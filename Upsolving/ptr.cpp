#include <bits/stdc++.h>
using namespace std;

void solve(int A[], int n)
{
    if (n == 0)
    {
        return;
    }
    cout << A[0] << " ";
    solve(A + 1, n - 1);
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};

    solve(A, 5);

    cout << "All well";

    // cout << P << " " << A << endl;
}
