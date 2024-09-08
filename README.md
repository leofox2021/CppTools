# CppTools

Tools.h: A collection of useful methods for C++.

Time.h: Since we don't have an easy method to access system time in C++, I decided to create my own struct to retreive system time using WIN32's set of tools provided for C++/CLI.

---
# Important warning
Files that have "(CLI)" in their names are made for the Microsoft VS compiler and will not work with g++ or any other C++ compiler.

Files that don't have "(CLI)" in their names are made for the g++ compiler (C++ 23 standard). They will not work with Microsoft VS or any other C++ compiler.

---
# Usage
Just copy the files into your project and include them wherever you want:
```
#include "Tools.h"
#include "Time.h"
```
