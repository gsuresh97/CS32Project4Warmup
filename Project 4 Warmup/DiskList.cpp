//
//  DiskList.cpp
//  Project 4 Warmup
//
//  Created by Gopi Suresh on 3/5/16.
//  Copyright © 2016 Gopi. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "DiskList.h"
#include "BinaryFile.h"

using namespace std;

DiskList::DiskList(const string& filename){
    bf.createNew(filename);
}

bool DiskList::push_back(const char *data){
    int size = 0;
    for (int i = 0; data[i] != 0; i++) {
        size++;
    }
    size++;
    if (bf.fileLength()==0) {
        int first = 4;
        bf.write(first, 0);

        if (!bf.write(size + 2*sizeof(int), 0))
            return false;
        if (!bf.write(size, sizeof(int)))
            return false;
        if (!bf.write(data, size, 2*sizeof(int)))
            return false;
        int null = 0;
        if (!bf.write(null, 2*sizeof(int) + size))
            return false;
        return true;
    } else {
        int offset = 0;
        int next;
        do{
            bf.read(next, offset);
            if (next != 0) {
                offset = next;
            }
        } while(next != 0);
        if (!bf.write(offset + size + 2*sizeof(int), offset))
            return false;
        if (!bf.write(size, offset + sizeof(int)))
            return false;
        if (!bf.write(data, size, offset + 2*sizeof(int)))
            return false;
        int null = 0;
        if (!bf.write(null, offset + 2*sizeof(int) + size))
            return false;
        return true;
    }
}

bool DiskList::push_front(const char *data){
    int size = 0;
    for (int i = 0; data[i] != 0; i++) {
        size++;
    }
    size++;
    if (bf.fileLength()==0) {
        int first = 4;
        bf.write(first, 0);

        if (!bf.write(size + 2*sizeof(int) + 4, 0 + 4))
            return false;
        if (!bf.write(size, sizeof(int) + 4))
            return false;
        if (!bf.write(data, size, 2*sizeof(int) + 4))
            return false;
        int null = 0;
        if (!bf.write(null, 2*sizeof(int) + size + 4))
            return false;
        return true;
    } else {
        int first;
        bf.read(first, 0);
        int offset = bf.fileLength();
        /*int next;
        do{
            bf.read(next, offset);
            if (next != 0) {
                offset = next;
            }
        } while(next != 0);*/
        if (!bf.write(offset + size + 2*sizeof(int), offset))
            return false;
        if (!bf.write(size, offset + sizeof(int)))
            return false;
        if (!bf.write(data, size, offset + 2*sizeof(int)))
            return false;
        int null = 0;
        if (!bf.write(null, offset + 2*sizeof(int) + size))
            return false;
        return true;
    }
}


void DiskList::printAll(){
    int offset = 0;
    int next;
    bf.read(next, 0);
    while (next != 0) {
        //cout << next;
        int size;
        bf.read(size, offset + sizeof(int));
        char word[size + 1];
        bf.read(word, size, offset + 2*sizeof(int));
        /*for (int i = 0; i < size; i++) {
            cout << (int)word[i] << endl;
        }*/
        cout << word << endl;
        offset = next;
        bf.read(next, offset);
    }
    
}