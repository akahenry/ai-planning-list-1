#include "openlist.hpp"

template <typename T> bool OpenList<T>::is_empty()
{
    return this->empty();
}

template <typename T> T OpenList<T>::pop()
{
    return this->pop();
}

template <typename T> void OpenList<T>::insert(T node)
{
    this->push_back(node);
}