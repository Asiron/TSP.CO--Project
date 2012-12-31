/* 
 * File:   graf.h
 * Author: mateusz
 *
 * Created on 30 grudzień 2012, 19:38
 */

#ifndef GRAF_H
#define	GRAF_H

#include <cstdlib>
#include <stdio.h>
#include <iostream>

using namespace std;


class Graph{
public:

    //macierz sąsiedztwa
    int **graph;
    //ilosc wierzcholkow
    int n;
        
    //generator grafu pełnego o zadanej liczbie wierzchołków i maksymalnej wadze krawędzi
    Graph(int n, int max_length);

    //zwolnienie pamięci po grafie
    ~Graph();

    //wypisanie grafu na ekran
    void graph_print();
};
#endif	/* GRAF_H */

