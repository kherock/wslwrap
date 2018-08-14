#include <cctype>
#include <cstdlib>
#include <experimental/filesystem>
#include <iostream>
#include <sstream>

namespace fs = std::experimental::filesystem;

int main(int argc, const char *argv[]) {
    fs::path executable = argv[0];
    std::ostringstream command;
    command << "wsl " << executable.stem().string();
    for (int i = 1; i < argc; i++) {
        command << ' ';
        fs::path p = argv[i];
        std::ostringstream arg;
        if (p.has_root_name()) {
            char &driveLetter = p.root_name().string().at(0);
            arg << "/mnt/" << (char)std::tolower(driveLetter) << '/';
        }
        bool hasSpace = false;
        for (char &c : p.relative_path().string()) {
            hasSpace |= c == ' ';
            if (c == '\\') {
                arg << '/';
            } else {
                arg << c;
            }
        }
        if (hasSpace) {
            command << '"' << arg.str() <<  '"';
        } else {
            command << arg.str();
        }
    }
    return std::system(command.str().c_str());
}
