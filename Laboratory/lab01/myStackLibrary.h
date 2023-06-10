
#ifndef myStackLibrary_h
#define myStackLibrary_h

template <class T>
class myStack
{
private:
    T *bottom;
    T *top;
    int maxSizeOfStack;

public:
    myStack();
    myStack(int s);
    ~myStack();

    void push(T element); // push element on the top of the stack
    T pop();              // return top element
    int getSize();        // get size of the stack
    void printStack();    // print each element from the stack
};

#endif
