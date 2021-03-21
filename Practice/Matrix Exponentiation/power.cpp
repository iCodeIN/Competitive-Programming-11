#include <iostream>
using namespace std;

// multiply(A,B,m,p,n) : Returns [C] = [A]*[B] in O(m*n*p)
// [A] : m x p
// [B] : p x n
int **multiply(int **A, int **B, int m, int p, int n)
{
    int **C = new int *[m];
    for (int i = 0; i < m; i++)
        C[i] = new int[n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < p; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    return C;
}

// pow(A,n,p) : Returns [A]^p in O(n^3 * log(p))
// [A] : n x n
int **pow(int **A, int n, int p)
{
    int i = 0;

    int **ans = new int *[n];
    for (int i = 0; i < n; i++)
        ans[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = (i == j);
    
    int **curr = A;
    int **temp = nullptr;
    
    while (p)
    {
        if (p & 1)
        {
            temp = ans;
            ans = multiply(ans, curr, n, n, n);
            delete temp;
        }

        temp = curr;
        curr = multiply(curr, curr, n, n, n);
        if (temp != A)
            delete temp;
        p >> 1;
    }
    return ans;
}

int main()
{
    // Code Here
}