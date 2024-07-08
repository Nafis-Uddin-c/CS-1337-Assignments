/*
    Name: Nafis Uddin
    Name: Kevin Chieng


*/


/*
    Activities :

    Kevin =  Wrote the 2nd function and checked the code manually
    Nafis =  Wrote the main and 1st function and tested the code 

*/


#include <iostream>
using namespace std;

void integerToBinary(int number)
{
    if(number == 0) return;

    int bin = number %2;
    number /= 2;
    integerToBinary(number), 
    cout<<bin;
}

void num_search(int array[], int size, int number, int index = 0)
{
    bool test = 0;
    if(index >= size) return;

    if(number == array[index]) 
    {
        test = 1;
        cout<<"The binary number of this integer is ";
        integerToBinary(number);
    }

    if(index == (size-1)) 
    {
        if(test != 1)
        cout<<"The number doesn't exist"<<endl;
    }
    return num_search(array, size, number, index+1);
    
}

int main()
{
    int number;
    cout<<"Write an integer"<<endl;
    cin>>number;

    int array[] = {0};
    int arr_len = sizeof(array)/sizeof(int);
    num_search(array, arr_len, number);
    return 0;
}
