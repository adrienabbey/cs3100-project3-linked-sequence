// Adrien Abbey, CS-3100-02, Feb. 8, 2023
// Node header file for Project 3

// Nodes are used by Sequences.

using namespace std;

class Node
{
public:
    Node *next;                                              // Tracks the next Node in a Sequence
    Node *previous;                                          // Tracks the previous Node in a Sequence
    int value;                                               // Contains the Node's integer value
    Node();                                                  // Empty Node constructor
    Node(Node *nextNode, Node *previousNode, int nodeValue); // Non-empty Node constructor
};