#include <stdio.h>

void printOptimalParenthesis(int *s, int i, int j, int n) {
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    printOptimalParenthesis(s, i, *((s+i*n) + j), n);
    printOptimalParenthesis(s, *((s+i*n)+j)+1, j, n);
    printf(")");
}

int MatrixChainOrder(int arr[], int n)
{
    int m[n][n];
    int s[n][n];

    int i, j, k, l, q;

    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }

    for (l = 2; l < n; l++) {
        for (i = 1; i < n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = 2147483647;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\nM Table representation:\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\nS table representation:\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }

    printf("\nOptimal Parenthesization: ");
    printOptimalParenthesis((int*)s, 1, n-1, n);

    return m[1][n - 1];
}

int main() {
    int n, a, b;
    printf("Enter number of matrices : ");
    scanf("%d", &n);

    int arr[n+1];
    for(int i=0; i<n; i++){
        printf("Enter row and col size of A%d : ", i+1);
        scanf("%d %d", &a, &b);
        if(i!=0 && a != arr[i]){
            printf("Invalid Sequence\n");
            return -1;
        }
        arr[i] = a;
        arr[i+1] = b;
    }

    printf("\nThe optimal ordering of the given matrices requires %d scalar multiplications.\n", MatrixChainOrder(arr, n+1));

}
