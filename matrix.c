#include <stdio.h>
#include <limits.h>

void printOptimalParens(int i, int j, int n, int *brackets, char *name)
{
    if (i == j)
    {
        printf("%c", (*name)++);
        return;
    }
    printf("(");
    printOptimalParens(i, *((brackets + i * n) + j), n, brackets, name);
    printOptimalParens(*((brackets + i * n) + j) + 1, j, n, brackets, name);
    printf(")");
}

void matrixChainOrder(int p[], int n)
{
    int m[n][n], brackets[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    brackets[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    printOptimalParens(1, n - 1, n, (int *)brackets, &name);
    printf("\n");
}

int main()
{
    int p[] = {2, 6, 4, 5, 1};
    int n = sizeof(p) / sizeof(p[0]);
    matrixChainOrder(p, n);
    return 0;
}
