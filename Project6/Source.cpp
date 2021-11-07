#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define HEADER ("Лабораторная работа №6\nВыполнил:Пантюшов Е.\n\n")
#include <queue>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <stack>
using namespace std;
void bfs(int** G, int* DIST, int v, int n)
{
	queue <int> q;
	q.push(v);
	DIST[v] = 0;
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		printf(" %d ", v);
		for (int i = 0; i < n; i++)
		{
			if ((G[v][i] == 1) && (DIST[i] == -1))
			{
				q.push(i);
				DIST[i] = 1+DIST[v];
			}
		}
	}
}
void dfs(int** G, int* DIST, int v, int a, int n)
{
	int rez = a + 1;
	DIST[v] = a;
	for (int i = 0; i < n; i++)
	{
		if (G[v][i] == 1 && DIST[i] == -1)
			dfs(G, DIST,i,rez,n);
		if (G[v][i] == 1 && a < DIST[i])
			dfs(G, DIST, i, rez, n);
	}
}


void task_1_1(int** G, int n)
{
	printf("\nЗадание 1.\n\nПункт 1.\nМатрица смежности:\n");
	for (int i = 0; i < n; i++)
	{
		G[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
		{
			G[i][j] = rand() % 2;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				G[i][j] = 0;
			}
			else
			{
				G[i][j] = G[j][i];
			}
			printf(" %d ", G[i][j]);
		}
		printf("\n");
	}
}
void task_1_2(int** G, int n)
{
	int* DIST = (int*)malloc(n * sizeof(int));
	int v;
	for (int i = 0; i < n; i++)
	{
		DIST[i] = -1;
	}
	printf("\nПункт 1.2.\nВведите точку входа: ");
	scanf("%d", &v);
	printf("Результат работы алгоритма обхода в ширину(матрица): ");
	bfs(G, DIST, v, n);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		if (DIST[i] == -1)
		{
			DIST[i] = 0;
		}
		printf("Расстояние от %dой вершины до %dой вершины=%d\n", v, i, DIST[i]);
	}
	free(DIST);
}
void task_2_1(int** G, int n)
{
	int* DIST = (int*)malloc(n * sizeof(int));
	int v = 0;
	int a = 0;
	for (int i = 0; i < n; i++)
	{
		DIST[i] = -1;
	}
	printf("\nПункт 2.1.\nВведите точку входа: ");
	scanf("%d", &v);
	printf("Результат работы алгоритма обхода в глубину(матрица): ");
	dfs(G,DIST,v,a,n);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		if (DIST[i] == -1)
		{
			DIST[i] = 0;
		}
		printf("Расстояние от %dой вершины до %dой вершины=%d\n", v, i, DIST[i]);
	}
	free(DIST);
}
int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	printf(HEADER);
	printf("Введите размерность матрицы: ");
	int n;
	scanf("%d", &n);
	int** G = (int**)malloc(n * sizeof(int*));
	task_1_1(G, n);
	task_1_2(G, n);
	task_2_1(G, n);
	system("PAUSE");
	return 0;
}
