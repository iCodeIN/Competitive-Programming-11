

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
#include <bits/stdc++.h>
// #include <cmath>
// #include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>

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

const int N = 1e6;
bool isPrime[N + 10] = {0};
int Ans[N + 10] = {0};

void pre()
{

    for (int i = 2; i <= N; i++)
        isPrime[i] = true;

    for (int i = 2; i * i <= N; i++)
        if (isPrime[i])
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;

    int j = -1;
    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
        {
            int x = i * i;
            int p = 2;
            while (x <= N * N)
            {
                if (isPrime[p + 1])
                    Ans[++j] = x;

                x *= i;
                p++;
            }
        }
    }

    sort(Ans, Ans + ++j);
}

int f(int n)
{
    int l = -1;
    int r = 78711;

    // rightmost <= n
    while (r - l > 1)
    {
        int m = (l + r) >> 1;

        if (Ans[m] <= n)
            l = m;
        else
            r = m;
    }
    return l + 1;
}

void solve()
{
    int n;
    cin >> n;
    int ans = f(n);

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