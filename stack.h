/*******************************************************************************
 * Name: Manuel Bonilla
 * Assignment: Assignment 4 - Simple Classes & Objects
 * File: stack.h
 * Date completed: 6/20/2026
 * Description: This file defines the blueprint for the stack class (ADT) while
 * setting up the static array and tracking the top index as private attributes.
 * It then defines stack size and prototypes the push, pop, peak and isEmpty.
 ******************************************************************************/
 
#ifndef STACK_H
#define STACK_H

// Constant for default stack size (Capitalized)
const int DEFAULT_SIZE = 10;

class Stack {
private:
    int data[DEFAULT_SIZE]; // Static integer array
    int top;                // Tracks the top of the stack

public:
    // Constructor
    Stack();

    // Allowed public methods (camelCase, matching strict assignment specs)
    bool push(int value);
    bool pop(int* value);
    bool peek(int* value);
    bool isEmpty();
};

#endif
