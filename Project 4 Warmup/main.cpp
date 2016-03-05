//
//  main.cpp
//  Project 4 Warmup
//
//  Created by Gopi Suresh on 3/4/16.
//  Copyright © 2016 Gopi. All rights reserved.
//

#include <iostream>
#include "DiskList.h"
int main(){
    DiskList d("list.txt");
    char word[] = "Hello";
    d.push_front(word);
    d.push_front("World");
    d.push_front("This");
    d.push_front("is");
    d.push_front("Gopi");
    d.printAll();
    return 0;
}
