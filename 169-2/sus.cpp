#include <stdio.h>
#include <string.h>
 
#define A	10000000
 
int xx[A + 1];
 
void init() {
	int a, b, x;
 
	memset(xx, -1, (A + 1) * sizeof *xx);
	for (a = 0; a <= A; a += 2)
		xx[a] = 0;
	xx[1] = 1;
	for (a = 3, x = 2; a <= A; a++)
		if (xx[a] == -1) {
			for (b = a; b <= A; b += a)
				if (xx[b] == -1)
					xx[b] = x;
			x++;
		}
}
 
int main() {
	int t;
 
	init();
    for (int i = 0; i < 1000; i++) {
        printf("%d ", xx[i]);
    }
	scanf("%d", &t);
	while (t--) {
		int n, a, x;
 
		scanf("%d", &n);
		x = 0;
		while (n--) {
			scanf("%d", &a);
			x ^= xx[a];
		}
		printf(x ? "Alice\n" : "Bob\n");
	}
	return 0;
}