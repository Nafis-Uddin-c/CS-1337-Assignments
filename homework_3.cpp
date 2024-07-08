#include <bits/stdc++.h>
using namespace std;

int OddSum(int array[], int size, int sum=0)
{   
    if(size < 0) return sum;
    if(size %2 != 0)  sum += array[size];

    return OddSum(array, size-1, sum);
}

void Backwards(string str, int index = 0)
{   
    if(index >= str.length())  return;
    
    Backwards(str, index+1);
    cout<<str[index];
}

int main()
{
    int test, sum = 0;
    cin>>test;

    int array[] = {0};
    int arr_len = sizeof(array)/sizeof(int);

    string str;
    int str_length = str.length();

    switch (test)
    {
    case 1:
        sum = OddSum(array, arr_len-1);
        cout<<sum;
        break;

    case 2:
        Backwards(str);
        break;
    
    default:
        break;
    }

    return 0;
}