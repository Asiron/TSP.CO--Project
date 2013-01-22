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

// Sorting order macros for chromosome representation
#define ASC true                
#define DESC false              

using namespace std;


/* Chromosome representation class */
class Genome {
        
public:
    /* Constructor. Creates chromosome and initializes auxiliary values*/
    Genome();
    
    /* Constructor. Creates chromosome and initializes all values*/
    Genome(Graph* graph);
    
    /* Copy Constructor. Creates a copy of other chromosome */
    Genome(const Genome& orig);
    
    /* Destructor. Frees up memory*/
    ~Genome();
    
    /* Less than operator overload, for sorting purposes */
    bool operator< (const Genome& oth) const {
        return this->evaluate() < oth.evaluate() ;
    }
    
    /* Prints chromosome, debug purposes*/
    void printGenome();
    
    /* Mutation operator*/
    void mutate();
    
    /* Crossover operator, Ordered Crossover (OX) */
    void crossover(Genome &other);
    
    /* Evaluation function, returns length of path*/
    int evaluate() const;
        
private:
    
    /* Size of chromosome*/
    int                 chromosomeSize;
    
    /* Chromosome in vector representation*/
    vector<int>         *chromosome;
    
    /* Pointer to graph*/
    Graph               *graph;
};

/* Compare class, Uses for comparing Genomes during sorting */
class CompareGenome {
    /*Decides the order in which objects are being sorted*/
    bool reverse; 
    
public:
    
    /*Constructor. Creates comparison object, default parameter is false, ascending order*/
    CompareGenome(const bool& revparam = false){ reverse = revparam; }
    
    /* Actual operator overload, decides order based on fitness function*/
    bool operator() ( const Genome* g1, const Genome*g2 ) const{
        if ( reverse ){
            return g1->evaluate() < g2->evaluate();
        } else {
            return g1->evaluate() > g2->evaluate();
        }
    }
};


#endif	/* GENOME_H */

