/*******************************************************************************
 * Name: Manuel Bonilla
 * Assignment: Assignment 4 - Simple Classes & Objects
 * File: stack.cpp
 * Date completed: 6/20/2026
 * Description: This file handles the implementation of all the stack functions
 * it sets the stack index to -1 and uses pointer based pass by reference for pop
 * and peak. 
 ******************************************************************************/

#include "stack.h"

// Constructor: Initializes the stack by setting the top index to -1.
Stack::Stack() {
    top = -1;
}

// push: Safely adds a value to the top of the stack if space is available.
bool Stack::push(int value) {
    bool success = false;
    
    if (top < DEFAULT_SIZE - 1) {
        top++;
        data[top] = value;
        success = true;
    }
    
    return success;
}

// pop: Removes and retrieves the top value via a pointer if the stack is not empty.
bool Stack::pop(int* value) {
    bool success = false;
    
    if (!isEmpty()) {
        *value = data[top];
        top--;
        success = true;
    }
    
    return success;
}

// peek: Copies the top value to a pointer without removing it from the stack.
bool Stack::peek(int* value) {
    bool success = false;
    
    if (!isEmpty()) {
        *value = data[top];
        success = true;
    }
    
    return success;
}

// isEmpty: Checks if the stack is completely empty by looking at the top index.
bool Stack::isEmpty() {
    bool status = false;
    
    if (top < 0) {
        status = true;
    }
    
    return status;
}
