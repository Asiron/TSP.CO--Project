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

/*
 * Representation of a tour, on list
 * Implements mutation, crossover and fitness function
 */
class Genome {
        
public:
    /* Constructor. Initializes values besides pointer to graph. */
    Genome();
    
    /* Constructor. Initializes all values and assigns pointer to graph */
    Genome(Graph* graph);
    
    /* Copy constructor. Creates copy of original Genome. */
    Genome(const Genome& orig);
    
    /* Destructor. Frees up memory*/
    ~Genome();
    
    /* Less then operator overload. Decides order based on fitness function */
    bool operator< (const Genome& oth) const {
        return this->evaluate() < oth.evaluate() ;
    }
    
    /* Print current tour. Debug and info purposes */
    void printGenome();
    
    /* Mutation operator. Mutates Genome, swaps two random cities */
    void mutate();
    
    /* Crossover operator. Performs crossover on an object */
    void crossover(Genome &other);
    
    /* Fitness function. Returns value of fitness function, length of tour
     * Shorter the better.
     *  */
    int evaluate() const;
        
private:
    
    /* size of a chromosome*/
    int                 chromosomeSize;
    
    /* Actual chromosome, in vector representation
     * Indicates tour order.
     */
    vector<int>         *chromosome;
    
    /* Pointer to graph */
    Graph               *graph;
};

/* Comparison class */
class CompareGenome {
    /* Decides ordering
     * true = ascending
     * false = descending
     *  */
    bool reverse; 
public:
    /* Constructs comparison object with default parameter set as false = descending */
    CompareGenome(const bool& revparam = false){ reverse = revparam; }
    /* Operator overload */
    bool operator() ( const Genome* g1, const Genome*g2 ) const{
        if ( reverse ){
            return g1->evaluate() < g2->evaluate();
        } else {
            return g1->evaluate() > g2->evaluate();
        }
    }
};


#endif	/* GENOME_H */

