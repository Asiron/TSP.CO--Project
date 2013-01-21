/* 
 * File:   Genome.cpp
 * Author: asiron
 * 
 * Created on January 19, 2013, 5:52 PM
 */

#include "Genome.h"

Genome::Genome(){}

Genome::Genome(Graph* graph){
    this->chromosome = new vector<int>();
    this->graph = graph;
    for(int i=0; i<graph->n; ++i){
            chromosome->push_back(i);
    }
    this->chromosomeSize = graph->n;
    random_shuffle(chromosome->begin(), chromosome->end());
}

Genome::Genome(const Genome& orig){
    this->chromosome = new vector<int>(*(orig.chromosome));
    this->chromosomeSize = orig.chromosomeSize;
    this->graph = orig.graph;
}  

Genome::~Genome(){
    delete chromosome;
}

void Genome::crossover(Genome &other){
    vector<int>::iterator it = find(other.chromosome->begin(),other.chromosome->end(), (*chromosome)[0]);
    if(it == other.chromosome->end()-1)
        return;
    
    if ( this->graph->graph[*it][*(it+1)] <= this->graph->graph[0][1] ) {
        vector<int>::iterator jt = find(chromosome->begin(), chromosome->end(), other.chromosome->operator [](*(it+1)));
        swap((*chromosome)[1], (*chromosome)[*jt]);
    }
}


void Genome::mutate(){
    int preMutationFitness = evaluate();
    int left = 0;
    int right = 0;
    
    while ( left == right ){
        left = rand() % chromosomeSize;
        right = rand() % chromosomeSize;
    }
    swap((*chromosome)[left], (*chromosome)[right]);
    
    if ( preMutationFitness > evaluate())
        swap((*chromosome)[left], (*chromosome)[right]);
}

int Genome::evaluate() const{
    
    int length = 0;
    
    vector<int>::iterator it;
    for( it=chromosome->begin(); it!=chromosome->end()-1; ++it){
        length += graph->graph[*it][*(it+1)];
    }
    length += graph->graph[chromosome->back()][chromosome->front()];
    
    //printf("%d\n", length);
    
    return length; 
}


void Genome::printGenome(){
    vector<int>::iterator it;
    for( it=chromosome->begin(); chromosome->end() != it; ++it)
        printf("%d ", *it);
    printf("\n");
}
