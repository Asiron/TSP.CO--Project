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
#include "farthest_insertion.h"
#include "ant_colony.h"
#include "brute.h"
#include "greedy.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Graph *g = new Graph(10,10); 
    //g->graph_print();
    

    Brute *br = new Brute();
    cout<<"brute: "<<br->brutealgorithm(g)<<endl;
    br->print(g->n);
    delete br;
    

    Greedy *nn = new Greedy();
    cout<<"greedy: "<<nn->nearest_neighbour(g)<<endl;
    delete nn;
    
    Farthest_insertion *fi = new Farthest_insertion();
    fi->initialize(g);
    fi->algorithm(g);
    fi->print(g);
    
    fi->clear();
    delete fi;
    
    srand(time(NULL));
    //graf, pocz. poziom feromonu, współczynnik odparowania feromonu, ilość mrówek, alfa, beta
    Ant_colony *ac = new Ant_colony(g, 1, 0.5, 20, 1, 5);
    //graf, ilość iteracji
    ac->algorithm(g, 20);
    ac->print();
    delete ac;
    
    ac = new Ant_colony(g, 1, 0.5, 100, 1, 5);
    ac->algorithm(g, 20);
    ac->print();
    delete ac;
    
    ac = new Ant_colony(g, 1, 0.5, 100, 1, 5);
    ac->algorithm(g, 50);
    ac->print();
    delete ac;
    
    delete g;
    
    return 0;
}

