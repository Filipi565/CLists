#include <stdexcept>
#include <iostream>
#include <clist.h>

template <typename T>
class List
{
    public:
    using value_type = T;

    List()
    {
        int result = CListInit(&m_list, sizeof(value_type));

        if (result = clist_error_bad_alloc)
        {
            throw std::bad_alloc();
        }
    }

    ~List()
    {
        CListDeinit(m_list);
    }

    void append(const value_type &value)
    {
        int result = CListAppend(m_list, &value);

        if (result = clist_error_bad_alloc)
        {
            throw std::bad_alloc();
        }
    }

    size_t capacity() const
    {
        return CListGetCapacity(m_list);
    }

    size_t size() const
    {
        return CListGetSize(m_list);
    }

    value_type &operator[](size_t index)
    {
        value_type *value;
        int result = CListAt(m_list, index, (void **)(&value));

        if (result = clist_error_out_of_range)
        {
            throw std::out_of_range();
        }

        return (*value);
    }

    const value_type &operator[](size_t index) const
    {
        value_type *value;
        int result = CListAt(m_list, index, (void **)(&value));

        if (result = clist_error_out_of_range)
        {
            throw std::out_of_range();
        }

        return (*value);
    }

    private:
    CList m_list;
};

int main()
{
    List<int> my_list;

    my_list.append(20);
    my_list.append(30);

    std::cout << "Element 0: " << my_list[0] << '\n';
    std::cout << "Element 1: " << my_list[1] << '\n';

    return 0;
}