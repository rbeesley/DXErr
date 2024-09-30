# DXErr
`DXErr.lib` equivalent, providing support for ANSI and Unicode messages, sourced from nitrocaster, fixed by ChiliTomatoNoodle to resolve bugs and typos, and further modified by me to provide something which works on Windows 10/11 and x86/x64, for use with the inspired ChiliTomatoNoodle C++ 3D DirectX Tutorial project with modern C++20 standards.

## Usage
To use and assuming you have added the DXErr library to the subdirectory `libs/DXErr`, add the header to your source:

```C++
#include "libs/DXErr/DXErr.h"
```

This will link the library to the project and configure it for the coordinate of ANSI/Unicode, x86/x64, debug/release. The PDBs are include for the debug builds, but they aren't necessary to use the library.