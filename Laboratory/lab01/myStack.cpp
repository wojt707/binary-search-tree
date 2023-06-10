#include <iostream>
#include "myStackLibrary.h"

int main(int argc, char const *argv[])
{
    myStack<int> exampleStack;

    std::cout << exampleStack.getSize() << std::endl;
    exampleStack.push(11);
    exampleStack.push(3);
    exampleStack.push(5);
    exampleStack.printStack();
    std::cout << "Popped element: " << exampleStack.pop() << std::endl;
    exampleStack.printStack();
    std::cout << "Size: " << exampleStack.getSize() << std::endl;

    myStack<double> d(10);
    std::cout << "Size: " << d.getSize() << std::endl;
    d.push(5.32);
    d.push(0.2);
    d.push(-2.99);
    d.push(-222);
    d.printStack();
    d.pop();
    d.pop();
    d.printStack();

    return 0;
}
