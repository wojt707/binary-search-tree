#include <iostream>
#include "myStackLibrary.h"

template <class T>
myStack<T>::myStack()
{
    std::cout << "constructed" << std::endl;
    this->bottom = this->top = new T[this->maxSizeOfStack = 100];
}

template <class T>
myStack<T>::myStack(int s)
{
    std::cout << "constructed with param " << s << std::endl;
    this->bottom = this->top = new T[this->maxSizeOfStack = s];
}

template <class T>
myStack<T>::~myStack()
{
    delete[] bottom;
}

template <class T>
void myStack<T>::push(T element)
{
    *this->top++ = element;
}

template <class T>
T myStack<T>::pop()
{
    return *--this->top;
}

template <class T>
int myStack<T>::getSize()
{
    return top - bottom;
}

template <class T>
void myStack<T>::printStack()
{
    for (size_t i = 0; i < this->top - this->bottom; i++)
    {
        std::cout << "---" << *(this->bottom + i) << "---" << std::endl;
    }
}
template class myStack<int>;
template class myStack<double>;