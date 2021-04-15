#include <stdio.h>
#include <stdlib.h>

struct pcs{
	int nrCrypto;  // nr actual
	int cost;  // pretul calculatorului
};

int comp(const void *x1, const void *x2) {
	const struct pcs *pa =  x1;
	const struct pcs *pb =  x2;
	/*sortez crescator dupa nrCrypto si descrescator dupa cost*/
	int rez = pa->nrCrypto - pb->nrCrypto;
	if (rez == 0) {
		return -(pa->cost - pb->cost);
	}
	return rez;
}

int main(int argc, char const *argv[]) {
	FILE *f, *g;
	f = fopen("crypto.in", "r");
	g = fopen("crypto.out", "w");

	int n, bani, i, min = 999999999;
	int cost = 0;
	fscanf(f, "%d %d", &n, &bani);
	struct pcs *a = malloc(sizeof(struct pcs) * n);
	for (i = 0; i < n; i++) {
		fscanf(f, "%d %d", &a[i].nrCrypto, &a[i].cost);
		if (min > a[i].nrCrypto)
			min = a[i].nrCrypto;
	}
	qsort(a, n, sizeof(struct pcs), comp);

	int aux = min;
	i = 0;
	while(cost <= bani) {
		for(i = 0; i < n; i++) {
			if (a[i].nrCrypto < aux) {
				cost = cost + a[i].cost;
				a[i].nrCrypto ++;
			} else {
				break;
			}
		}
		aux++;
	}

	fprintf(g, "%d\n", aux-2);
	fclose(f);
	fclose(g);
	return 0;
}
