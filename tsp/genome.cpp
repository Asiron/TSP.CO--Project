/* 
 * File:   genome.cpp
 * Author: asiron
 * 
 * Created on January 19, 2013, 5:52 PM
 */

#include "genome.h"

genome::genome(const genome& orig){
    this->distance = orig.distance;
    this->fitness = orig.fitness;
    this->evaluated = orig.evaluated;
    this->chromosome = new vector<int>(*(orig.chromosome));
    this->graph = orig.graph;    
}  

genome::genome(Graph* graph){
    this->distance = 0;
    this->fitness = 0;
    this->evaluated = false;
    this->chromosome = new vector<int>();
    this->graph = graph;
    for(int i=0; i<graph->n; ++i){
            chromosome->push_back(i);
    }
    random_shuffle(chromosome->begin(), chromosome->end());
}

genome::~genome(){
    delete chromosome;
}


void genome::mutate(){
    
}

double genome::evaluate(){
    if (evaluated){
        return fitness;
    }else{
        vector<int>::iterator it;
        for( it=chromosome->begin(); it!=chromosome->end()-1; ++it){
            distance += graph->graph[*it][*(it+1)];
        }
        distance += graph->graph[chromosome->back()][chromosome->front()];
    }
    cout << endl << distance << endl;
}
void genome::printGenome(){
    vector<int>::iterator it;
    for( it=chromosome->begin(); chromosome->end() != it; ++it)
        printf("%d ", *it);
    printf("\n");
}
