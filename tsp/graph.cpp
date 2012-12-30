#include "graph.h"

//macierz sąsiedztwa
int **graph;

//generator grafu pełnego o zadanej liczbie wierzchołków i maksymalnej wadze krawędzi
void graph_generate(int n, int max_length){
    
//alokacja pamięci
    graph = new int*[n];
    
    for(int i = 0; i < n; ++i){
        graph[i] = new int[n];
    }
 
//generowanie grafu
    srand ( time(NULL) );
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i!=j){
                graph[i][j] = rand() % max_length +1;
            }else{
                graph[i][j] = 0;
            }
        }
    }    
    
}

//zwolnienie pamięci po grafie
void graph_delete(int n){
    for(int i=0; i < n; ++i){
        delete [] graph[i];
    }
    delete [] graph;
}

//wypisanie grafu na ekran
void graph_print(int n){
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    } 
}
