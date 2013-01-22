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

    
    int left = 0;
    int right = 0;
    
    while (!(left < right)) {
        left = rand() % chromosomeSize;
        right = rand() % chromosomeSize;
    }
    
    vector<int> *temp = new vector<int>(chromosomeSize, -1);
    for(int i=left; i<=right; i++){
        temp->at(i) = this->chromosome->at(i);
    }
    
    for(int i=0, j=0; i<left; j++){
        if(find(temp->begin(), temp->end(), other.chromosome->at(j)) == temp->end()){
            temp->at(i) = other.chromosome->at(j);
            ++i;
        }
    }
    
    if(right != chromosomeSize-1){        
        for(int i=right+1, j=0; i<chromosomeSize; ++j){
            if(find(temp->begin(), temp->end(), other.chromosome->at(j)) == temp->end()){
                temp->at(i) = other.chromosome->at(j);
                ++i;
            }
        }
    }
    delete this->chromosome;
    this->chromosome = temp;
    
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
