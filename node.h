// Adrien Abbey, CS-3100-02, Feb. 8, 2023
// Node header file for Project 3

// Nodes are used by Sequences.

using namespace std;

class Node
{
public:
    Node *next;     // Tracks the next Node
    Node *previous; // Tracks the previous Node
    /* Also need something to contain data, but I'm not sure which.  typedef? */
    Node();         // Empty Node constructor
    /* I know I need another constructor, but this depends on the above uncertainty. */
};