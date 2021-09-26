

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

unsigned int countSetBit(unsigned int n);

unsigned int getLeftmostBit(int n)
{
    int m = 0;
    while (n > 1)
    {
        n = n >> 1;
        m++;
    }
    return m;
}

unsigned int getNextLeftmostBit(int n, int m)
{
    unsigned int temp = 1 << m;
    while (n < temp)
    {
        temp = temp >> 1;
        m--;
    }
    return m;
}

unsigned int _countSetBit(unsigned int n,
                          int m)
{

    if (n == 0)
        return 0;

    m = getNextLeftmostBit(n, m);

    if (n == ((unsigned int)1 << (m + 1)) - 1)
        return (unsigned int)(m + 1) * (1 << m);

    n = n - (1 << m);
    return ((n + 1) + countSetBit(n) + m * (1 << (m - 1)));
}

unsigned int countSetBit(unsigned int n)
{

    int m = getLeftmostBit(n);

    return _countSetBit(n, m);
}

int countSetBits(int L, int R)
{
    int a = countSetBit(R);
    int b = countSetBit(L - 1);
    return abs(a - b);
}

void solve()
{
    int l, r;
    cin >> l >> r;

    int ans = countSetBits(l, r);
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