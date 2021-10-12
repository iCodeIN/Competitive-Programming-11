

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
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

int len(int x)
{
    int ans = 0;

    while (x)
    {
        ans++;
        x /= 10;
    }
    return ans;
}

int solve(v(int) A[], int len1, int len2, int l, bool smaller)
{

    if(smaller)
    {

        

    }
}

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;

    v(int) A[10];

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        A[len(x)].push_back(x);
    }

    for (int i = 1; i < 10; i++)
        sort(all(A[i]));

    int len_l = len(l);
    int len_r = len(r);

    int ans = n * n;

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (i + j < len_l or i + j > len_r)
            {
                int f1 = A[i].size();
                int f2 = A[j].size();
                ans -= (f1 * f2);
            }
            else
            {
                if (i + j == len_l)
                    ans -= solve(A, i, j, l, 1);
                if (i + j == len_r)
                    ans -= solve(A, i, j, r, 0);
            }
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //