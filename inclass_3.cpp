// Nafis Uddin and Luis Lopez
//Colaborated on one computer to work on each function together
#include <iostream>
using namespace std;

struct node
{
    int num;
    node *next;
};

node* removeNode(node *&head, int position)
{
    node* hold = new node;
    node* ptr = head;
    int counter= 0;
   
    if (position == 0)
    {
        cout << "The 0 position is delete\n";
        hold = head;
        head = head -> next;
        return hold;
    }
    else
    {
        while (ptr->next != nullptr)
        {
            counter++;
            if(counter == position)
            {
                hold = ptr -> next;
                ptr -> next = hold -> next;
                return hold;
            }
            ptr = ptr->next;
           
        }
    }
}

void insertNode(node *&head, int position, int value)
{
    node *A = new node, *ptr = head;
    A -> num = value;
    int counter = 0;
   
    if (position == 0)
    {
        cout << "The position is zero\n";
        A -> next = head;
        head = A;
    }
    else
    {
        while (ptr->next != nullptr)
        {
            counter++;
            if(counter == position)
            {
                A -> next = ptr -> next;
                ptr -> next = A;
            }
            ptr = ptr->next;
           
        }
    }
}

int search(node *& head, int numfind)
{
    node* find = head;
    int placement = 0;
    int position;
   
    if(find == nullptr)
    {
        return -1;
    }
    else
    {
        while(find)
        {
            if(find->num == numfind)
            {
                position = placement;
            }
            placement++;
            find = find->next;
        }
    }
    return position;
}

void addNode(node *&);
void deleteNode(node *&, int);
void printList(node *);

void printList(node *head)
{
    node *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->num << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
void addNode(node *&head)
{
    node *A = new node, *ptr = head;

    cout << "Enter the value for the node: ";
    cin >> A->num;
    A->next = nullptr;

    ptr = head;
    if (head == nullptr)
    {
         head = A;
         return;
    }
    else if (A->num < head->num)
    {
        A->next = head;
        head = A;
        return;
    }
    else
    {
        while (ptr->next != nullptr)
        {
            if (ptr->next->num > A->num)
            {
                A->next = ptr->next;
                ptr->next = A;
                return;
            }
            ptr = ptr->next;
        }
    }

    //if (ptr->next == nullptr)
        ptr->next = A;
}

void deleteNode(node *&head, int del)
{
    node *ptr = head;

    if (head == nullptr)
    {
        cout << "Nothing to delete";
        return;
    }
    else if (del == head->num)
    {
        head = head->next;
        ptr->next = nullptr;
        delete ptr;
        return;
    }
    else
    {
        while (ptr->next != nullptr)
        {
            if (ptr->next->num == del)
            {
                node *hold = ptr->next;
                ptr->next = ptr->next->next;
                hold->next = nullptr;
                delete hold;
                return;
            }
            ptr = ptr->next;
        }

    }
    cout << "Number is not in list";
}

int main()
{
    int menu;
    node *head = nullptr;

    do
    {
        cout << "1. Add Node\n"
            << "2. Delete Node\n"
            << "3. Print List\n"
            << "4. Search List\n"
            << "5. Insert Node\n"
            << "6. Remove Node\n"
            << "7. Quit\n\n"
            << "Please pick an operation for the linked list: ";
        cin >> menu;

        if (menu == 1)
            addNode(head);
        else if (menu == 2)
        {
            int num2del;
            cout << "What number would you like to delete";
            cin >> num2del;
            deleteNode(head, num2del);
        }
        else if (menu == 3)
            printList(head);
           
        else if (menu == 4)
        {
            int searchnum;
            cout << "What do you want to go: ";
            cin >> searchnum;
            int answer = search(head, searchnum);
            cout << answer << endl;
        }
        else if (menu == 5)
        {
            int num, placement;
            cout << "Enter the value for the node: ";
            cin >> num;
            cout << "Where do you want it to go: ";
            cin >> placement;
            insertNode(head, placement, num);
        }
        else if (menu == 6)
        {
            int placement;
            cout << "Where do you want something to delete: ";
            cin >> placement;
            node* hold = removeNode(head, placement);
            delete hold;
        }

    } while (menu != 7);

}
