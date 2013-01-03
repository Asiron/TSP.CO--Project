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
#include <algorithm>
#include <list>
#include <math.h>
#include "graph.h"
class Ant;

class Ant_colony{
private:
    //ilość wierzchołków
    int n;
    //tablica feromonów
    float **pheromones;
    //liczba mrówek
    int ant_number;
    //tablica mrówek;
    Ant **ant_array;
    //współczynnik odparowania
    float evaporation;
    
    //odparowanie feromonu
    void pheromone_evaporate();
    //"uruchomienie" wszystkich mrówek, tak by każda znalazła swoją ścieżkę
    void run_ants(Graph *g);
    //naniesienie nowej porcji feromonu przez mrówki na krawędzie
    void pheromone_increase();
    //usunięcie mrówek
    void delete_ants();
    
public:
    //najlepsza ścieżka
    list<int> best_path;
    //dlugosc najlepszej trasy
    int best_path_length;
    //evapor z zakresu (0,1);
    Ant_colony(Graph *g, float start_pher, float evapor, int ant_num);
    ~Ant_colony();
    //wykonanie się algorytmu, w efekcie znalezienie cyklu
    void algorithm(Graph *g, int iter_num);
    //wypisanie cyklu
    void print();
        
};

class Ant{
private:
    //czy dany wierzchołek był już odwiedzony
    bool *visited;
    //prawdopodobieństwa przejścia do danego wierzchołka
    float *probabilistic;
    //ilość odwiedzonych wierzcholkow
    int visited_nodes_counter;
    
    //obliczanie prawdopodobieństw wybrania danego miasta jako następnego
    void calculate_prob(float **pheromones, Graph *g);
    
    //obliczenie mianownika wzoru na prawdopodobieństwo wyboru miasta
    float denominator(int node, Graph *g, float **pheromones);
    
    //przejście do następnego wierzchołka
    int get_next_node(float **pheromones, Graph *g);
    
public:
    //dana ścieżka
    list<int> path;
    int path_length;
    
    Ant();
    Ant(Graph *g);
    ~Ant();
    void find_path(Graph *g, float **pheromones);
    void print();

};


#endif	/* ANT_COLONY_H */

