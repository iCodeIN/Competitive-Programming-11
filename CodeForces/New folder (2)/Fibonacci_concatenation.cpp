

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

    int z;
    int o;
};

int pow(int x, int n, int m)
{

    int ans = 1;

    while (n)
    {

        if (n & 1)
            ans = (ans * x) % m;

        n >>= 1;

        x = (x * x) % m;
    }

    return ans;
}

const int N = 2 * 1e5;

node A[N + 10];
node B[N + 10];

void solve()
{
    int n;
    cin >> n;

    int p = (A[n].o - 1 + mod - 1) % (mod - 1);
    int ans1 = pow(2, A[n].z, mod);
    int ans2 = (B[n].o * pow(2, p, mod)) % mod;

    ans2 = (ans2 + mod) % mod;

    int ans = (ans1 * ans2) % mod;

    cout << ans << endl;
}

int32_t main()
{
    FastIO;
    A[0].z = 1;
    A[0].o = 0;
    A[1].o = 1;
    A[1].z = 0;

    B[0].z = 1;
    B[0].o = 0;
    B[1].o = 1;
    B[1].z = 0;

    for (int i = 2; i <= N; i++)
    {
        A[i].z = (A[i - 1].z + A[i - 2].z) % (mod - 1);
        A[i].o = (A[i - 1].o + A[i - 2].o) % (mod - 1);

        B[i].z = (B[i - 1].z + B[i - 2].z) % (mod);
        B[i].o = (B[i - 1].o + B[i - 2].o) % (mod);
    }

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //