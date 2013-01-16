#include "test_operations.h"

Test_operations::Test_operations(string fname, char* algorithm_name){
    mtime = 0;
    seconds = 0;
    useconds = 0;
    
    this->filename = fname.c_str();
    filename = "pomiary/"+filename;
    file.open(filename.c_str(), fstream::in|fstream::out|fstream::trunc);
    file << algorithm_name << "\n";
    file << "liczba wierzcholkow,czas [ms],dlugosc trasy\n";
    file.close();
}

Test_operations::~Test_operations(){

}

void Test_operations::timer_start(){
    gettimeofday(&start, NULL);
}

void Test_operations::timer_stop(int nodes_num, int path_length){
    gettimeofday(&end, NULL);

    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    //mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
    mtime = (long double)(seconds * 1000 * 1000 + useconds)/1000;
    
    file.open(filename.c_str(), fstream::in|fstream::out|fstream::app);
    file << nodes_num << "," << mtime << "," << path_length << "\n";
    file.close();
}

void Test_operations::time_print(int nodes_num){
    cout<< nodes_num << "\t" << this->mtime << "\n";
}