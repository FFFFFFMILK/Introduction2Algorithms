// Rewrite the MERGE procedure so that it does not use sentinels, 
// instead stopping once either array L or R has had all its elements 
// copied back to A and then copying the remainder of the other array back into A.

#include <iostream>
using namespace std;

void merge(int A[], int p, int q, int r) {
    int i, j, k;

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (j = 0; j < n2; j++)
        R[j] = A[q + j + 1];

    for(i = 0, j = 0, k = p; k <= r; k++) {
        if (i == n1) { // i 堆的牌到底了
            A[k] = R[j++]; // equal: A[k] = R[j]; j++;
        } else if (j == n2) { // j 堆的牌到底了
            A[k] = L[i++];
        } else if (L[i] <= R[j]) { 
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void merge_sort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main()
{
	int A[9] = {23, 2, 4, 34, 56, 7, 12, 0, 5};

	merge_sort(A, 0, 8);

	for (int i=0; i < 9; i++)
		cout<< "A["<<i<<"] is " << A[i] <<endl;

	return 0;
}