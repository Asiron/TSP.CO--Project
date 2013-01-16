/* 
 * File:   local_search.h
 * Author: mateusz
 *
 * Created on 15 styczeń 2013, 20:00
 */

#ifndef LOCAL_SEARCH_H
#define	LOCAL_SEARCH_H

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <list>
#include "graph.h"


class Local_search{
private:
    Graph *g;
    
    bool change_for_better;
    int temp_i;
    int temp_j;
    
    
    int *path;
    int *temp_path;
    
public:
    int length;
    
    Local_search(Graph *g);
    ~Local_search();
    
    void algorithm();
    int check_path_length(int *p);
    void print();
    
};

#endif	/* LOCAL_SEARCH_H */

