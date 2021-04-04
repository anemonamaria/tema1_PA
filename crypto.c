#include <stdio.h>
#include <stdlib.h>

struct pcs{
	int nrCrypto; // nr actual
	int cost; //pretul calculatorului
	int index;
};

int main(int argc, char const *argv[]){
	FILE *f, *g;
	f = fopen(argv[1], "r");
	if (f == NULL) {
		fprintf(stderr, "Eroare: Fisierul nu poate fi deschis %s", "gard.in");
		return -1;
	}
	g = fopen("gard.out", "w");

	int n, bani, max, min;
	fscanf(f, "%d %d", &n, &bani);
	struct pcs *a = malloc(sizeof(struct pcs) * n);
	for (i = 0; i < n; i++) {
		fscanf(f, "%d %d", &a[i].nrCrypto, &a[i].cost);
		a[i].index = i; // de la 0 la 4
	}
	qsort(a, n, sizeof(struct pcs), cmpf);
	max = a[0].stop;
	for (i = 1; i < n; i++) {
		if (a[i].stop <= max) {
			red++;
		} else {
			max = a[i].stop;
		}
	}

	fprintf(g, "%d", red);

	return 0;
}