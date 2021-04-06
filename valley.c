#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	FILE *f, *g;
	f = fopen("valley.in", "r");
	g = fopen("valley.out", "w");

	int n, i, min = __INT_MAX__, poz_min = -1, last_poz = -1, duplicates = 0;
	long long unsigned int excavat = 0;

	fscanf(f, "%d", &n);
	int *a = malloc(sizeof(int) * n);
	for(i = 0; i < n; i++) {
		fscanf(f, "%d", &a[i]);
		if (a[i] < min && i > 0 && i < n-1) {
			min = a[i];
			poz_min = i;
			last_poz = poz_min;
			duplicates = 1;
		} else if (min == a[i]) {
			duplicates++;
			last_poz = i;
		}
	}

	if (last_poz != poz_min) {
		for (i = poz_min; i < last_poz; i++) {
			excavat = excavat + a[i] - min;
			a[i] = min;
		}
	}

	if (duplicates == n) {
		fprintf(g, "0");
	} else {
		for(i = 0; i < poz_min; i++) {
			if(a[i] < a[i+1]) {
				excavat = excavat + a[i+1] - a[i];
				a[i+1] = a[i];
			}
		}
		for (i = n - 2; i >= last_poz; i--) {
			if (a[i] > a[i+1]) {
				excavat = excavat + a[i] - a[i+1];
				a[i] = a[i + 1];
			}
		}
		fprintf(g, "%lld\n", excavat);
	}

	printf("\n");
	fclose(f);
	fclose(g);
	return 0;
}
