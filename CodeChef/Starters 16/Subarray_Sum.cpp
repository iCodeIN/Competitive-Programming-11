

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
#include <stack>
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
#define d(x) cout << #x << ": " << x << endl;
#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);
    for (int &x : A)
        cin >> x;
    v(int) ngr(n, n);

    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and A[st.top()] < A[i])
            st.pop();

        if (!st.empty())
            ngr[i] = st.top();

        st.push(i);
    }

    while (st.size() > 0)
        st.pop();

    v(int) ngl(n, -1);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and A[st.top()] <= A[i])
            st.pop();
        if (!st.empty())
            ngl[i] = st.top();

        st.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int left = i - ngl[i];
        int right = ngr[i] - i;

        // d(left);
        // d(right);

        int tri = ((right) * (right + 1)) >> 1;
        int sq = (right) * (n - ngr[i]);

        // d(tri);
        // d(sq);
        int contribution = (((tri + sq) % mod) * (A[i])) % mod;
        contribution = (left * contribution) % mod;
        // d(contribution);
        // cout << "------\n";
        ans = (ans + contribution) % mod;
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