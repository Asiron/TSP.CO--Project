#include "local_search.h"


Local_search::Local_search(Graph* g){
    this->g = g;
    change_for_better = false;
    path = new int[g->n];
    temp_path = new int[g->n];
    
    for(int i = 0; i < g->n; ++i){
        path[i] = i;
        temp_path[i] = i;
    }
}

Local_search::~Local_search(){
    delete [] path;
    delete [] temp_path;
}

int Local_search::check_path_length(int *p){
    int sum = 0;
    for(int i = 1; i < g->n; ++i){
        sum += g->graph[p[i-1]][p[i]];
    }
    return sum;
}

void Local_search::algorithm(){
    do{
        change_for_better = false;
        length = check_path_length(path);
        
        for(int i = 0; i < g->n; ++i){
            temp_path[i] = path[i];
        }
        for(int i = 0; i < g->n; ++i){
            for(int j = 0; j < g->n; ++j){
                if(i<j){
                    swap(temp_path[i], temp_path[j]);
                    int l = check_path_length(temp_path);
                    if(l < length){
                        temp_i = i;
                        temp_j = j;
                        change_for_better = true;
                        length = l;
                    }
                    swap(temp_path[i], temp_path[j]);
                }
            }
        }
        if(change_for_better){
            swap(path[temp_i], path[temp_j]);
        }
    }while(change_for_better);
}

void Local_search::print(){
    for(int i = 0; i < g->n; ++i){
          cout<< path[i] <<"  ";
    }
    cout<<endl<<check_path_length(path)<<endl;
}