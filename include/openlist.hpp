#include <vector>

#ifndef OPENLIST_H
#define OPENLIST_H

template <typename T> class OpenList : public std::vector<T>
{
    public:
        bool is_empty();
        T pop();
        void insert(T node);
};

#endif