

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

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

bool check(v(v(char)) & A, char ch, int k, int x, int y, v(v(int)) & pre)
{
    int m = A.size();
    int n = A[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sx = i;
            int sy = j;
            int ex = i + k - 1;
            int ey = j + k - 1;

            if (ex >= m or ey >= n)
                break;
            if (x < sx or x > ex or y < sy or y > ey)
                continue;
            bool same = true;
            for (int i_ = sx; i_ <= ex and same; i_++)
            {
                int sum = pre[i_][ey];
                if (sy > 0)
                    sum -= pre[i_][sy - 1];
                // cout << sum << " " << ch * k << endl;
                same &= (sum == (int)(ch * k));
            }
            if (same)
                return true;
        }
    }
    return false;
}

void solve()
{
    int m, n, k;
    cin >> m >> n >> k;

    v(v(char)) A(m, v(char)(n, 0));
    v(v(int)) pre(m, v(int)(n, 0));

    bool winnerDecided = false;
    int player = 0;

    int q = m * n;
    int t = 0;
    while (q--)
    {
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        A[i][j] = (t & 1) ? 'B' : 'A';

        pre[i][j] = A[i][j];
        if (j > 0)
            pre[i][j] += pre[i][j - 1];
        for (int j_ = j + 1; j_ < n; j_++)
            pre[i][j_] = pre[i][j_ - 1] + A[i][j_];

        if (!winnerDecided)
        {
            if (check(A, A[i][j], k, i, j, pre))
                winnerDecided = true, player = t & 1;
        }
        t++;
    }

    if (winnerDecided)
    {
        if (player == 0)
            cout << "Alice";
        else
            cout << "Bob";
    }
    else
        cout << "Draw";

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