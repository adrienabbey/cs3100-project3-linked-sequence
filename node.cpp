// Adrien Abbey, CS-3100-02, Feb. 8, 2023
// Node cpp file for Project 3

#include "node.h"

/* Constructors */
Node::Node() : next(nullptr), previous(nullptr), value(0) {}
Node::Node(Node *nextNode, Node *previousNode, int newValue)
{
    next = nextNode;
    previous = previousNode;
    value = newValue;
}