#include <iostream>
using namespace std;

#include "Data.h"
#include "Node.h"
#include "Stack.h"


int main()
{
    Stack stack;
    Node *newnode = nullptr;
    for(int i = 0; i<5; i++)
    {
        newnode = new Node(Data((i+1)*10.0));
        stack << newnode;
        std::cout << stack;
    }

    newnode = nullptr;
    while(stack.getHead())
    {
        stack >> newnode;
        std::cout << stack;
        delete newnode;
    }
}