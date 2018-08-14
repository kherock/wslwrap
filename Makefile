SRCDIR := src
BUILDDIR := build
TARGET := wslwrap

SOURCES := $(shell find $(SRCDIR) -name *.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.cpp=.o))
CXX := x86_64-w64-mingw32-g++
CXXFLAGS := -O2 -Wall -Iinclude -std=c++11
LIB := -static-libgcc -static-libstdc++ -lstdc++fs

$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $(TARGET).exe $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<

clean:
	$(RM) -r $(BUILDDIR) $(TARGET).exe
