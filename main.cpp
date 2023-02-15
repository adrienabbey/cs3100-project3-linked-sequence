/*
 * Adrien Abbey, CS-3100-02, Feb. 8, 2023
 * Project 3: Linked Sequence Data Structure
 * Visual Studio Code Server, Ubuntu 22.04, g++/gdb
 */

#include <iostream>
#include "sequence.h"

using namespace std;

int main()
{
    // Test the new Sequence constructor:
    Sequence *newSequence = new Sequence(0);

    // Fill the new sequence with values:
    for (int i = 0; i < 5; i++)
    {
        newSequence->push_back(i + 1);
    }

    // Test the ostream operator<<:
    cout << *newSequence << endl;

    // Test getting the value of a specified index value:
    // NOTE: I struggled a bit to figure out dereferencing.
    // This was a valuable learning experience.
    int value = (*newSequence)[4];

    // Test the Sequence deep copy constructor:
    Sequence *copiedSequence = new Sequence(*newSequence);

    // Test the back and front methods:
    int front = (*copiedSequence).front();
    int back = (*copiedSequence).back();

    // Test the pop_back method:
    copiedSequence->pop_back();

    // Test the Sequence deconstructor:
    delete newSequence;
    // FIXME: I need to set this POINTER to nullptr!!!
    // Delete will delete the sequence, but NOT remove the pointer!

    // Test the empty method:
    bool newIsEmpty = newSequence->empty();
    bool copiedIsEmpty = copiedSequence->empty();

    // Test the size method:
    int newSize = newSequence->size();
    int copiedSize = copiedSequence->size();

    // Test the =operator overload:
    Sequence equalSequence;
    equalSequence = *copiedSequence;
    // pointer = pointer will just change the pointer!
    // equalSequence is NOT a pointer
    // I need to dereference the target of this to work!

    return 0;
}