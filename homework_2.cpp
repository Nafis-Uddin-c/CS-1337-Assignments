#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string infilename, str, outputString;
    cin>>infilename;         // taking input the input file name
    
    string outfilename = "vowels_";    
    outfilename.append(infilename);      // output file name
    
    int i = 0, cur = -1, line = 0;
    fstream infile(infilename, ios::in | ios::out | ios::binary);   // opening the input file

    if(!infile)    // if file doesn't exist
    {
        cout<<"File is not exist"<<endl;
        exit(0);    // exit the code
    }
    
    //else the later code will execute since used exit() function
    
    while(!infile.eof())    // running while loop to count the lines
    {
        getline(infile,str);
        line++;
    }
    

    infile.clear();     // clear the flag
    infile.close();     // close the input file

    for(int j = 0; j < line; j++)
    {
        // opening the input file
        infile.open(infilename, ios::in | ios::out | ios::binary);  

        if(j != 0) infile.seekp(cur);         // moving the file pointer to the current position
        getline(infile, str);                // reading a line from the input file

        cur = infile.tellg();             // current position of the file pointer
        infile.clear();                  // clear  the flag
        infile.close();                 // closing the input file

        // opening the output file
        infile.open(outfilename, ios::app | ios::in | ios::out | ios:: binary);  

        for(i = 0; i<str.length(); i++)         // running for loop
        {
            //check if the characters are vowels

            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
                
                {
                    infile<<str[i];       // add the vowels to the output file
                }
        }

        if(j != line-1) infile<<endl;  // input new line as long as loop doesn't reach the length times

        infile.close();         // closing the output file  
    }
    
    return 0;
}
