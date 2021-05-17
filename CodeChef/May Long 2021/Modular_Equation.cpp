

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

// #define int long long int
#define mod 1000000007ll
#define endl "\n"

static v(int) fac[500003];
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
// return count of factors of x <= y
long long count(int x, int y)
{

    if (fac[x].size() > 0)
    {
        int l = -1;
        int r = fac[x].size();

        while (r - l > 1)
        {
            int m = (l + r) / 2;

            if (fac[x][m] <= y)
                l = m;
            else
                r = m;
        }
        return l + 1;
    }
    else
    {
        int ans = 0;
        for (int j = 1; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                fac[x].push_back(j);
                if (j <= y)
                    ans++;
                if (j * j != x)
                {
                    fac[x].push_back(x / j);
                    if (x / j <= y)
                        ans++;
                }
            }
        }
        sort(all(fac[x]));
        return ans;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    long long  ans = 0;

    for (int b = 2; b <= min(m, n); b++)
        ans += count(m - (m % b), b - 1);
    if (n > m)
    {
        long long  extra = (n - m);
        extra *= (m + n - 1);
        extra /= 2;
        ans += extra;
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