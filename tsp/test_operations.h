/* 
 * File:   test_operations.h
 * Author: mateusz
 *
 * Created on 15 styczeń 2013, 11:01
 */

#ifndef TEST_OPERATIONS_H
#define	TEST_OPERATIONS_H

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <sys/time.h>
#include <fstream>

using namespace std;
class Test_operations{
        private:
            fstream file;       //plik
            string filename;    //nazwa pliku
            struct timeval start, end;  //zmienne "stopera"
            long  seconds, useconds;    
            long double mtime;
            
        public:
            Test_operations(string fname, char* algorithm_name);
            ~Test_operations();
            
            void timer_start(); //rozpoczyna odlicznaie czasu
            void timer_stop(int nodes_num);     //zatrzymuje "stoper", oblicza czas i zrzuca dane do pliku
            void time_print(int nodes_num);     //wypisuje dane na ekran
};

#endif	/* TEST_OPERATIONS_H */

