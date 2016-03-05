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
    return 0;
}
