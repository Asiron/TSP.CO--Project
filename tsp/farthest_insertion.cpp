#include "farthest_insertion.h"

void Farthest_insertion::initialize(Graph *g){
    fi_visited = new bool[g->n];
    for(int i = 0; i < g->n; ++i){
        fi_visited[i] = false;
    }
    fi_path_length = 0;
}

void Farthest_insertion::clear(){
    delete [] fi_visited;
    fi_path.clear();
}
//////////////////////////////////////////////////////////////////////////////////
void Farthest_insertion::algorithm(Graph *g){
    int temp_node = 0;
    
    fi_path.push_back(0);
    fi_visited[0] = true;
    fi_path_length++;
    
    temp_node = search_farthest_node(g);   
    fi_path.push_back(temp_node);
    fi_visited[temp_node] = true;
    fi_path_length++;
    
    while(fi_path_length < g->n){
             temp_node = search_farthest_node(g);
             insert_farthest_node(temp_node,g);
             fi_visited[temp_node] = true;
             fi_path_length++;
    }
}
/////////////////////////////////////////////////////////////////////////////////
int Farthest_insertion::search_farthest_node(Graph *g){
    int farthest_node = -1;
    int distance = -1;
    
    for(int i = 1; i < g->n; ++i){
        if(!fi_visited[i]){
            int min_edge = 99999999;
            for(fi_list_it = fi_path.begin(); fi_list_it != fi_path.end(); ++fi_list_it){
                if(g->graph[*fi_list_it][i] < min_edge){
                    min_edge = g->graph[*fi_list_it][i];
                    if(min_edge > distance){
                        distance = min_edge;
                        farthest_node = i;
                    }
                } 
            }
        }
    }
cout<< farthest_node<< endl;    
return farthest_node;    
}

void Farthest_insertion::insert_farthest_node(int node, Graph *g){
    list<int>::iterator pre = fi_path.begin(); //wierzchołek po którym należy umieścić wstawiany wierzchołek
    list<int>::iterator post = ++pre;
    
    int min_value;
    int temp = 99999999;
    
    min_value = g->graph[*pre][node] + g->graph[node][*post] - g->graph[*pre][*post];
    
    for(fi_list_it = ++fi_path.begin(); fi_list_it != --fi_path.end(); ++fi_list_it){
        post = fi_list_it;
        post++;
        temp = g->graph[*fi_list_it][node] + g->graph[node][*post] - g->graph[*fi_list_it][*post];
        if(temp < min_value){
            min_value = temp;
            pre = fi_list_it;
        }
    }
    
    
    temp = g->graph[*(--fi_path.end())][node] + g->graph[node][*fi_path.begin()] - g->graph[*(--fi_path.end())][*fi_path.begin()];
    if(temp < min_value){
        min_value = temp;
        pre = (--fi_path.end());
    }
    
    fi_path.insert(++pre,node);
}

void Farthest_insertion::print(Graph *g){
    for(fi_list_it = fi_path.begin(); fi_list_it != fi_path.end(); ++fi_list_it){
        cout<<*fi_list_it<<" ";
    }
    cout<<endl;

    int distance = 0;
    
    for(fi_list_it = fi_path.begin(); fi_list_it != --fi_path.end(); ++fi_list_it){
        list<int>::iterator next = fi_list_it;
        distance += g->graph[*fi_list_it][*(++next)];
    }
    distance+=g->graph[*--fi_path.end()][*fi_path.begin()];
    cout<<distance<<endl;
}
