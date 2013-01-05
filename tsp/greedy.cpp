#include "greedy.h"

int greedy :: find_nearest(Graph *g, int point){
    int min = 0;
    int value = INF;
    for (int i = 0; i < (g -> n); i++)
        if ((value > g -> graph[point][i]) && ( visited[i] != true) && (point != i)){
           value = g -> graph[point][i];
           min = i;
        }
    visited[min]=true;
    return min;
}

int greedy :: nearest_neighbour(Graph *g){
    int distance = 0;
    int tmp = 0;
    int next = 0;
    //inicjalizacja tablicy odwiedzonych
    visited = new bool [g -> n];
    for (int i = 0; i < (g -> n); i++)
        visited[i] = 0;
    //pierwszy jest odwiedzony bo od niego zaczynamy
    visited[0] = 1;
    for (int i = 0; i < (g -> n); i++){
              tmp = find_nearest(g,next);
              if (tmp != INF) distance += g -> graph[tmp][next];
              next = tmp;
    }
return distance;    
}
