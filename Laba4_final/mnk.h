#pragma once

#include <iostream>
#include "gauss.h"

using namespace std;

double Pow(double x, int s)
{
	double ans = 1;
	for (int i = 0; i < s; i++)
		ans *= x;
	return ans;
}

float* CalcPOWERX(float* x, int n, int m)
{
	float* arr = new float[m*2];
	for (int i = 0; i < m*2; i++)
	{
		arr[i] = 0;
		for (int j = 0; j < n; j++)
			arr[i] += Pow(x[j], i+1);
	
	}
	return arr;
}

float* CalcPRAWX(float* x, float* y, int n, int m)
{
	float* arr = new float[m+1];
	for (int i = 0; i < m+1; i++)
	{
		arr[i] = 0;
		for (int j = 0; j < n; j++)
			arr[i] += y[j] * Pow(x[j], i);

	}
	return arr;
}

float* MNK(float* x, float* y, int n, int m)
{
	float* powerx = CalcPOWERX(x, n, m);
	float* prawx = CalcPRAWX(x, y, n, m);

	float** mat = new float* [m + 1];
	for (int i = 0; i < m + 1; i++)
		mat[i] = new float[m + 2];

	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			if (i == 0 && j == 0)
				mat[i][j] = n;
			else
				mat[i][j] = powerx[i + j - 1];

		}

	}

	for (int i = 0; i < m + 1; i++)
		mat[i][m + 1] = prawx[i];

	float* ans = Gauss(mat, m + 1, m + 2);


	return ans;
}

double Calculate(float* c, int n, double x)
{
	double ans =  c[0];
	for (int i = 1; i < n; i++)
	{
		ans += c[i] * Pow(x, i);
	}
	return ans;
}

float CalcOtkl(float* x, float* y, int n, float* c, int k)
{
	double ans = 0;

	for (int i = 0; i < n; i++)
	{
		double a = y[i] - Calculate(c, k, x[i]);
		ans += a * a;
	}

	ans /= n - k;

	return sqrt(ans);
}