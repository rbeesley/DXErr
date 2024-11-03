//--------------------------------------------------------------------------------------
// File: DXErr.h
//
// DirectX Error Library
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#define _WIN32_WINNT 0x0A00
#include <sdkddkver.h>

// Windows.h macro defines
#define WIN32_LEAN_AND_MEAN

// Minimum required Windows.h defines for DXErr
//#define NOGDI // - All GDI defines and routines
//#define NOUSER // - All USER defines and routines
//#define NOMB // - MB_ * and MessageBox()
//#define NOMSG // - typedef MSG and associated routines

// Not required for DXErr
#define NOGDICAPMASKS // - CC_*, LC_*, PC_*, CP_*, TC_*, RC_
#define NOVIRTUALKEYCODES // - VK_ *
#define NOWINMESSAGES // - WM_*, EM_*, LB_*, CB_*
#define NOWINSTYLES // -  WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
#define NOSYSMETRICS // - SM_ *
#define NOMENUS // - MF_ *
#define NOICONS // - IDI_ *
#define NOKEYSTATES // - MK_ *
#define NOSYSCOMMANDS // - SC_ *
#define NORASTEROPS // - Binary and Tertiary raster ops
#define NOSHOWWINDOW // - SW_ *
#define OEMRESOURCE // - OEM Resource values
#define NOATOM // - Atom Manager routines
#define NOCLIPBOARD // - Clipboard routines
#define NOCOLOR // - Screen colors
#define NOCTLMGR // - Control and Dialog routines
#define NODRAWTEXT // - DrawText() and DT_ *
//#define NOGDI // - All GDI defines and routines
#define NOKERNEL // - All KERNEL defines and routines
//#define NOUSER // - All USER defines and routines
#define NONLS // - All NLS defines and routines
//#define NOMB // - MB_ * and MessageBox()
#define NOMEMMGR // - GMEM_*, LMEM_*, GHND, LHND, associated routines
#define NOMETAFILE // - typedef METAFILEPICT
#define NOMINMAX // - Macros min(a, b) and max(a, b)
//#define NOMSG // - typedef MSG and associated routines
#define NOOPENFILE // - OpenFile(), OemToAnsi, AnsiToOem, and OF_*
#define NOSCROLL // - SB_ * and scrolling routines
#define NOSERVICE // - All Service Controller routines, SERVICE_ equates, etc.
#define NOSOUND // - Sound driver routines
#define NOTEXTMETRIC // - typedef TEXTMETRIC and associated routines
#define NOWH // - SetWindowsHook and WH_ *
#define NOWINOFFSETS // - GWL_*, GCL_*, associated routines
#define NOCOMM // - COMM driver routines
#define NOKANJI // - Kanji support stuff.
#define NOHELP // - Help engine interface.
#define NOPROFILER // - Profiler interface.
#define NODEFERWINDOWPOS // - DeferWindowPos routines
#define NOMCX // - Modem Configuration Extensions
#define NORPC
#define NOPROXYSTUB
#define NOIMAGE
#define NOTAPE

#ifndef STRICT
#define STRICT
#endif

#include <Windows.h>
#include <sal.h>

#if defined(_M_ARM64EC)
#if defined(_UNICODE)
#if defined(_DEBUG)	// ARM64EC/UNICODE/DEBUG
#pragma comment(lib, "DXErr_ARM64EC_ud.lib")
#else				// ARM64EC/UNICODE/RELEASE
#pragma comment(lib, "DXErr_ARM64EC_ur.lib")
#endif
#else
#if defined(_DEBUG)	// ARM64EC/ANSI/DEBUG
#pragma comment(lib, "DXErr_ARM64EC_ad.lib")
#else				// ARM64EC/ANSI/RELEASE
#pragma comment(lib, "DXErr_ARM64EC_ar.lib")
#endif
#endif
#elif defined(_M_ARM64)
#if defined(_UNICODE)
#if defined(_DEBUG)	// ARM64/UNICODE/DEBUG
#pragma comment(lib, "DXErr_ARM64_ud.lib")
#else				// ARM64/UNICODE/RELEASE
#pragma comment(lib, "DXErr_ARM64_ur.lib")
#endif
#else
#if defined(_DEBUG)	// ARM64/ANSI/DEBUG
#pragma comment(lib, "DXErr_ARM64_ad.lib")
#else				// ARM64/ANSI/RELEASE
#pragma comment(lib, "DXErr_ARM64_ar.lib")
#endif
#endif
#elif defined(_M_ARM)
#if defined(_UNICODE)
#if defined(_DEBUG)	// ARM/UNICODE/DEBUG
#pragma comment(lib, "DXErr_ARM_ud.lib")
#else				// ARM/UNICODE/RELEASE
#pragma comment(lib, "DXErr_ARM_ur.lib")
#endif
#else
#if defined(_DEBUG)	// ARM/ANSI/DEBUG
#pragma comment(lib, "DXErr_ARM_ad.lib")
#else				// ARM/ANSI/RELEASE
#pragma comment(lib, "DXErr_ARM_ar.lib")
#endif
#endif
#elif defined(_M_X64) && !defined(_M_ARM64EC)
#if defined(_UNICODE)
#if defined(_DEBUG)	// x64/UNICODE/DEBUG
#pragma comment(lib, "DXErr_x64_ud.lib")
#else				// x64/UNICODE/RELEASE
#pragma comment(lib, "DXErr_x64_ur.lib")
#endif
#else
#if defined(_DEBUG)	// x64/ANSI/DEBUG
#pragma comment(lib, "DXErr_x64_ad.lib")
#else				// x64/ANSI/RELEASE
#pragma comment(lib, "DXErr_x64_ar.lib")
#endif
#endif
#elif defined(_WIN32) && !(defined(_M_ARM) || defined(_M_ARM64) || defined(_WIN64))
#if defined(_UNICODE)
#if defined(_DEBUG)	// x86/UNICODE/DEBUG
#pragma comment(lib, "DXErr_x86_ud.lib")
#else				// x86/UNICODE/RELEASE
#pragma comment(lib, "DXErr_x86_ur.lib")
#endif
#else
#if defined(_DEBUG)	// x86/ANSI/DEBUG
#pragma comment(lib, "DXErr_x86_ad.lib")
#else				// x86/ANSI/RELEASE
#pragma comment(lib, "DXErr_x86_ar.lib")
#endif
#endif
#endif

