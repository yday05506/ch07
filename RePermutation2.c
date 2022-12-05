#include <stdio.h>
#define R 3

int b[R];
int cnt = 0;

void PrintB(void) {
	int i;
	cnt++;

	for (i = 0; i < R; i++) printf("%d ", b[i]);
	printf("\n");
}

void exchange(int* p1, int* p2) {
	int temp = *p1;

	*p1 = *p2;
	*p2 = temp;
}

void RePermutation(int a[], int n, int r) {
	int i;

	if (r == R) PrintB();
	else for (i = 0; i < n; i++) {
		exchange(a + 0, a + i); //exchange(&a[0], &a[i]); ��ȯ
		b[r] = a[0];
		RePermutation(a, n, r + 1);
		exchange(a + 0, a + i); //����ġ
	}
}

int main(void) {
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);

	RePermutation(a, n, 0);

	printf("\nn = %d, r = %d �϶�, �ߺ����� ����: %d\n", n, R, cnt);

	return 0;
}