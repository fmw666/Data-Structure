#include <stdio.h>

const int n = 6;

/*
 * 自底向上方式
 * 
 */
void MatrixChain(int *p, int n, int m[n][n], int s[n][n])
{
    for(int i=0; i < n; i++)
        m[i][i] = 0;
    for(int r=2; r<=n; r++)
        for(int i=1; i<= n-r+1; i++)
        {
            int j = i+r-1;
            m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];
            s[i][j] = i;
            for(int k=i+1; k<j; k++)
            {
                int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(t<m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
}

void Print(int s[n][n], int i, int j)
{
    if(i == j)
        printf("A%d", i);
    else
    {
        printf("(");
        Print(s, i, s[i][j]);
        Print(s, s[i][j]+1, j);
        printf(")");
    }
}

int main()
{
    int p[7] = {30, 35, 15, 5, 10, 20, 25};
    int m[n+1][n+1], s[n+1][n+1];
    MatrixChain(p, n, m, s);
    Print(s, 1, n-1);
    printf("\n");
    
    return 0;
}