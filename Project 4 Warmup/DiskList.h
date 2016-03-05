#ifndef DiskList_h
#define DiskList_h

#include <iostream>
#include "BinaryFile.h"
class DiskList
{
public:
    DiskList(const std::string& filename);
    bool push_front(const char* data);
    bool remove(const char* data);
    void printAll();
private:
    BinaryFile bf;
    int length;
};

#endif /* DiskList_h */
