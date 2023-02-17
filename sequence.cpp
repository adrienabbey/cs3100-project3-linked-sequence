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
    // Destroy objects belonging to this Sequence and replace
    // them with a deep copy of the other Sequence.

    // FIXME: This does NOT make DEEP copies!!!

    // Clear the current sequence:
    clear();

    // Deep copy the given sequence to this one:
    // Start copying elements from the other Sequence:
    SequenceNode *toCopy = s.head;
    while (toCopy != nullptr)
    {
        // Copy the SequenceNode from the other Sequence:
        push_back(toCopy->elt);

        // Next up:
        toCopy = toCopy->next;
    }

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

    // Check to see if there's a valid SequenceNode to remove:
    if (numElts == 0)
    {
        // Nothing to pop_back, so throw an exception:
        throw exception();
    }
    else
    {
        // Remove the last node, and adjust the tail pointer and number of elements.

        // Remember which SequenceNode to delete:
        SequenceNode *deleteMe = tail;

        // Set the new tail's pointer to null, but only if there's a new tail:
        if (tail->prev != nullptr)
        {
            tail->prev->next = nullptr;
        }

        // Set the Sequence tail appropriately:
        tail = tail->prev;

        // Delete the SequenceNode:
        delete deleteMe;

        // Decrement the number of elements in this Sequence:
        numElts--;

        // If there's no more elements, set head to nullptr:
        if (numElts == 0)
        {
            head = nullptr;
        }
    }
}

void Sequence::insert(size_type position, value_type value)
{
    // Insert the given value at the given position in the Sequence, extending its size.
    // Make sure the index position is valid:
    if (position > numElts - 1)
    {
        // Invalid index, throw a tantrum:
        throw exception();
    }
    else
    {
        // Find the target node, starting with head:
        SequenceNode *targetNode = head;
        for (int i = 0; i < position; i++)
        {
            targetNode = targetNode->next;
        }

        // Create a new SequenceNode to insert:
        SequenceNode *newNode = new SequenceNode(value);

        // Set the newNode's prev/next:
        newNode->next = targetNode;
        newNode->prev = targetNode->prev;

        // Set next/prev of the nodes around newNode:
        // But only if there's a previous node:
        if (targetNode->prev != nullptr)
        {
            targetNode->prev->next = newNode;
        }
        targetNode->prev = newNode;

        // If the newNode is replacing the head or tail:
        if (position == 0)
        {
            head = newNode;
        }
        if (position == numElts - 1)
        {
            tail = newNode;
        }

        // Finally, increment the element count:
        numElts++;
    }
}

const Sequence::value_type &Sequence::front() const
{
    // Returns a reference to the first item in the Sequence.
    // NOTE: Throws an exception if there are no items in the Sequence.

    // Check to see if there's anything to return:
    if (head == nullptr)
    {
        // Nothing valid to return, so throw an exception:
        throw exception();
    }
    else
    {
        // Return the value of the head node:
        return head->elt;
    }
}

const Sequence::value_type &Sequence::back() const
{
    // Returns a reference to the last item in the Sequence.
    // NOTE: Throws an exception if there are no items in the Sequence.

    // Check if there's anything to return:
    if (tail == nullptr)
    {
        // Nothing valid to return, so throw an exception:
        throw exception();
    }
    else
    {
        // Return the value of the tail node:
        return tail->elt;
    }
}

bool Sequence::empty() const
{
    // Return 'true' if this Sequence is empty, 'false' if not.

    // If there's elements in this Sequence:
    if (numElts != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

Sequence::size_type Sequence::size() const
{
    // Return the size of this Sequence.
    return numElts;
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
    // Deletes the given number of items starting at the index value listed,
    // reducing the Sequence size and freeing memory.
    // Assuming position is an array index (starts at zero).

    // Throw an exception if the position or count is invalid:
    // NOTE: Size_type is an unsigned integer, so I only really need one test.
    // If these were a signed ints, I'd need to make sure position and count are > 0.
    if (position + count > numElts)
    {
        throw exception();
    }
    else
    {
        // Otherwise, find the first and last SequenceNode NOT being deleted.
        SequenceNode *firstKeep = nullptr;
        SequenceNode *lastKeep = nullptr;

        // Find the first node to keep:
        // NOTE: This CAN be nullptr!
        for (int i = 0; i <= position; i++)
        {
            // We need to start with head node, if we don't have a node already selected:
            if (firstKeep == nullptr)
            {
                firstKeep = head;
            }
            else
            {
                // Select the next node:
                firstKeep = firstKeep->next;
            }
        }

        // Find the last node to keep:
        int lastKeepIndex = position + count - 1;
        // Check if there is a lastNode to keep:
        if (lastKeepIndex == numElts - 1)
        {
            // Then there's no node to keep.
        }
        else
        {
            // Otherwise find the last node to keep:
            for (int i = numElts; i > lastKeepIndex; i--)
            {
                // For efficiency's sake, start with the tail:
                if (lastKeep == nullptr)
                {
                    lastKeep = tail;
                }
                else
                {
                    // Go to the previous node:
                    lastKeep = lastKeep->prev;
                }
            }
        }

        // Now that we have which nodes to keep, start deleting nodes between:
        SequenceNode *currentNode = firstKeep; // Track which nodes to work with.
        for (int i = 0; i < count; i++)
        {
            // Track the previous and next nodes:
            SequenceNode *prevNode = currentNode->prev;
            SequenceNode *nextNode = currentNode->next;

            // Glue those two nodes together, but handling for nullptr:
            if (prevNode != nullptr)
            {
                prevNode->next = nextNode;
            }
            else
            {
                // We havce a new head:
                head = nextNode;
            }
            if (nextNode != nullptr)
            {
                nextNode->prev = prevNode;
            }
            else
            {
                // We have a new tail:
                tail = prevNode;
            }

            // Delete the current node:
            delete currentNode;

            // Don't forget to reduce element count:
            numElts--;

            // Finally, track the next node:
            currentNode = nextNode;
        }
    }
}

ostream &operator<<(ostream &os, const Sequence &s)
{
    // Returns an ostream output string of the given Sequence.

    // Start with the head node:
    Sequence::SequenceNode *current = s.head; // This works!  Needs Sequence:: at front!
    // Note that this is not const!

    // Start with "<":
    os << "<";

    // Start iterating through the list:
    while (current != nullptr)
    {
        // Start adding elements to the ostream:
        os << current->elt;
        // Add a comma so long as there's a next element:
        if (current->next != nullptr)
        {
            os << ", ";
        }
        current = current->next;
    }

    // End with ">":
    os << ">";

    return os;
}