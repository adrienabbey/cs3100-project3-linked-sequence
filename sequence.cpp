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
    // 
    throw exception();
}

void Sequence::push_back(const value_type &value)
{
}

void Sequence::pop_back()
{
    throw exception();
}

void Sequence::insert(size_type position, value_type value)
{
    throw exception();
}

const Sequence::value_type &Sequence::front() const
{
    throw exception();
}

const Sequence::value_type &Sequence::back() const
{
    throw exception();
}

bool Sequence::empty() const
{
    return false;
}

Sequence::size_type Sequence::size() const
{
    return -1;
}

void Sequence::clear()
{
    throw exception();
}

void Sequence::erase(size_type position, size_type count)
{
    throw exception();
}

ostream &operator<<(ostream &os, const Sequence &s)
{
    return os;
}