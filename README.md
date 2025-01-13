<h1>CList lib</h1>

A simple c lib to create a list

<h2>How to build</h2>

<h3>Clone the repo and go to the folder</h3>

```bash
git clone https://github.com/Filipi565/CLists.git
cd CLists
```

<h3>Build using cmake</h3>

```bash
cmake . -B build -DCMAKE_BUILD_TYPE=Relase
cmake --build build
```

<h3>Install the library</h3>

```bash
sudo cmake --install build
```

<h3>Run ldconfig to avoid link errors</h3>

```bash
sudo ldconfig
```

<h2>Example</h2>

```C
#include <clist.h>
#include <stdio.h>

#define THROW_BADALLOC {fprintf(stderr, "BacAllocError\n");return -1;}

int main()
{
    CList list;
    if (CListInit(&list, sizeof(int)) == clist_error_bad_alloc)
        THROW_BADALLOC

    for (size_t i = 0; i < 10; i++)
    {
        int value = i * i;
        if (CListAppend(list, &value) == clist_error_bad_alloc)
            THROW_BADALLOC
    }

    size_t list_size = CListGetSize(list);

    for (size_t i = 0; i < list_size; i++)
    {
        int *value;
        CListAt(list, i, (void **)&value);
        printf("Address: %p, Value: %d\n", value, *value);
    }

    CListDeinit(list);

    return 0;
}
```