

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

    stack<int> s1, s2;
    v(int) sm(n), lg(n);
    int ans = 0;
    int prev = -1;
    for (int i = 0; i < n; i++)
    {

        while (s1.size() > 0 and A[s1.top()] > A[i])
            s1.pop();

        while (s2.size() > 0 and A[s2.top()] < A[i])
            s2.pop();

        int ans1 = i - prev;
        int ans2 = i - prev;

        if (s1.size())
        {
            sm[i] = s1.top();
        }
        else
        {
            sm[i] = -1;
        }

        if (s2.size())
        {
            lg[i] = s2.top();
        }
        else
        {
            lg[i] = -1;
        }

        if (sm[i] != -1 and sm[sm[i]] != -1)
        {
            ans1 = i - sm[sm[i]];
            prev = max(prev, sm[sm[i]]);
        }

        if (lg[i] != -1 and lg[lg[i]] != -1)
        {
            ans2 = i - lg[lg[i]];
            prev = max(prev, lg[lg[i]]);
        }
        ans1 = min(ans1, ans2);
        ans += ans1;
        s1.push(i);
        s2.push(i);
        cout << sm[i] << ' ' << lg[i] << "\n";
        // cout << ans << " " << prev << endl;
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