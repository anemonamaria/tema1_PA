#include <stdio.h>
#include <stdlib.h>

struct firme{
	int actual;
	int pierderi;  // actual - minim
	int profit;  //maxim - actual
};

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int buget, int pierderi, struct firme *a, int n)
{
	//  int W, int wt[], int val[], int n
	if (n == 0 || buget == 0 || pierderi == 0)
		return 0;
	if (a[n-1].pierderi >= pierderi || a[n - 1].actual > buget)
		return knapSack(buget, pierderi, a, n - 1);

	else
		return max(
			a[n - 1].profit
				+ knapSack(buget - a[n - 1].actual,
						pierderi - a[n - 1].pierderi, a, n - 1),
			knapSack(buget, pierderi, a, n - 1));
}

int main(){
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
		a[i].pierderi = b - a[i].actual;
	}

	fprintf(g, "%d", knapSack(buget, pierderi, a, n));

	fclose(f);
	fclose(g);
	return 0;
}
