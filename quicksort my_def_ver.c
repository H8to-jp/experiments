#include<stdio.h>
#define rep(i, n) for(int i = 0; i < n; i++)

void print_array_int(int A[], int len) {
	rep(i, len) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

//配列のアドレス値(ポインタ)を介して配列の要素を入れ替える関数
void swap(int* x, int* y) {
	int tmp = 0;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

//クイックソートを実行する関数
void quick_sort(int A[], int l, int r) {	//Array, left, right
	int cl = l, cr = r, p = A[(l + r) / 2];	// cursor left, cursor right, pivot
	printf("%d %d %d\n", l, r, p);
	if (r - l > 0) {
		while (1) {
			while (A[cl] < p && cl <= r) {
				cl += 1;
			}
			while (p < A[cr] && cr >= l) {
				cr -= 1;
			}
			if (cl < cr) {
				swap(&A[cl], &A[cr]);
				cl += 1;
				cr -= 1;
			}
			else {
				print_array_int(A, 10);
				break;
			}
		}
		quick_sort(A, l, cl - 1);
		quick_sort(A, cr + 1, r);
	}
	else {
		//void
	}
}

int main(void) {
	int X[10] = { 5, 0, 9, 7, 1, 6, 3, 8, 4, 2 };
	print_array_int(X, 10);
	quick_sort(X, 0, 9);
	print_array_int(X, 10);

	return 0;
}