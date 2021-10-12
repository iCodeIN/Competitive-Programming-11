

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

struct node
{
    int e = 0;
    int o = 0;
};

node solve(int n)
{
    node ans;

    while (n > 0 and n % 2 == 0)
    {
        ans.e++;
        n >>= 1;
    }

    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            ans.o++;
            n /= i;
        }
    }

    if (n != 1)
        ans.o++;

    return ans;
}

int f(int n, int gain)
{
    if (n == 0 or gain == 0)
        return 0;

    if (gain > 0)
        return n * gain;
    else
        return gain;
}

void solve()
{
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    node count = solve(n);

    int ans = 0;
    int one = (n & 1) ? b : a;

    ans += f(count.e, a);
    
    if (not(count.e > 0 and b < 0))
        ans += f(count.o, b);

    ans = max(ans, one);
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