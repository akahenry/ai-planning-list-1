#include <iostream>
#include <cstddef>
#include <vector>
#include <algorithm>

#include "actions.hpp"
#include "state.hpp"
#include "problem.hpp"

#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        int id;
        State* state;
        Node* parent;
        Actions action;
        int path_cost;

        int getId();

        static void init();
        static Node* make_root_node(State* state);
        static Node* make_node(Node* parent, Actions action, State* state);
        static std::vector<Actions> extract_path(Node node);
        static int count();

        Node& operator=(const Node &node);
        bool operator==(const Node &node) const;
        
    private:
        static int nextId;

        Node();
};

// namespace std
// {
//   template<>
//     struct hash<Node>
//     {
//       size_t
//       operator()(const Node & obj) const
//       {
//         return hash<int>()(obj.id);
//       }
//     };
// }

#endif