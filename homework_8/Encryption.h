#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "FileFilter.h"
#include <fstream>

class Encryption : public FileFilter
{
    private: 
        int key;

    public: 
        Encryption();
        Encryption(int k);

        void setKey(int key);
    
    void doFilter(std::ifstream & in, std::ofstream & out) override;
};

#endif
