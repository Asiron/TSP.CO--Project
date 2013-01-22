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
#include "genetic.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
   
    Test_operations *brute_test, *nn_test, *fi_test, *ac_test, *ls_test, *ga_test;
    
    /*brute_test = new Test_operations("brute.csv", "Brute force algorithm");
    nn_test = new Test_operations("greedy.csv", "Nearest Neighbour algorithm");
    fi_test = new Test_operations("farthest_insertion.csv", "Farthest Insertion Algorithm");
    ac_test = new Test_operations("ant_colony.csv", "ant_colony_algorithm");
     */ 
    ls_test = new Test_operations("Local_search.csv", "local_search_algorithm");
   

    for(int i = 100; i < 101; i++){
        
        Graph *g = new Graph(i,100); 
        //g->graph_print();

/*
        Brute *br = new Brute();
        
        brute_test->timer_start();
                cout<< br->brutealgorithm(g)<<endl;
        brute_test->timer_stop(g->n, br->path_length); 
        
        br->print(g->n);
        delete br;
        

        Greedy *nn = new Greedy();
        
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
        delete ac;
*/
        
        Local_search *ls;
        ls = new Local_search(g);
        
        ls_test->timer_start();
                ls->algorithm();
        ls_test->timer_stop(g->n, ls->length);
        
        cout<<"ls\n";
        ls->print();
        
        ga_test = new Test_operations("ga_benchmark.csv", "Number of vertices from 50 to 500, population size 50, number of epochs 50*vertices, xover 0.06, mutation 0.03, elite size 5");
//        for(int i=50; i<500; i+=50){
//            Graph *graph = new Graph(i,100);
//            Genetic ga(graph, i*20, 0.06, 0.03, 50, 5);
//            ga_test->timer_start();
//            int result = ga.run().evaluate();
//            ga_test->timer_stop(i, result);
//            delete graph;
//        }
        
        for(int i=100; i<10000; i+=100){
            Genetic ga(g, i, 0.06, 0.03, 50, 5);
            for(int j=0; j<5; j++){
                ga_test->timer_start();
                int result = ga.run().evaluate();
                ga_test->timer_stop(i, result);
            }
        }
        
        delete ls;
        delete ls_test;
        delete ga_test;
        delete g;
    }

//    Graph *g = new Graph(100,50);
//    srand(time(NULL));
    
//    ac_test = new Test_operations("ACO_const_ant_number_10.csv","ilosc wierzcholkow w tym wypadku jest iloscia iteracji algorytmu\n");
//    //graf, pocz. poziom feromonu, współczynnik odparowania feromonu, ilość mrówek, alfa, beta
//    for(int i = 10; i <= 105; i+=5){
//    
//        Ant_colony *ac = new Ant_colony(g, 1, 0.5, 10, 1, 5);
//        
//        ac_test->timer_start();
//            //graf, ilość iteracji
//            ac->algorithm(g, i);
//        ac_test->timer_stop(i, ac->best_path_length);
//        delete ac;
//        cout<<"const_ant: "<<i<<endl;
//    }
//    delete ac_test;
//    
//    ac_test = new Test_operations("ACO_const_iterations_number_10.csv","ilosc wierzcholkow w tym wypadku jest iloscia mrowek\n");
//    for(int i = 10; i <= 105; i+=5){
//    
//        Ant_colony *ac = new Ant_colony(g, 1, 0.5, i, 1, 5);
//        
//        ac_test->timer_start();
//            //graf, ilość iteracji
//            ac->algorithm(g, 10);
//        ac_test->timer_stop(i, ac->best_path_length);
//        delete ac;
//        cout<<"const_iter: "<<i<<endl;
//    }
//    
//    ac_test = new Test_operations("ACO_increasing_ants_and _iterations.csv","ilosc wierzcholkow w tym wypadku jest iloscia mrowek i iteracji\n");
//    for(int i = 10; i <= 105; i+=5){
//    
//        Ant_colony *ac = new Ant_colony(g, 1, 0.5, i, 1, 5);
//        
//        ac_test->timer_start();
//            //graf, ilość iteracji
//            ac->algorithm(g, i);
//        ac_test->timer_stop(i, ac->best_path_length);
//        delete ac;
//        cout<<"const_nth: "<<i<<endl;
//    }
//    
//    delete ac_test;
    return 0;
}

