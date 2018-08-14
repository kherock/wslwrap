# WSLWrap

A multi-call program that lets you use Linux commands from your Windows
Subsystem for Linux environment directly in a PowerShell or Command Prompt.
Supports translating directory separators and absolute paths to be
WSL-friendly.

Example:  
```
C:\wslwrap>mklink ls.exe wslwrap.exe
C:\wslwrap>ls.exe C:\wslwrap
build  LICENSE  ls.exe  Makefile  README.md  src  wslwrap.exe
```
