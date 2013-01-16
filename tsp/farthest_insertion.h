/* 
 * File:   farthest_insertion.h
 * Author: mateusz
 *
 * Created on 31 grudzień 2012, 13:10
 */

#ifndef FARTHEST_INSERTION_H
#define	FARTHEST_INSERTION_H
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <list>
#include "graph.h"

class Farthest_insertion{
 public:
     int path_length;
     
    //inicjalizacja potrzebnych do działąnia algorytmu struktur 
    void initialize(Graph *g);
    //sprzatanie po sobie
    void clear();
    //glowny algorytm
    void algorithm(Graph *g);
    //wypisanie cyklu i jego dlugosci
    void print(Graph *g);

private:   
    int search_farthest_node(Graph *g);
    void insert_farthest_node(int node, Graph *g);
    int fi_path_length;
    bool *fi_visited;
    
    list<int> fi_path;
    list<int>::iterator fi_list_it;

};

#endif	/* FARTHEST_INSERTION_H */

