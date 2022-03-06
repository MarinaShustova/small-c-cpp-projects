#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define N 500
#define M 10
float A[N][N], I[N][N], B[N][N], At[N][N], R[N][N], Mba[N][N], Rd[N][N], Res[N][N], Bt[N][N], Rt[N][N];
int sign = 0;

void multBA()
{
	int i, j, k, s;
	for (i = 0; i<N; ++i)
		for (j = 0; j < N; ++j)
		{
			Mba[i][j] = 0;
			for (k = 0; k < N; ++k)
				Mba[i][j] += B[i][k] * At[j][k];
		}
}

void multRdR()
{
	int i, j, k, s;
	if (sign %2 == 0)
	for (i = 0; i<N; ++i)
		for (j = 0; j < N; ++j)
		{
			Mba[i][j] = 0;
			for (k = 0; k < N; ++k)
				Mba[i][j] += Rd[i][k] * Rt[j][k];
		}
	else
		for (i = 0; i<N; ++i)
			for (j = 0; j < N; ++j)
			{
				Rd[i][j] = 0;
				for (k = 0; k < N; ++k)
					Rd[i][j] += Mba[i][k] * Rt[j][k];
			}
	++sign;
}

void multResB()
{
	int i, j, k, s;
	for (i = 0; i<N; ++i)
		for (j = 0; j < N; ++j)
		{
			Mba[i][j] = 0;
			for (k = 0; k < N; ++k)
				Mba[i][j] += Res[i][k] * Bt[j][k];
		}
}

void check()
{
	int i, j, k;
	for (i = 0; i<N; ++i)
		for (j = 0; j < N; ++j)
		{
			Res[i][j] = 0;
			for (k = 0; k < N; ++k)
				Res[i][j] += Mba[i][k] * A[k][j];
		}
	for (i = 0; i < N; ++i)
	{
		printf("\n");
		for (j = 0; j < N; ++j)
		{
			printf("%f ", Res[i][j]);
		}
	}
}

int main()
{
	float  exch;
	size_t i, j, k, s = 0, p = 0, s_max = 0, p_max = 0;
	clock_t start, finish;
	srand(time(0));
	for (i = 0; i<N; ++i) //init A2
		for (j = 0; j<N; ++j)
			A[i][j] = (i == j) ? 2 : 0;
	/*for(i = 0; i<N; ++i) 
		for (j = 0; j<N; ++j)
			A[i][j] = rand() % 30;*/
	for (i = 0; i<N; ++i) //init I
		for (j = 0; j<N; ++j)
			I[i][j] = (i == j) ? 1 : 0;
	start = clock();
	memcpy(At, A, N*N*sizeof(float));
	for (i = 1; i < N; ++i)
		for (j = 0; j < i; ++j)
			At[i][j] = A[j][i];
	for (i = 0; i<N; ++i) //max_line
	{
		for (j = 0; j<N; ++j)
			s += A[i][j];
		if (s>s_max)
			s_max = s;
		s = 0;
	}
	for (j = 0; j<N; ++j)
	{
		for (i = 0; i<N; ++i)
			p += A[i][j];
		if (p>p_max)
			p_max = p;
		p = 0;
	}
	p_max *= s_max;
	memcpy(B, At, N*N * sizeof(float));
	for (i = 0; i<N; ++i)
	{
		for (j = 0; j<N; ++j)
		{
			B[i][j] = (double)(B[i][j] / p_max);
		}
	}
	multBA(); //multing
	for (i = 0; i<N; ++i)  //init R
		for (j = 0; j<N; ++j)
			R[i][j] = I[i][j] - Mba[i][j];
	memcpy(Rd, R, N*N * sizeof(float));
	memcpy(Rt, R, N*N * sizeof(float));
	for (i = 1; i < N; ++i)
		for (j = 0; j < i; ++j)
			Rt[i][j] = R[j][i];
	for (k = 0; k < M; ++k)
	{
		multRdR();
		for (i = 0; i < N; ++i)
			for (j = 0; j < N; ++j)
			{
				if (sign % 2 == 0)
					Res[i][j] += Mba[i][j];
				else
					Res[i][j] += Rd[i][j];
			}
	}
	for (i = 0; i<N; ++i)
		Res[i][i] += 1;
	memcpy(Bt, B, N*N * sizeof(float));
	for (i = 1; i < N; ++i)
		for (j = 0; j < i; ++j)
			Bt[i][j] = B[j][i];
	multResB();
	finish = clock();
//	check();
	printf("Time taken %lf sec\n", (double)(finish - start)/1000);
	return 0;
}
