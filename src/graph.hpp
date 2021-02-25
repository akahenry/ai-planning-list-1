#include <cstddef>
#include <vector>
#include <algorithm>
#include <map>

template <class State_Type, class Action_Type, typename T = int> class Node
{
    public:
        State_Type* state;
        Node* parent;
        Action_Type* action;
        T path_cost;

        Node<State_Type, Action_Type, T> make_root_node();
        Node<State_Type, Action_Type, T> make_node(Node<State_Type, Action_Type, T> parent, Action_Type action, State_Type state);
        std::vector<Action_Type> extract_path(Node<State_Type, Action_Type, T> node);
};

template <typename T> class OpenList : public std::vector<T>
{
    public:
        bool is_empty();
        T pop();
        void insert(T node);
};

template <typename State_Type, typename Node_Type> class ClosedList : public std::map<State_Type, Node_Type>
{
    public:
        bool lookup(State_Type state);
        void insert(Node_Type node);
};