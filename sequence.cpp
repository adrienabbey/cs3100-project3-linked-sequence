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
    // These will likely have Node objects.
}

Sequence::Sequence(const Sequence &s)
{
    // Create a deep copy of the given Sequence.
}

Sequence::~Sequence()
{
    // Destroy all objects belonging to this Sequence.
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
    throw exception();
}

/* Methods */

void Sequence::push_back(const value_type &value)
{
    // Append the given value to the end of the Sequence, extending its size.
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
    throw exception();
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