/*
 * Adrien Abbey, CS-3100-02, Feb. 8, 2023
 * Project 3: Linked Sequence Data Structure
 * Visual Studio Code Server, Ubuntu 22.04, g++/gdb
 */

#include "sequence.h"

/* Constructors and Destructors */

Sequence::Sequence(size_type sz)
{
    // Create a Sequence of the specified length.
    // NOTE: I do NOT need to validate the size, as it's an unsigned int.

    // Set the initial size of the sequence to zero:
    numElts = 0;

    // Set the head and tail to null:
    head = nullptr;
    tail = nullptr;

    // Add the appropriate number of blank SequenceNodes:
    for (int i = 0; i < sz; i++)
    {
        // To reduce code repetition, I'm going to use push_back to add each node:
        push_back(0);
    }
}

Sequence::Sequence(const Sequence &s)
{
    // Create a deep copy of the given Sequence.

    // Initialize this sequence:
    head = nullptr;
    tail = nullptr;
    numElts = 0;

    // Start copying elements from the other Sequence:
    SequenceNode *toCopy = s.head;
    while (toCopy != nullptr)
    {
        // Copy the SequenceNode from the other Sequence:
        push_back(toCopy->elt);

        // Next up:
        toCopy = toCopy->next;
    }
}

Sequence::~Sequence()
{
    // Destroy all objects belonging to this Sequence.

    // Just call the clear function:
    clear();
}

/* Operators */

Sequence &Sequence::operator=(const Sequence &s)
{
    // Destroy objects belonging to this Sequence and replace them with a deep copy of the given Sequence.
    return *this;
}

Sequence::value_type &Sequence::operator[](size_type position)
{
    // Return a reference to the value of the given index position.
    // NOTE: Throw an exception if the index value is invalid.

    // Check to see if the index value is valid:
    // NOTE: unsigned int means less than 0 should be impossible.
    if (position > numElts - 1)
    {
        // Invalid index, throw an exception:
        throw exception();
    }
    else
    {
        // Valid index.  Return the integer at the given index.

        // Start with the head node:
        SequenceNode *currentNode = head;

        // Start crawling through the SequenceNodes until we reach the expected index value:
        // NOTE: if position = 0, it's already set, and this will do nothing!
        for (int i = 0; i < position; i++)
        {
            // Move currentNode to the next SequenceNode:
            currentNode = currentNode->next;
        }

        // Return the value of the currentNode:
        return currentNode->elt;
    }
}

/* Methods */

void Sequence::push_back(const value_type &value)
{
    // Append the given value to the end of the Sequence, extending its size.
    // FIXME: ...Why is this a const...?

    // If the Sequence is empty:
    if (numElts == 0)
    {
        // Then create a new SequenceNode with the given value:
        SequenceNode *newNode = new SequenceNode(value);

        // Set the head and tail to the new SequenceNode:
        head = newNode;
        tail = newNode;

        // Increase the size of the Sequence:
        numElts++;
    }
    // If the Sequence is NOT empty:
    else
    {
        // Create a new SequenceNode:
        SequenceNode *newNode = new SequenceNode(value);

        // Set the new node's previous and next:
        newNode->prev = tail;
        newNode->next = nullptr;

        // Point the old tail to the new tail:
        tail->next = newNode;

        // Finally, set the new tail and increment the Sequence's size:
        tail = newNode;
        numElts++;
    }
}

void Sequence::pop_back()
{
    // Delete the item at the end of the Sequence, reducing its size.
    // NOTE: Throw an exception if there are no items in the Sequence.
    throw exception();
}

void Sequence::insert(size_type position, value_type value)
{
    // Insert the given value at the given position in the Sequence, extending its size.
    throw exception();
}

const Sequence::value_type &Sequence::front() const
{
    // Returns a reference to the first item in the Sequence.
    // NOTE: Throws an exception if there are no items in the Sequence.
    throw exception();
}

const Sequence::value_type &Sequence::back() const
{
    // Returns a reference to the last item in the Sequence.
    // NOTE: Throws an exception if there are no items in the Sequence.
    throw exception();
}

bool Sequence::empty() const
{
    // Return 'true' if this Sequence is empty, 'false' if not.
    return false;
}

Sequence::size_type Sequence::size() const
{
    // Return the size of this Sequence.
    return -1;
}

void Sequence::clear()
{
    // Delete all items in this sequence (freeing memory).
    // FIXME: Why does this have an exception throw?
    // throw exception();

    // Destroy all objects belonging to this Sequence.

    // Walk through the SequenceNodes, deleting each one:
    SequenceNode *deleteMe = head;
    while (deleteMe != nullptr)
    {
        // Remember who to kill next:
        SequenceNode *deleteMeNext = deleteMe->next;

        // Delete:
        delete deleteMe;

        // Next on the block:
        deleteMe = deleteMeNext;
    }

    // Finally, reset this Sequence to a clean state:
    head = nullptr;
    tail = nullptr;
    numElts = 0;
}

void Sequence::erase(size_type position, size_type count)
{
    // Deletes the given number of items starting at the index value listed, reducing the Sequence size.
    throw exception();
}

ostream &operator<<(ostream &os, const Sequence &s)
{
    // Returns an ostream output string of the given Sequence.
    return os;
}