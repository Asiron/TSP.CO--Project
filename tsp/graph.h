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

//generator grafu pełnego o zadanej liczbie wierzchołków i maksymalnej wadze krawędzi
void graph_generate(int n, int max_length);

//zwolnienie pamięci po grafie
void graph_delete(int n);

//wypisanie grafu na ekran
void graph_print(int n);

#endif	/* GRAF_H */

