/*
Name: Nafis Uddin
*/



#include <iostream>
using namespace std;

struct Node
{
    int num;
    Node *next = nullptr;
};

void enQueue(int, Node *&);
Node *deQueue(Node *&);
void printQueue(Node *);

void enQueue(int integer, Node *&head)
{
    Node *newnode = new Node;
    newnode->num = integer;

    if(!head) head = newnode;
    else
    {
        Node *tmp = head;
        while(tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = newnode;
    }
}

Node *deQueue(Node *& head)
{
    if(head)
    {
        Node *tmp = head;
        head = tmp->next;
        return tmp;
    }

    else return nullptr;

}

void printQueue(Node *head)
{
    if(!head) return;
    else
    {
        cout<<head->num<<" ";
        printQueue(head->next);
    }

}

int main()
{
    Node *head = nullptr;
    int integer;
    int exp;
    while(cin>>exp)
    {
        switch (exp)
        {
            case 1: 
            {
                cin>>integer;
                enQueue(integer, head);
                break;
            }
            case 2:
            {
                Node *tmp = deQueue(head);
                delete tmp;
                printQueue(head);
                cout<<endl;
            }
            
            default: break;
        }
    }

    return 0;
}

