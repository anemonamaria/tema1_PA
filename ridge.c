#include <stdio.h>
#include <stdlib.h>

struct munte{
	int inaltime;
	int cost;
};

int check_duplicates(struct munte *a, int n) {
	int i, v[n], j = 0, cost = 0;
	for(i = 0; i< n; i++) {
		if(i > 0 && a[i-1].inaltime == a[i].inaltime) {
			v[j] = i-1;
			j++;
			if(a[i-1].cost > a[i].cost) {
				cost = cost + a[i].cost;
				a[i].inaltime = a[i].inaltime - 1;
			} else {
				cost = cost + a[i-1].cost;
				a[i-1].inaltime = a[i-1].inaltime - 1;
			}
		}
	}
	if (cost == 0) return cost;
	else
	 return cost + check_duplicates(a, n);
}

int main() {
	FILE *f, *g;
	f = fopen("ridge.in", "r");
	g = fopen("ridge.out", "w");

	int n,  i, j = 0;
	long unsigned int cost;
	fscanf(f, "%d", &n);
	int v[n];
	// int *v;
	// v = malloc(sizeof(int) * n);
	struct munte *a = malloc(sizeof(struct  munte) * n);
	for(int i = 0; i < n; i++) {
		fscanf(f, "%d %d", &a[i].inaltime, &a[i].cost);
		if(i > 0 && a[i-1].inaltime == a[i].inaltime) {
			v[j] = i-1;
			j++;
		}
	}
	for(i = 0; i < j ; i++) {
	// printf("%d\n", v[i]);
		if(a[v[i]].inaltime == a[v[i]+1].inaltime &&
			a[v[i]].cost > a[v[i] + 1].cost) {
			cost = cost + a[v[i]+1].cost;
	// printf("%d   a   b cost\n",a[v[i]+1].cost);

			a[v[i]+1].inaltime = a[v[i]+1].inaltime - 1;
		} else if (a[v[i]].inaltime == a[v[i]+1].inaltime) {
			cost = cost + a[v[i]].cost;
	// printf("%d   a    cost\n",a[v[i]].cost);
			a[v[i]].inaltime = a[v[i]].inaltime - 1;
		}
	// printf("%d   cost\n",cost);
	}
	// fprintf(g, "%d", check_duplicates(a, n));
	fprintf(g, "%ld", cost);

	fclose(f);
	fclose(g);
	return 0;
}
