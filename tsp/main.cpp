/* 
 * File:   main.cpp
 * Author: mateusz
 *
 * Created on 30 grudzień 2012, 19:37
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include "graph.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    graph_generate(10,10);
    graph_print(10);
    graph_delete(10);
    return 0;
}

