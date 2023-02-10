// Adrien Abbey, CS-3100-02, Feb. 8, 2023
// Node cpp file for Project 3

#include "node.h"

/* Constructors */
Node::Node() : next(nullptr), previous(nullptr), value(0) {}
Node::Node(Node *newNextNode, Node *newPreviousNode, int newValue) : next(newNextNode), previous(newPreviousNode), value(newValue) {}