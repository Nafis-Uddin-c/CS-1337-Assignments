/*

Name: Nafis Uddin

Name: Aeden Chandy

Group: 10


Activities:

Aeden --- Opened the file and allocated the numbers into the dynamic array
            Helped to debug the code


Nafis --- Calculated the lowest, highest number, Sum, and average




*/






#include <iostream> 
#include <fstream>
using namespace std;

int main()
{
    string filename = "E:\\PROBLEM SOLVE\\inclass_2.txt";

    // string filename;
    // cin>>filename;
    
    fstream file(filename, ios::in | ios:: out | ios:: binary);

    if(!file) cout<<"File doesn't open"<<endl;
    else
    {
        int number; 
        int count = 0;

        while(file>>number)
        {
            count++;
        }

        int *new_arr = new int [count];
        file.clear();
        file.seekg(0, ios::beg);

        while(file>>number)
        {
            *new_arr = number;
            new_arr += 1; 
        }

        new_arr -= count; 

        for(int i = 0; i<count;  i++)
        {
            new_arr++;
        }

        new_arr -= count; 
        int lowest =  *new_arr, highest = *new_arr, sum =0 , ave =0; 

        for(int i = 0; i<count; i++)
        {
            if(lowest > *new_arr) lowest = *new_arr;
            if(highest < *new_arr) highest = *new_arr;
            sum += *new_arr; 
            new_arr++;
        }

        ave = sum/count;

        cout<<"Lowest number is "<<lowest<<endl;
        cout<<"Highest number is "<<highest<<endl;
        cout<<"Sum is "<<sum<<endl;
        cout<<"Average is "<<ave<<endl;

        delete [] new_arr;

    }
    
    return 0;
}