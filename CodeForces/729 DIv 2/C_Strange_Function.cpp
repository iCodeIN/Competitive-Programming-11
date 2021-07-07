

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
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

int lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}

int f(int n, int i)
{
    int ans = 1;
    for (int j = 0; p[j] < i; j++)
    {
        int t = p[j];
        while (t < n)
        {
            ans *= p[j];
            t *= t;
        }
    }
    cout << ans << " ";
    // return ans;
    if (ans % i == 0)
        return 0;
    return (n / ans) + (n / i) - (n / lcm(ans, i));
}

void solve()
{
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 2; i <= 4; i++)
    {
        ans += f(n, i);
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