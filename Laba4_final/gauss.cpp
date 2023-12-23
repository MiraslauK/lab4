#include "gauss.h"

float** Create(int n, int m, float* a)
{
	float** arr = new float* [n];

	for (int i = 0; i < n; i++)
		arr[i] = new float[m];


	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = a[i * m + j];


	return arr;
}

void Out(float** a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(10) << a[i][j] << "\t\t";
		cout << endl;
	}

	cout << endl << endl;
}

void SwapLines(int x, int x2, float** a, int m)
{
	for (int j = 0; j < m; j++)
		swap(a[x][j], a[x2][j]);
}

float* Gauss(float** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		float maxi = arr[i][i];

		for (int j = i; j < m; j++)
		{
			arr[i][j] /= maxi;
		}

		for (int k = i + 1; k < n; k++)
		{
			float dp = arr[k][i];

			for (int j = i; j < m; j++)
				arr[k][j] -= arr[i][j] * dp;
		}
	}


	float* ans = new float[n];

	for (int i = n - 1; i >= 0; i--)
	{
		float sum = 0;
		for (int k = i + 1; k < n; k++)
		{
			sum += arr[i][k] * ans[k];
		}
		ans[i] = arr[i][n] - sum;
	}

	return ans;
}

float* VectNevyaz(float* ans, float* arr, int m, int n)
{
	float* newans = new float[n];

	for (int i = 0; i < n; i++)
		newans[i] = 0;

	int k = 0;
	int j = 0;
	float sum = 0;

	for (int i = 0; i < n * m; i++)
	{
		if (j == 3)
		{
			j = 0;
			k++;
			continue;
		}

		newans[k] += ans[j] * arr[i];
		j++;
	}

	j = 3;

	float* res = new float[n];
	for (int i = 0; i < k; i++)
	{
		res[i] = arr[j] - newans[i];
		j += 4;
	}

	return res;
}

double searchNorm(float* vecNev, int n)
{
	float Max = 0;
	for (int i = 0; i < n; i++)
		Max = max(Max, abs(vecNev[i]));

	return Max;
}

double searchError(float* res1, float* res2, int n)
{
	float Max = abs(res1[0] - res2[0]);
	float MaxRes = abs(res1[0]);

	for (int i = 1; i < n; i++) {
		float temp = abs(res1[i] - res2[i]);
		Max = max(Max, temp);
		MaxRes = max(MaxRes, abs(res1[i]));
	}
	return Max / MaxRes;
}

void OutAns(float* ans, int n)
{
	cout << endl << endl << setprecision(3) << "answer : ";
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl << endl;
}

float* calcMatrix(float** matrix, float* r, int n) {
	float* res = new float[n];
	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j < n; j++)
			sum += matrix[i][j] * r[j];
		res[i] = sum;
	}
	return res;
}