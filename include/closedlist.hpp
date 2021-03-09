#include <map>
#include <algorithm>

#ifndef CLOSEDLIST_H
#define CLOSEDLIST_H

template <typename State_Type, typename Node_Type> class ClosedList : public std::map<State_Type, Node_Type>
{
    public:
        bool lookup(State_Type state);
        void insert(Node_Type node);
};

#endif