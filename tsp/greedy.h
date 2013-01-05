/* 
 * File:   nearest_neighbour.h
 * Author: mateusz
 *
 * Created on 5 styczeń 2013, 10:21
 */

#ifndef GREEDY_H
#define	GREEDY_H

#include "graph.h"

#define INF 99999999

class greedy{
      private:
              bool *visited;
      public:
             int nearest_neighbour(Graph *g);
             int find_nearest(Graph *g, int point);
};

#endif	/* GREEDY_H */

