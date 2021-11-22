

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

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    v(int) A(n);

    int i = (n / 2) - 1;
    int j = (n / 2);

    A[i] = a;
    A[j] = b;

    bool ok = true;
    set<int> st;
    int v = n;
    i--;
    while (i >= 0)
    {
        if (v == a or v == b)
        {
            v--;
            continue;
        }
        A[i] = v--;
        if (A[i] < a)
            ok = false;
        i--;
        st.insert(A[i]);
    }
    // for (int x : A)
    //     cout << x << " ";
    // cout << endl;
    v = 1;
    i = n - 1;
    while (i > j)
    {
        if (v == a or v == b or st.count(v))
        {
            v++;
            continue;
        }

        A[i] = v++;
        if (A[i] > b)
            ok = false;
        i--;
        st.insert(A[i]);
    }
    // for (int x : A)
    //     cout << x << " ";
    // cout << endl;

    if (!ok)
    {
        cout << -1 << endl;
        return;
    }

    for (int x : A)
        cout << x << " ";
    cout << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //