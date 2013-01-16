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
#include "test_operations.h"
#include "local_search.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
   
    Test_operations *brute_test, *nn_test, *fi_test, *ac_test, *ls_test;
    
    brute_test = new Test_operations("brute.csv", "Brute force algorithm");
    nn_test = new Test_operations("greedy.csv", "Nearest Neighbour algorithm");
    fi_test = new Test_operations("farthest_insertion.csv", "Farthest Insertion Algorithm");
    ac_test = new Test_operations("ant_colony.csv", "ant_colony_algorithm");
    ls_test = new Test_operations("Local_search.csv", "local_search_algorithm");
    
    for(int i = 10; i < 11; i++){
        
        Graph *g = new Graph(i,10); 
        g->graph_print();


        Brute *br = new Brute();
        
        brute_test->timer_start();
                cout<< br->brutealgorithm(g)<<endl;
        brute_test->timer_stop(g->n, br->path_length); 
        
        br->print(g->n);
        delete br;
        

        /*Greedy *nn = new Greedy();
        
        nn_test->timer_start();
                nn->nearest_neighbour(g);
        nn_test->timer_stop(g->n, nn->path_length);
        
        delete nn;

        
        Farthest_insertion *fi = new Farthest_insertion();
        fi->initialize(g);
                
        fi_test->timer_start();
                fi->algorithm(g);
        fi_test->timer_stop(g->n, fi->path_length);
                
        fi->print(g);
        fi->clear();
        delete fi;

        srand(time(NULL));
        //graf, pocz. poziom feromonu, współczynnik odparowania feromonu, ilość mrówek, alfa, beta
        Ant_colony *ac = new Ant_colony(g, 1, 0.5, 20, 1, 5);
        
        ac_test->timer_start();
            //graf, ilość iteracji
            ac->algorithm(g, 20);
        ac_test->timer_stop(g->n, ac->best_path_length);
        
        ac->print();
        delete ac;*/
        
        Local_search *ls;
        ls = new Local_search(g);
        
        ls_test->timer_start();
                ls->algorithm();
        ls_test->timer_stop(g->n, ls->length);
        
        cout<<"ls\n";
        ls->print();
        
        delete ls;

        delete g;
    }
    return 0;
}

