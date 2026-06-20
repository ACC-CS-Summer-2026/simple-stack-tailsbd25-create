/*******************************************************************************
 * Name: Manuel Bonilla
 * Assignment: Assignment 4 - Simple Classes & Objects
 * File: main.cpp
 * Date completed: 6/20/2026
 * Description: This is the test bed where the whole program runs, it takes the
 * stack through each check for testing. It then runs a large dynamic loop of 1000
 * random operations to stress test the stack.
 ******************************************************************************/
 
 #include "main.h"

// main: Comprehensive testbed evaluating stack safety, boundaries, and random execution.
int main() {
    Stack testStack;
    int i;
    int tempValue;
    int randomChoice;
    int currentExpectedSize;
    int totalRandomOps;
    bool operationSuccess;
    int returnStatus;

    // Initialize tracking variables
    currentExpectedSize = 0;
    totalRandomOps = DEFAULT_SIZE * 100;
    returnStatus = 0;

    // Seed the random number generator
    std::srand(std::time(0));

    std::cout << "========================================\n";
    std::cout << "STARTING EXPLICIT BOUNDARY TESTING\n";
    std::cout << "========================================\n\n";

    // Underflow testing
    std::cout << "Checking underflow on empty stack:\n";
    std::cout << "isEmpty() returns (1 for true): " << testStack.isEmpty() << "\n";
    
    operationSuccess = testStack.peek(&tempValue);
    std::cout << "peek() on empty stack returns success status: " << operationSuccess << "\n";

    operationSuccess = testStack.pop(&tempValue);
    std::cout << "pop() on empty stack returns success status: " << operationSuccess << "\n\n";

    // Fill stack to full capacity
    std::cout << "Filling the stack to capacity (" << DEFAULT_SIZE << " items):\n";
    i = 0;
    while (i < DEFAULT_SIZE) {
        operationSuccess = testStack.push(i * 10);
        std::cout << "Pushing " << (i * 10) << " | Success status: " << operationSuccess << "\n";
        i++;
    }
    std::cout << "isEmpty() returns (0 for false): " << testStack.isEmpty() << "\n\n";

    // Overflow testing
    std::cout << "Checking overflow on full stack:\n";
    operationSuccess = testStack.push(999);
    std::cout << "push() on full stack returns success status: " << operationSuccess << "\n\n";

    // Emptying ad verifying LIFO
    std::cout << "Emptying stack to verify Last-In, First-Out (LIFO):\n";
    i = 0;
    while (i < DEFAULT_SIZE) {
        operationSuccess = testStack.pop(&tempValue);
        std::cout << "Popped value: " << tempValue << " | Success status: " << operationSuccess << "\n";
        i++;
    }
    std::cout << "\n";

    // Dynamic random testing
    std::cout << "========================================\n";
    std::cout << "STARTING DYNAMIC RANDOM TESTING\n";
    std::cout << "Executing " << totalRandomOps << " random operations...\n";
    std::cout << "========================================\n";

    i = 0;
    while (i < totalRandomOps) {
        // Generate a pseudo-random choice: 0 = push, 1 = pop, 2 = peek
        randomChoice = std::rand() % 3;

        if (randomChoice == 0) {
            // Test push operation
            tempValue = std::rand() % 1000;
            operationSuccess = testStack.push(tempValue);
            if (operationSuccess) {
                currentExpectedSize++;
            }
        }
        else if (randomChoice == 1) {
            // Test pop operation
            operationSuccess = testStack.pop(&tempValue);
            if (operationSuccess) {
                currentExpectedSize--;
            }
        }
        else if (randomChoice == 2) {
            // Test peek operation
            operationSuccess = testStack.peek(&tempValue);
        }

        i++;
    }

    std::cout << "Random testing completed with zero crashes.\n";
    std::cout << "Final expected stack size tracked independently: " << currentExpectedSize << "\n";
    std::cout << "Final isEmpty() verification: " << testStack.isEmpty() << "\n";
    std::cout << "========================================\n";

    return returnStatus;
}
