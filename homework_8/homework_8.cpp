#include "FileFilter.h"
#include "Encryption.h"
#include "Uppercase.h"
#include "Copy.h"

#include <iostream>

int main()
{
    std::cout<<"Enter the filename: "<<std::endl;
    std::string filename;
    std::cin>>filename;

    Encryption encrypt_object1;
    std::ifstream infile(filename);
    std::ofstream  outfile("EncryptionDefault.txt");
    encrypt_object1.doFilter(infile, outfile);
    infile.close();
    outfile.close();

    Encryption encrypt_object2(12);
    infile.open(filename);
    outfile.open("Encryption12.txt");
    encrypt_object2.doFilter(infile, outfile);
    infile.close();
    outfile.close();

    Encryption encrypt_object3(-4);
    infile.open(filename);
    outfile.open("Encryption-4.txt");
    encrypt_object3.doFilter(infile, outfile);
    infile.close();
    outfile.close();

    Uppercase uppercase_object;
    infile.open(filename);
    outfile.open("Uppercase.txt");
    uppercase_object.doFilter(infile, outfile);
    infile.close();
    outfile.close();

    Copy copy_object;
    infile.open(filename);
    outfile.open("Copy.txt");
    copy_object.doFilter(infile, outfile);
    infile.close();
    outfile.close();

    return 0;
}