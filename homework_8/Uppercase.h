#ifndef UPPERCASE_H
#define UPPERCASE_H

#include "Encryption.h"

class Uppercase : public FileFilter
{
    public: 
        char transform(char ch);

        void doFilter(std::ifstream &in, std::ofstream & out) override;
};

#endif