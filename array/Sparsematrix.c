//SPARSE MARITX
#include <stdio.h>
void sparseadd(int a[50][50], int b[50][50]);
void transpose(int a[50][50]);
void display(int a[50][50], int r, int c);

int main() {
    int A[50][50], B[50][50], C[50][50], D[50][50];
    int r1, r2, c1, c2, k1, k2;

    // Input for first matrix
    printf("Enter the number of rows and columns of the 1st matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the array elements: ");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("The original matrix:\n");
    display(A, r1, c1);

    // Sparse representation of first matrix
    B[0][0] = r1;
    B[0][1] = c1;
    k1 = 1;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            if (A[i][j] != 0) {
                B[k1][0] = i;
                B[k1][1] = j;
                B[k1][2] = A[i][j];
                k1++;
            }
        }
    }
    B[0][2] = k1 - 1;
    printf("The sparse matrix representation of the 1st matrix is:\n");
    display(B, k1, 3);

    printf("The transpose of the matrix is:\n");
    transpose(B);

    // Input for second matrix
    printf("\nEnter the number of rows and columns of the 2nd matrix: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter the array elements: ");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &C[i][j]);
        }
    }

    printf("The original matrix:\n");
    display(C, r2, c2);

    // Sparse representation of second matrix
    k2 = 1;
    D[0][0] = r2;
    D[0][1] = c2;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            if (C[i][j] != 0) {
                D[k2][0] = i;
                D[k2][1] = j;
                D[k2][2] = C[i][j];
                k2++;
            }
        }
    }
    D[0][2] = k2 - 1;
    printf("The sparse matrix representation of the 2nd matrix is:\n");
    display(D, k2, 3);

    printf("\nThe transpose of the second matrix is:\n");
    transpose(D);

    printf("\nThe sum of the matrices is:\n");
    sparseadd(B, D);

    return 0;
}

void display(int a[50][50], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void transpose(int a[50][50]) {
    int t[50][50];
    t[0][0] = a[0][1];
    t[0][1] = a[0][0];
    t[0][2] = a[0][2];
    int k = 1;
    for (int z = 0; z < a[0][1]; z++) {
        for (int i = 1; i <= a[0][2]; i++) {
            if (a[i][1] == z) {
                t[k][0] = a[i][1];
                t[k][1] = a[i][0];
                t[k][2] = a[i][2];
                k++;
            }
        }
    }
    display(t, k, 3);
}

void sparseadd(int a[50][50], int b[50][50]) {
    int r[50][50];
    int l1 = a[0][2];
    int l2 = b[0][2];
    int i = 1, j = 1, k = 1;
    r[0][0] = a[0][0];
    r[0][1] = a[0][1];
    while (i <= l1 && j <= l2) {
        if (a[i][0] == b[j][0]) {
            if (a[i][1] == b[j][1]) {
                r[k][0] = a[i][0];
                r[k][1] = a[i][1];
                r[k][2] = a[i][2] + b[j][2];
                k++;
                i++;
                j++;
            } else {
                if (a[i][1] < b[j][1]) {
                    r[k][0] = a[i][0];
                    r[k][1] = a[i][1];
                    r[k][2] = a[i][2];
                    i++;
                    k++;
                } else {
                    r[k][0] = b[j][0];
                    r[k][1] = b[j][1];
                    r[k][2] = b[j][2];
                    j++;
                    k++;
                }
            }
        } else {
            if (a[i][0] < b[j][0]) {
                r[k][0] = a[i][0];
                r[k][1] = a[i][1];
                r[k][2] = a[i][2];
                i++;
                k++;
            } else {
                r[k][0] = b[j][0];
                r[k][1] = b[j][1];
                r[k][2] = b[j][2];
                j++;
                k++;
            }
        }
    }
    while (i <= l1) {
        r[k][0] = a[i][0];
        r[k][1] = a[i][1];
        r[k][2] = a[i][2];
        i++;
        k++;
    }
    while (j <= l2) {
        r[k][0] = b[j][0];
        r[k][1] = b[j][1];
        r[k][2] = b[j][2];
        j++;
        k++;
    }
    r[0][2] = k - 1;
    display(r, k, 3);
}
