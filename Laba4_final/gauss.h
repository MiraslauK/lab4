#pragma once

#include <iostream>
#include <iomanip>

using namespace std;




void Out(float** a, int n, int m);
float** Create(int n, int m, float* a);
void SwapLines(int x, int x2, float** a, int m);
float* Gauss(float** arr, int n, int m);
void OutAns(float* ans, int n);
float* VectNevyaz(float* ans, float* arr, int m, int n);
double searchNorm(float* vecNev, int n);
double searchError(float* res1, float* res2, int n);
float* calcMatrix(float** matrix, float* r, int n);