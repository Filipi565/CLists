#ifndef CLIST_H
#define CLIST_H

#include <stddef.h>

#if defined(_WIN32)
    #if defined(__TINYC__) && !defined(__declspec)
        #define __declspec(x) __attribute__((x))
    #endif
    #if defined(BUILD_LIBTYPE_SHARED)
        #define CLISTAPI __declspec(dllexport)     // We are building the library as a Win32 shared library (.dll)
    #elif defined(CLIST_DLL)
        #define CLISTAPI __declspec(dllimport)     // We are using the library as a Win32 shared library (.dll)
    #endif
#else
    #if defined(BUILD_LIBTYPE_SHARED)
        #define CLISTAPI __attribute__((visibility("default"))) // We are building as a Unix shared library (.so/.dylib)
    #endif
#endif

#ifndef CLISTAPI
    #define CLISTAPI
#endif

#if defined(__cplusplus)
extern "C" {
#endif

typedef enum CListError CListError;
typedef void *CList;

enum CListError
{
    clist_no_error = 0,
    clist_error_bad_alloc,
    clist_error_out_of_range
};

CLISTAPI int CListInit(CList *list, size_t member_size);

#if defined(__cplusplus)
}
#endif

#endif