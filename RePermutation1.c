#include <stdio.h>
#define R 3

int b[R];
int cnt = 0;

void RePerPrint(void) {
	int i;

	for (int i = 0; i < R; i++) {
		printf("%5d", b[i]);
	}
	printf("\n");
	cnt++;
}

void Repermutation(int a[], int n, int r) {
	int i = 0;

	if (r == R) RePerPrint();
	else {
		for (i = 0; i < n; i++) {
			b[r] = a[i];
			Repermutation(a, n, r + 1);
		}
	}
}

int main(void) {
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(int);

	Repermutation(a, n, 0);

	printf("중복 순열 개수 : %d", cnt);
}