#ifdef __cplusplus
extern "C" {
	#endif

	//--------------------------------------------------------------------------------------
	// DXGetErrorString
	//--------------------------------------------------------------------------------------
	const WCHAR* WINAPI DXGetErrorStringW(_In_ HRESULT hr);
	const CHAR* WINAPI DXGetErrorStringA(_In_ HRESULT hr);
	#ifdef UNICODE
	#define DXGetErrorString DXGetErrorStringW
	#else
	#define DXGetErrorString DXGetErrorStringA
	#endif

	//--------------------------------------------------------------------------------------
	// DXGetErrorDescription has to be modified to return a copy in a buffer rather than
	// the original static string.
	//--------------------------------------------------------------------------------------
	void WINAPI DXGetErrorDescriptionW(_In_ HRESULT hr, _Out_cap_(count) WCHAR* desc, _In_ size_t count);
	void WINAPI DXGetErrorDescriptionA(_In_ HRESULT hr, _Out_cap_(count) CHAR* desc, _In_ size_t count);
	#ifdef UNICODE
	#define DXGetErrorDescription DXGetErrorDescriptionW
	#else
	#define DXGetErrorDescription DXGetErrorDescriptionA
	#endif

	//--------------------------------------------------------------------------------------
	//  DXTrace
	//
	//  Desc:  Outputs a formatted error message to the debug stream
	//
	//  Args:  WCHAR* strFile   The current file, typically passed in using the 
	//                         __FILEW__ macro.
	//         DWORD dwLine    The current line number, typically passed in using the 
	//                         __LINE__ macro.
	//         HRESULT hr      An HRESULT that will be traced to the debug stream.
	//         CHAR* strMsg    A string that will be traced to the debug stream (may be NULL)
	//         BOOL bPopMsgBox If TRUE, then a message box will popup also containing the passed info.
	//
	//  Return: The hr that was passed in.  
	//--------------------------------------------------------------------------------------

	HRESULT WINAPI DXTraceW(_In_z_ const WCHAR* strFile, _In_ DWORD dwLine, _In_ HRESULT hr, _In_opt_ const WCHAR* strMsg, _In_ bool bPopMsgBox);
	//--------------------------------------------------------------------------------------
	//  DXTrace
	//
	//  Desc:  Outputs a formatted error message to the debug stream
	//
	//  Args:  CHAR* strFile   The current file, typically passed in using the 
	//                         __FILE__ macro.
	//         DWORD dwLine    The current line number, typically passed in using the 
	//                         __LINE__ macro.
	//         HRESULT hr      An HRESULT that will be traced to the debug stream.
	//         CHAR* strMsg    A string that will be traced to the debug stream (may be NULL)
	//         BOOL bPopMsgBox If TRUE, then a message box will popup also containing the passed info.
	//
	//  Return: The hr that was passed in.  
	//--------------------------------------------------------------------------------------
	HRESULT WINAPI DXTraceA(_In_z_ const CHAR* strFile, _In_ DWORD dwLine, _In_ HRESULT hr, _In_opt_ const CHAR* strMsg, _In_ bool bPopMsgBox);
	#ifdef UNICODE
	#define DXTrace DXTraceW
	#else
	#define DXTrace DXTraceA
	#endif

	//--------------------------------------------------------------------------------------
	//
	// Helper macros
	//
	//--------------------------------------------------------------------------------------
	#if defined(_DEBUG)
	#ifdef UNICODE
	#define DXTRACE_MSG(str)              DXTrace( __FILEW__, (DWORD)__LINE__, 0, str, false )
	#define DXTRACE_ERR(str,hr)           DXTrace( __FILEW__, (DWORD)__LINE__, hr, str, false )
	#define DXTRACE_ERR_MSGBOX(str,hr)    DXTrace( __FILEW__, (DWORD)__LINE__, hr, str, true )
	#else
	#define DXTRACE_MSG(str)              DXTrace( __FILE__, (DWORD)__LINE__, 0, str, false )
	#define DXTRACE_ERR(str,hr)           DXTrace( __FILE__, (DWORD)__LINE__, hr, str, false )
	#define DXTRACE_ERR_MSGBOX(str,hr)    DXTrace( __FILE__, (DWORD)__LINE__, hr, str, true )
	#endif
	#else
	#define DXTRACE_MSG(str)              (0L)
	#define DXTRACE_ERR(str,hr)           (hr)
	#define DXTRACE_ERR_MSGBOX(str,hr)    (hr)
	#endif

	#ifdef __cplusplus
}
#endif //__cplusplus