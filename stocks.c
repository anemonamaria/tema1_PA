#include <stdio.h>
#include <stdlib.h>

struct firme{
	int actual;
	int pierderi;  // actual - minim
	int profit;  // maxim - actual
};

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int knapsack3D(struct firme *a, int n, int buget, int pierderi) {
	int ***profit = (int ***) calloc(n + 1, sizeof(int **));
	for (int i = 0; i <= n; i++) {
		profit[i] = (int **) calloc(buget + 1, sizeof(int *));
		for (int j = 0; j <= buget; j++) {
			profit[i][j] = (int *) calloc(pierderi + 1, sizeof(int));
		}
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= buget; j++) {
			for (int k = 1; k <= pierderi; k++) {
				if((j >= a[i-1].actual) && (k >= a[i-1].pierderi))
					profit[i][j][k] = max(profit[i-1][j][k],
						profit[i-1][j-a[i-1].actual][k-a[i-1].pierderi] + a[i-1].profit);
				else
					profit[i][j][k] = profit[i-1][j][k];
			}
		}
	}

	return profit[n][buget][pierderi];
}


int main() {
	FILE *f, *g;
	f = fopen("stocks.in", "r");
	g = fopen("stocks.out", "w");

	int n, buget, pierderi, i;
	fscanf(f, "%d %d %d", &n, &buget, &pierderi);
	struct firme *a = malloc(sizeof(struct firme) * n);
	int d, b, c;
	for (i = 0; i < n; i++) {
		fscanf(f, "%d %d %d", &a[i].actual, &b, &c);
		a[i].profit = c - a[i].actual;
		a[i].pierderi = a[i].actual - b;
	}

	fprintf(g, "%d", knapsack3D(a, n, buget, pierderi));

	fclose(f);
	fclose(g);
	return 0;
}
