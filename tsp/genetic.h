#ifndef GENETIC_H
#define	GENETIC_H

#include <cstdlib>
#include <queue>
#include <algorithm>
#include "graph.h"
#include "Genome.h"

using namespace std;

// Forward declarations
class Genome;
class CompareGenome;

/* Main class for running GA */
class Genetic {
public:
    /* Constructor. Creates object and initializes all its values */
    Genetic(Graph* graph, int epochs, float crossoverRate, float mutationRate, int populationSize, int eliteSize);
    
    /* Copy constructor. Creates copy of an object*/
    Genetic(const Genetic& orig);
    
    /* Destructor. Frees up memory*/
    ~Genetic();
    
    /* Main run method. Runs algorithm and returns reference to solution */
    Genome& run();
    

private:
    /* Chance for mutation to happen */
    float       mutationRate;
    /* Chance for crossover to happen */
    float       crossoverRate;
    /* Size of population*/
    int         populationSize;
    /* Size of elite that is transfer to next generation*/
    int         eliteSize;
    /* Number of epochs to run*/
    int         epochs;
    /* Pointer to graph*/
    Graph       *graph;
    /* Population. In vector representation */
    vector<Genome*>      *population;
    /* Result */
    Genome      result;
    /* Pointer to comparison object*/
    CompareGenome *comp;
    
};
#endif	/* GENETIC_H */

