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
 * This function allocates memory for a new CList and initializes its fields.
 *
 * @param outlist A pointer to the CList that will be initialized.
 * @param member_size The size of the data members that will be stored in the list.
 *
 * @return An integer representing the outcome of the operation.
 * - clist_no_error (0): The list was successfully initialized.
 * - clist_error_bad_alloc: Memory allocation failed. The list was not initialized.
 */
CLISTAPI int CListInit(CList *outlist, size_t member_size);

/**
 * @brief Deinitializes a CList
 *
 * This function frees the memory allocated for a CList and its associated data members.
 *
 * @param list The CList that will be deinitialized.
 *
 * @return This function does not return a value.
 *
 * @note After calling this function, the CList and its associated data members should not be used.
 *       The memory allocated for the CList and data members will be freed.
 */
CLISTAPI void CListDeinit(CList list);

/**
 * @brief Retrieves the value at the specified index in the list.
 *
 * This function retrieves the value at the specified index in the list and stores it in the memory location pointed to by `out_value`.
 *
 * @param list The list from which to retrieve the value.
 * @param index The index of the value to retrieve.
 * @param out_value A pointer to a pointer where the retrieved value will be stored.
 *
 * @return An integer representing the result of the operation.
 * - `clist_no_error`: The operation was successful.
 * - `clist_error_out_of_range`: The specified index is out of range.
 */
CLISTAPI int CListAt(CList list, size_t index, void **out_value);

/**
 * @brief Appends a new element to the end of the list.
 *
 * This function appends a new element to the end of the list. If the list's capacity is full,
 * it will automatically resize the list to accommodate the new element.
 *
 * @param list The list to which the new element will be appended.
 * @param value A pointer to the value that will be appended to the list.
 *
 * @return An integer representing the result of the operation.
 * - clist_no_error: The operation was successful.
 * - clist_error_bad_alloc: Memory allocation failed, and the list was deinitialized.
 */
CLISTAPI int CListAppend(CList list, const void *value);

#if defined(__cplusplus)
}
#endif

#endif