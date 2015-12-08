/**
 * Celem zadania jest napisanie szablonu klasy reprezentujacej macierz 2D.
 * Charakterystyczne jest to że rozmiary macierzy zadawane sa w czasie kompilacji.
 * Tym samym Matrix<double, 2, 2> i Matrix<double, 3, 3> sa roznymi typami.
 * Dostep do elemetow macierzy realizowany jest poprzez metode szabolonowa at
 * ktorej argumentami sa indeksy macierzy.
 * Tym sposobem mozna w czasie kompilacji spawdzic czy nie wychodzi sie poza zakres tablicy.
 * (Nie trzeba implementowac samego sprawdzenia. Chyba ze komus starczy czasu.)
 * Tablice o tym samym rozmiarze i roznym typie przechowywanym mozna dodawac.
 * Kompilowac z -Wall -g do pliku mtest
 **/

#include <iostream>
#include "Matrix.h"


int main() {

  Matrix<double, 2, 3> a;
  a.zero(5.1); // ustawia wszystkie warosci na 5.1
  Matrix<double, 3, 3> b;

 // a.add(b); // to sie nie moze kompilowac, jesli sie kompiluje to jest 0 pkt za zadanie
 
  b.at<1,1>() = 2.5;
  b.at<1,2>() = 3.1;

  Matrix<int, 3, 3> c;
  c.at<2,0>() = 7;
  b.add(c); // a to sie kompiluje bo wymiary sa takie same
 
  std::cout << b;
}
/* wynik
 0 0 7
 0 2.5 0
 0 3.1 0
 */
