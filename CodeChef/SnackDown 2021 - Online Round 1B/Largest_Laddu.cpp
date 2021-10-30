

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <set>
#include <queue>
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
    int n;
    cin >> n;
    n = (1 << n);
    priority_queue<int> pq1, pq2;

    int cur = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq1.push(x);
    }

    int size = n;

    while (size > 1)
    {

        priority_queue<int> &pqCurrent = (cur == 0) ? pq1 : pq2;
        priority_queue<int> &pqNext = (cur == 0) ? pq2 : pq1;

        while (pqCurrent.size() >= 2)
        {
            int a = pqCurrent.top();
            pqCurrent.pop();
            int b = pqCurrent.top();
            pqCurrent.pop();

            if (abs(a - b) > 1)
            {
                cout << "NO\n";
                return;
            }
            pqNext.push(a + b);
        }
        cur ^= 1;
        size >>= 1;
    }
    cout << "YES\n";
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //