

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
#include <set>
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
v(int) spf(300001);

void pre()
{
    const int N = spf.size();
    for (int i = 2; i < N; i++)
        spf[i] = i;

    for (int i = 2; i * i < N; i++)
        if (spf[i] == i)
            for (int j = i * i; j < N; j += i)
                spf[j] = i;
}
int f(int n)
{
    if (n == 1)
        return 0;

    set<int> st;

    while (n != 1)
    {
        st.insert(spf[n]);
        n /= spf[n];
    }
    int ans = (int)st.size();
    ans = 1 << (ans - 1);

    return ans;
}

void solve()
{
    int q, n;
    cin >> q >> n;

    while (q--)
    {
        int k;
        cin >> k;

        int ans = f(k);

        cout << ans << endl;
    }
}

int32_t main()
{
    FastIO;
    pre();
    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
