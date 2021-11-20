

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
#include <map>
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

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);

    map<int, int> mp;
    for (int &x : A)
    {
        cin >> x;
        mp[x]++;
    }

    sort(all(A));

    bool ans = mp[A[n - 1]] == 1;

    if (ans)
    {
        for (auto e : mp)
        {
            ans &= e.second <= 2;
        }
    }

    if (!ans)
        cout << -1;
    else
    {
        stack<int> st;
        for (auto e : mp)
        {
            st.push(e.first);
            if (e.second == 2)
                cout << e.first << " ";
        }

        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }

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