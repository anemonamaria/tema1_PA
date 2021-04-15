#include <stdio.h>
#include <stdlib.h>

struct munte{
	int inaltime;
	int cost;
};

long long min(long long a, long long b) {
	if (a < b)
		return a;
	return b;
}

long long  minimumCost(struct munte *a, int n) {
	long long  **cost = (long long **) calloc(n, sizeof(long long *));
	for (int i = 0; i < n; i++) {
		cost[i] = (long long *) calloc(3, sizeof(long long));
	}

	cost[0][1] = a[0].cost;
	cost[0][2] = a[0].cost * 2;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			long long minimum = __LONG_LONG_MAX__;
			int aux = a[i].inaltime - j;
			if (aux < 0) {
				cost[i][j] = __LONG_LONG_MAX__;
				continue;
			} else {
				if (aux != a[i-1].inaltime)
					minimum = min(minimum, cost[i-1][0]);
				if (a[i-1].inaltime - aux != 1)
					minimum = min(minimum, cost[i-1][1]);
				if (a[i-1].inaltime - aux != 2)
					minimum = min(minimum, cost[i-1][2]);
			}
			cost[i][j] = j * a[i].cost + minimum;
		}
	}
	long long rez = __LONG_LONG_MAX__;

	for (int i = 0; i < 3; i++)
		rez = min(rez, cost[n-1][i]);
	return rez;
}

int main() {
	FILE *f, *g;
	f = fopen("ridge.in", "r");
	g = fopen("ridge.out", "w");

	int n;
	fscanf(f, "%d", &n);

	struct munte *a = malloc(sizeof(struct  munte) * n);
	for(int i = 0; i < n; i++) {
		fscanf(f, "%d %d", &a[i].inaltime, &a[i].cost);
	}

	fprintf(g, "%llu", minimumCost(a, n));

	fclose(f);
	fclose(g);
	return 0;
}
