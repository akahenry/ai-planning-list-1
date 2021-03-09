#include "node.hpp"

int Node::nextId;

Node::Node()
{
    this->id = -1;
    this->state = nullptr;
    this->parent = nullptr;
    this->action = Actions::UP;
    this->path_cost = -1;
}

void Node::init()
{
    nextId = 0;
}

Node* Node::make_root_node(State* state)
{
    Node* node = new Node;
    node->id = nextId;
    node->state = state;
    node->parent = NULL;
    node->action = Actions::UP;
    node->path_cost = 0;

    nextId++;

    return node;
}

Node* Node::make_node(Node* parent, Actions action, State* state)
{
    if(parent->state == state)
    {
        return parent;
    }
    else
    {
        Node* node = new Node;
        node->id = nextId;
        node->state = state;
        node->parent = parent;
        node->action = action;
        node->path_cost = parent->path_cost + Problem::cost(*state, action);

        nextId++;

        return node;
    }
}

std::vector<Actions> Node::extract_path(Node node)
{
    std::vector<Actions> path;

    while(node.parent != nullptr)
    {
        //std::cout << "Pai id: " << node.parent->id << std::endl;
        path.push_back(node.action);
        node = *(node.parent);
    }

    std::reverse(path.begin(), path.end());

    return path;
}

int Node::count()
{
    return Node::nextId;
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