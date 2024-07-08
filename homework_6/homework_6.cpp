#include <iostream>
using namespace std;


#include "Data.h"
#include "Node.h"
#include "Stack.h"


void print_stack(const Stack& print_stack)
{
    Node *temp = print_stack.getHead();
    while(temp)
    {
        std::cout<<temp->getPayload().getOperand()<<" ";
        temp = temp->getNext();
    }
    std::cout<<std::endl;
}


int main()
{
    Node *newnode = new Node(Data(10, '+'));
    Node *temp = newnode;
    for(int i = 0; i < 4; i++)
    {
        temp = temp->getNext();
        temp->setNext(new Node(Data(10*(i+2), '+')));
    }

    Stack first_obj(newnode);
    Stack second_obj(first_obj);


    std::cout << "Print stack " << std::endl;

    print_stack(first_obj);
    print_stack(second_obj);



    //Using mutators, add 1 to each operand in one of the stack objects
    temp = second_obj.getHead();
    while(temp)
    {
        double operand = temp->getPayload().getOperand() + 1;
        temp->getPayload().setOperand(operand);
        temp = temp->getNext();
    }


    std::cout << "Print stack after adding 1 " << std::endl;

    print_stack(first_obj);
    print_stack(second_obj);
    
    delete newnode;
    
    return 0;
}




