#ifndef COPY_H
#define COPY_H

#include "Uppercase.h"

class Copy : public FileFilter
{
    public:
        void doFilter(std::ifstream &in, std::ofstream & out) override;
};

#endif 