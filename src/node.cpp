#include "node.hpp"

int Node::hash(Actions action, State state)
{
    return state.getId();
}

Node::Node()
{
    this->id = -1;
    this->state = State();
    this->parent = nullptr;
    this->action = Actions::UP;
    this->path_cost = -1;
}

Node Node::make_root_node(State state)
{
    Node node;
    node.state = state;
    node.parent = NULL;
    node.action = Actions::UP;
    node.path_cost = 0;
    node.id = hash(node.action, state);

    return node;
}

Node Node::make_node(Node* parent, Actions action, State state)
{
    Node node;
    node.id = hash(action, state);
    node.state = state;
    node.parent = parent;
    node.action = action;
    node.path_cost = parent->path_cost + Problem::cost(state, action);

    return node;
}

std::vector<Actions> Node::extract_path(Node node, State start)
{
    std::vector<Actions> path;

    while(node.state != start && node.parent != nullptr)
    {
        path.push_back(node.action);
        node = *(node.parent);
    }

    std::reverse(path.begin(), path.end());

    return path;
}

int Node::getId()
{
    return this->id;
}

Node&  Node::operator=(const Node &other)
{
    this->id = other.id;
    this->action = other.action;
    this->parent = other.parent;
    this->path_cost = other.path_cost;
    this->state = other.state;

    return *this;
}

bool Node::operator==(const Node &node) const
{
    return this->id == node.id;
}