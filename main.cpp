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
    // Test the new sized Sequence constructor:
    Sequence *newSequence = new Sequence(5);

    // Test getting the value of a specified index value:
    // FIXME: Why is this not working???
    // int value = newSequence[4];

    // Test the Sequence deconstructor:
    delete newSequence;
    // FIXME: newSequence still shows up in the debugger.  Why?

    return 0;
}