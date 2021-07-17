

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
#include <vector>

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

using namespace std;

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 1, -1, 0, 0, -1, 1};

int m, n;
bool safe(int i, int j)
{
    return i >= 0 and i < m and j >= 0 and j < n;
}

void solve()
{
    cin >> m >> n;

    v(v(char)) A(m, v(char)(n, '0')), B(m, v(char)(n, '0'));
    int c1 = 1;
    int c2 = 1;
    A[0][0] = '1';
    B[0][1] = '1';

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (i == 0 or j == 0 or i == m - 1 or j == n - 1)
            {
                if (A[i][j] == '0')
                {
                    bool possible = true;
                    for (int k = 0; k < 8; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if (safe(x, y))
                            possible &= (A[x][y] == '0');
                    }
                    if (possible)
                        A[i][j] = '1', c1++;
                }
            }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (i == 0 or j == 0 or i == m - 1 or j == n - 1)
            {
                if (i == 0 and j == 0)
                    continue;
                if (B[i][j] == '0')
                {
                    bool possible = true;
                    for (int k = 0; k < 8; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if (safe(x, y))
                            possible &= (B[x][y] == '0');
                    }
                    if (possible)
                        B[i][j] = '1', c1++;
                }
            }

    if (c1 >= c2)
        for (auto &x : A)
        {
            for (char &y : x)
                cout << y;
            cout << endl;
        }
    else
    {
        for (auto &x : B)
        {
            for (char &y : x)
                cout << y;
            cout << endl;
        }
    }
    cout << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //