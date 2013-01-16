#include "brute.h"

long int Brute :: factorial (int n){
     long tmp = 1;
     for (int i = 2; i <= n; i++)
         tmp *= i;
     return tmp;
}

void Brute :: permute (int *path, int size){
     int i,j;
     
     i = size - 1;
     while ((i > 0) && (path[i - 1] >= path[i]))
           i--;
     if (i > 0){
           j = size;
           while ((j > 0) &&(path[j - 1] <= path[i - 1]))
                 j--;
     }
     if ((i > 0) && (j > 0))
        swap(path[i-1], path[j-1]);
     for (i++, j = size; i < j; i++, j--)
         swap(path[i-1], path[j-1]);
}

int Brute :: sum(Graph *g, int *path){
     int distance = 0;
     for (int i=1; i < (g->n); i++)
         distance += g->graph[ path[i] - 1 ][ path[i - 1] - 1 ] ;
     //dodanie drogi z ostatniego punktu do punktu startowego
     distance += g->graph[ path[0] - 1 ][ path[ (g -> n) - 1] - 1 ];
     return distance;
}

int Brute :: brutealgorithm(Graph *g){
     int distance = 99999999;
     int tmp = 0;
     //generowanie tablicy o rozmiarze równej liczbie wierzcho³ków grafu
     path = new int [g->n + 1];
     //inicjalizacja tablicy wartociami od 1 do n
     for (int i = 0; i < g->n; i++)
         path[i] = i + 1;
     for (int i = 0; i <= factorial(g->n); i++){
         //trasa - permutowanie
         permute(path, g->n);
         //sumowanie odleg³oci
         tmp = sum(g, path);
         //wybór najkrótszej
         if (distance >= tmp) 
            distance = tmp;
     }
     path_length = distance;
     return distance;
}

void Brute::print(int n){
    for(int i = 0; i < n; ++i){
        cout<<" "<<path[i]-1;
    }
    cout<<endl;
}