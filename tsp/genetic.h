#ifndef GENETIC_H
#define	GENETIC_H

#include <cstdlib>
#include <list>
#include <algorithm>
#include "graph.h"

using namespace std;

class genetic {
public:
    genetic();
    genetic(Graph* graph);
    genetic(const genetic& orig);
    ~genetic();
private:

};
#endif	/* GENETIC_H */

