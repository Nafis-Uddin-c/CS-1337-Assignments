#include "Encryption.h"

Encryption::Encryption()
{
    key = 5;
}

Encryption::Encryption(int k)
{
    key = k;
}

void Encryption::setKey(int key)
{
    this->key = key;
}


void Encryption::doFilter(std::ifstream &in, std::ofstream &out)
{
    char ch;
    while(in.get(ch))
    {
        if(ch == '\n') out.put(ch);
        else 
        {
            int val = static_cast<int>(ch);
            val += key;
            if(val > 126) val = 32 + (val - 127);
            else if(val < 32) val = 127 - (32 - val);

            ch = static_cast<char>(val);
            out.put(ch);
        }

    }
}


