

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

int f(int a, int b, int c)
{
    return (a - b) * (b - c);
}

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);

    for (int &x : A)
        cin >> x;

    int ans = 0;

    for (int k = 2; k < n; k++)
    {
        int b = A[k];
        set<int> st;
        for (int j = k - 1; j > 0; j--)
        {
            int a = A[j - 1];
            st.insert(A[j]);
            auto itr = st.upper_bound((a + b) / 2);
            int cur = 0;
            if (itr != st.end())
            {
                cur = f(a, *itr, b);
            }
            if (itr != st.begin())
            {
                itr--;
                cur = max(cur, f(a, *itr, b));
            }
            if (itr != st.begin())
            {
                itr--;
                cur = max(cur, f(a, *itr, b));
            }
            ans += cur;
        }
        // cout << ans << endl;
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