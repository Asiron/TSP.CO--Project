#include <string>
#include <vector>

#include "ant_colony.h"

Ant::Ant(){
}

Ant::Ant(Graph* g){
    visited = new bool[g->n];
    for(int j = 0; j < g->n; ++j){
        visited[j] = false;
    }
    
    probabilistic = new float[g->n];
 
    //losowanie miasta poczatkowego
    srand(time(NULL));
    int i = rand() % g->n;
    path.push_back(i);
    visited[i] = true;
    path_length = 0;
    visited_nodes_counter = 1;
}

Ant::~Ant(){
    delete [] visited;
    delete [] probabilistic;
    path.clear();
}

float Ant::denominator(int node, Graph *g, float **pheromones){
    float result = 0;
    
    for(int i = 0; i < g->n; ++i){
        if(!visited[i]){
            result = result + (pheromones[node][i] / g->graph[node][i]);
        }
    }
    return result;
}

void Ant::calculate_prob(float **pheromones, Graph *g){
    list<int>::iterator it = --path.end();
    
    for(int i = 0; i < g->n; ++i){
        if(visited[i]){
            probabilistic[i] = 0;
        }else{
            probabilistic[i] = (pheromones[*it][i] / g->graph[*it][i]) / denominator(*it, g, pheromones);
        }
    }
    
    for(int i = 1; i < g->n; ++i){
        probabilistic[i] += probabilistic[i-1];
    }
}

int Ant::get_next_node(float **pheromones, Graph *g){
    int next_node;
    calculate_prob(pheromones, g);
    
    srand(time(NULL));
    float rnd = rand() % (int)floor(probabilistic[g->n - 1]);
    
    if(rnd <= probabilistic[0]){
        next_node = 0;
    }else{
        for(int i = 1; i < g->n; ++i){
            if(rnd <= probabilistic[i]){
                next_node = i;
                break;
            }
        }
    }
  return next_node;  
}

void Ant::find_path(Graph* g, float **pheromones){
    int node;
    list<int>::iterator it;
    
    while(visited_nodes_counter < g->n){
        node = get_next_node(pheromones, g);
        it = --path.end();
        path_length += g->graph[*it][node];
        path.push_back(node);
        visited_nodes_counter++;
    }
    
    it = --path.end();
    path_length += g->graph[*it][*path.begin()];
}

void Ant::print(){
    list<int>::iterator it;
    
    for(it = path.begin(); it != path.end(); ++it){
        cout<<*it<<"  ";
    }
    cout<<endl<<"length: "<<path_length<<endl;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
Ant_colony::Ant_colony(Graph* g, float start_pher, float evapor, int ant_num){
    n = g->n;
    
    pheromones = new float*[g->n];
    for(int i = 0; i < g->n; ++i){
        pheromones[i] = new float[g->n];
    }
    
    for(int i = 0; i < g->n; ++i){
        for(int j = 0; j < g->n; ++j){
            pheromones[i][j] = start_pher;
        }
    }
    
    this->ant_number = ant_num;
    this->evaporation = evapor;
    this->ant_array = new Ant*[ant_num];
    
    this->best_path_length = 0;
    
 /*   for(int i = 0; i < ant_num; ++i){
        ant_array[i] = new Ant(g);
    }*/
}

Ant_colony::~Ant_colony(){
    for(int i = 0; i < n; ++i){
        delete [] pheromones[i];
    } 
    delete [] pheromones;
    
    for(int i = 0; i < ant_number; ++i){
        delete ant_array[i];
    }
    delete [] ant_array;
}

void Ant_colony::pheromone_evaporate(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            pheromones[i][j] *= (1-evaporation);
        }
    }
}

void Ant_colony::pheromone_increase(){
    for(int i = 0; i < ant_number; ++i){
        if(ant_array[i]->path_length > best_path_length){
            best_path_length = ant_array[i]->path_length;
            copy(ant_array[i]->path.begin(), ant_array[i]->path.end(), best_path.begin()); 
        }
        list<int>::iterator it, it2;
        for(it = ant_array[i]->path.begin(); it != --ant_array[i]->path.end(); ++it){
            it2 = it;
            it2++;
            pheromones[*it][*it2] += 1 / ant_array[i]->path_length;
            pheromones[*it2][*it] += 1 / ant_array[i]->path_length;
        }
        it = ant_array[i]->path.begin();
        it2 = ant_array[i]->path.end();
        it2--;
        pheromones[*it][*it2] += 1 / ant_array[i]->path_length;
        pheromones[*it2][*it] += 1 / ant_array[i]->path_length;
    }
}

void Ant_colony::run_ants(Graph *g){
    for(int i = 0; i < ant_number; ++i){
        ant_array[i] = new Ant(g);
    }
    for(int i = 0; i < ant_number; ++i){
        ant_array[i]->find_path(g, pheromones);
    } 
}

void Ant_colony::delete_ants(){
    for(int i = 0; i < ant_number; ++i){
        delete ant_array[i];
    }
}

void Ant_colony::algorithm(Graph *g, int iter_num){
    for(int i = 0; i < iter_num; ++i){
        pheromone_evaporate();
        run_ants(g);
        pheromone_increase();
        delete_ants();
    }
}

void Ant_colony::print(){
    list<int>::iterator it;
    
    for(it = best_path.begin(); it != best_path.end(); ++it){
        cout<<*it<<"  ";
    }
    cout<<endl<<"length: "<<best_path_length<<endl;
}  