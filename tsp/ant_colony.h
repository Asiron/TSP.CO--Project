/* 
 * File:   ant_colony.h
 * Author: mateusz
 *
 * Created on 2 styczeń 2013, 18:04
 */

#ifndef ANT_COLONY_H
#define	ANT_COLONY_H

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <list>
#include "graph.h"

class Ant_colony{
private:
    //tablica feromonów
    float *pheromones;
    //liczba mrówek
    int ant_number;
    //tablica mrówek;
    Ant *ant_array;
    //współczynnik odparowania
    float evaporation;
    
    //odparowanie feromonu
    void pheromone_evaporating();
    //"uruchomienie" wszystkich mrówek, tak by każda znalazła swoją ścieżkę
    void run_ants();
    //naniesienie nowej porcji feromonu przez mrówki na krawędzie
    void increase_pheromone();
    
    
public:
    //najlepsza ścieżka
    list<int> best_path;
    //evapor z zakresu (0,1);
    Ant_colony(Graph *g, float start_pher, float evapor, int ant_num);
    ~Ant_colony();
    //wykonanie się algorytmu, w efekcie znalezienie cyklu
    void algorithm();
    //wypisanie cyklu
    void print();
        
};

class Ant{
private:
    //czy dany wierzchołek był już odwiedzony
    bool *visited;
    //prawdopodobieństwa przejścia do danego wierzchołka
    int *probabilistic;
    int *cumulated_probabilistic;
    
    //obliczanie prawdopodobieństw
    void calculate_prob(float *pheromones, Graph *g);
    
    //przejście do następnego wierzchołka
    void go_to_next_node();
public:
        //dana ścieżka
    list<int> path;
    
    Ant(Graph *g);
    ~Ant();
    void find_path(Graph *g);

};


#endif	/* ANT_COLONY_H */

