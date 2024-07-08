#include "Uppercase.h"

char Uppercase::transform(char ch)
{
    if(ch >= 'a'  && ch <= 'z') return ch-32;
    else return ch;
}


void Uppercase::doFilter(std::ifstream &in, std::ofstream & out)
{
    char ch;
    while(in.get(ch))
    {
        out.put(transform(ch));
    }
}