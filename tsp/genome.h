/* 
 * File:   Genome.h
 * Author: asiron
 *
 * Created on January 19, 2013, 5:52 PM
 */

#ifndef GENOME_H
#define	GENOME_H

#include <cstdlib>
#include <vector>
#include <algorithm>
#include "graph.h"

#define ASC true
#define DESC false

using namespace std;

class Genome {
        
public:
    Genome();
    Genome(Graph* graph);
    Genome(const Genome& orig);
    ~Genome();
    
    bool operator< (const Genome& oth) const {
        return this->evaluate() < oth.evaluate() ;
    }
    
    void printGenome();
    
    void mutate();
    void crossover(Genome &other);
    int evaluate() const;
        
private:
    int                 chromosomeSize;
    vector<int>         *chromosome;
    Graph               *graph;
};

class CompareGenome {
    bool reverse; 
public:
    CompareGenome(const bool& revparam = false){ reverse = revparam; }
    bool operator() ( const Genome* g1, const Genome*g2 ) const{
        if ( reverse ){
            return g1->evaluate() < g2->evaluate();
        } else {
            return g1->evaluate() > g2->evaluate();
        }
    }
};


#endif	/* GENOME_H */

