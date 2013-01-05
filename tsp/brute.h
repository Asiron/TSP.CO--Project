/* 
 * File:   brute.h
 * Author: mateusz
 *
 * Created on 5 styczeń 2013, 09:47
 */

#ifndef BRUTE_H
#define	BRUTE_H

#include "graph.h"

class Brute{
      private:
              //tablica zawierajaca wierzcholki w kolejnosci odwiedzania
              int *path;
      public:
  
             //algorytm wlasciwy
             int brutealgorithm(Graph *g);
             //funkcja permutujaca ciag odwiedzanych wierzcholkow
             void permute(int *path, int size);
             //funkcja licz¹ca d³ugoæ drogi po ca³ym cyklu
             int sum(Graph *g, int *path);
             //funkcja obliczajaca wartosc silni dla podanego n
             long int factorial(int n);
             //wypisanie najlepszej ścieżki
             void print(int n);
};


#endif	/* BRUTE_H */

