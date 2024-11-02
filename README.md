# DXErr

One of the little utility libraries in the DirectX SDK is a static library for converting HRESULTs
to text strings for debugging and diagnostics known as `DXERR.LIB`. There were once even older versions of this library, `DXERR8.LIB` and `DXERR9.LIB`, but they were removed from the DirectX SDK many years back in favor of a unified `DXERR.LIB`.

However, this library was removed from Windows SDK 8.0 (see "[Where is DXERR.LIB?](http://blogs.msdn.com/b/chuckw/archive/2012/04/24/where-s-dxerr-lib.aspx)" [[Archive]](https://web.archive.org/web/20160224020327/http://blogs.msdn.com:80/b/chuckw/archive/2012/04/24/where-s-dxerr-lib.aspx)).

DXERR.LIB contained the following functions (both ASCII and UNICODE):

* `DXGetErrorString`
* `DXGetErrorDescription`
* `DXTrace`

And the macros `DXTRACE_MSG`, `DXTRACE_ERR`, `DXTRACE_ERR_MSGBOX`

Nitrocaster's implementation was taken from
Chuck Walbourn's MSDN blog and modified to comply with software that uses ANSI encoding.

ChiliTomatoNoodle took that implementation and introduced an updated version in [Chapter 14 of the HW3D C++ 3D DirectX Tutorial project](https://github.com/planetchili/hw3d/blob/T14-End/hw3d/dxerr.h).

This is a `DXERR.LIB` modern equivalent, providing support for ANSI and Unicode messages, saved from the Microsoft trash heap by Chuck Walbourn, extracted and made to work on ANSI and Unicode by nitrocaster, fixed by ChiliTomatoNoodle to resolve bugs and typos, and further modified to provide something which works on Windows 10/11 and x86/x64, for use with the inspired ChiliTomatoNoodle C++ 3D DirectX Tutorial project using modern C++ standards.

## Usage

Update the `C/C++ > General > Additional Include Directories` and `Linker > General > Additional Library Directories` project properties to include this library directory. Something like `$(ProjectDir)lib\DXErr` will work for all configurations if you follow a structure where the lib directory is a subdirectory under the Project Directory. It is dependent on _WIN64, _ARM64, _UNICODE, and _DEBUG macro definitions, so make sure those are set appropriately to match your target build configuration.

Then add the header to your source:

```C++
#include "DXErr.h"
```

This will link the library to the project and configure it to automatically link to the coordinate of ANSI/Unicode, x86/x64, debug/release based on your project build. PDBs are included.
