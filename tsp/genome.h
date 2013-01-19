/* 
 * File:   genome.h
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

using namespace std;

class genome {
public:
    genome(Graph* graph);
    genome(const genome& orig);
    ~genome();
    
    void mutate();
    double evaluate();
    
    void printGenome();
    
private:
    double              fitness;
    bool                evaluated;
    int                 distance;
    vector<int>         *chromosome;
    Graph               *graph;
};

#endif	/* GENOME_H */

