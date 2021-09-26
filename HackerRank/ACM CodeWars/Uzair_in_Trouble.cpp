

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
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

struct node
{
    int s;
    int e;

    bool operator<(node b)
    {
        if (b.s != s)
            return s < b.s;
        return e < b.e;
    }
};

void solve()
{
    int n;
    cin >> n;

    v(node) A(n);

    for (auto &x : A)
        cin >> x.s >> x.e;

    sort(all(A));

    priority_queue<int, vector<int>, greater<int>> pq;

    int ans = 1;
    for (int i = 0; i < n; i++)
    {

        if (pq.size() == 0 or pq.top() > A[i].s)
        {
            pq.push(A[i].e);
        }
        else
        {
            pq.pop();
            pq.push(A[i].e);
        }
        ans = max(ans, (int)pq.size());
    }
    ans--;
    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //