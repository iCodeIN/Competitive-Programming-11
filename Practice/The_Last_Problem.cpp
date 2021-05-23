

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
#include <bits/stdc++.h>
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

int A[1001][1001];
int rowPre[1001][1001] = {0};
int colPre[1001][1001] = {0};
void pre()
{
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++)
            A[i][j] = -1;
    int v = 0;
    for (int j = 1; j <= 1000;)
    {
        int i = 1;
        int nj = j + 1;
        while (i <= 1000 and j >= 1)
            A[i++][j--] = ++v;
        j = nj;
    }

    for (int i = 2; i <= 1000;)
    {
        int j = 1000;
        int ni = i + 1;
        while (i <= 1000 and j >= 1)
            A[i++][j--] = ++v;
        i = ni;
    }

    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            rowPre[i][j] = A[i][j] + rowPre[i][j - 1];
            colPre[i][j] = A[i][j] + colPre[i - 1][j];
        }
    }
}

int solve(int x1, int y1, int x2, int y2)
{
    int ans = 0;

    ans = colPre[x2][y1] - colPre[x1 - 1][y1];

    ans += rowPre[x2][y2] - rowPre[x2][y1 - 1];

    ans -= A[x2][y1];
    return ans;
}

void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int ans = solve(x1, y1, x2, y2);
    cout << ans << endl;
}

int32_t main()
{
    FastIO;
    pre();
    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //