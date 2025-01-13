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

/**
 * @brief Initializes a CList
 *
 * This function allocates memory for a new CList structure and initializes its fields.
 *
 * @param outlist A pointer to a pointer to the CList structure that will be initialized.
 * @param member_size The size of the data members that will be stored in the list.
 *
 * @return An integer representing the outcome of the operation.
 * - clist_no_error: The list structure was successfully initialized.
 * - clist_error_bad_alloc: Memory allocation failed. The list structure was not initialized.
 */
CLISTAPI int CListInit(CList *outlist, size_t member_size);
CLISTAPI void CListDeinit(CList list);

#if defined(__cplusplus)
}
#endif

#endif