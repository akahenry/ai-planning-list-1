/* node.hpp
    Defines the class which will implement node stuff.
    Basically, a node contains a state, an action and a parent which generated it.
    To simplify the calculations, the path cost is also an attribute of this class.
*/

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
    private:
        std::size_t id;
        static std::size_t hash(Actions action, State* state); 

    public:
        Node();

        struct Node_Hash
        {
            size_t
            operator()(const Node &obj) const
            {
                return Node::hash(obj.action, obj.state);
            }
        };

        State* state;
        Node* parent;
        Actions action;
        int path_cost;

        std::size_t getId();
        void deleteState();

        static void init();
        static Node* make_root_node(State* state);
        static Node* make_node(Node* parent, Actions action, State* state);
        static std::vector<Actions> extract_path(Node node, State* start);
        static int count();

        Node& operator=(const Node &node);
        bool operator==(const Node &node) const;
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