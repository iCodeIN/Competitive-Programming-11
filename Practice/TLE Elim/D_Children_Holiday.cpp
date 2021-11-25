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

#define pair <int, int> pii
#define ff first
#define ss second

#define int long long
#define mod 1000000007ll
#define endl "\n"
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

struct node
{
    int t;
    int x;
    int y;
};

// returns maxNo of ballons A[i] can inflate in timeInHand minutes O(1)
int f(v(node) & A, int i, int timeInHand)
{
    int l = 0;
    int r = 1e6;

    while (r - l > 1)
    {

        int m = l + (r - l) / 2;

        if (m * A[i].t + ((m - 1) / A[i].x) * A[i].y <= timeInHand)
            l = m;
        else
            r = m;
    }
    return l;
}

bool good(v(node) & A, int total, int timeInHand) 
{
    int count = 0;
    int n = A.size();
    for (int i = 0; i < n; i++)
        count += f(A, i, timeInHand);
    return count >= total;
}

void solve()
{
    int m;
    cin >> m;

    int n;
    cin >> n;

    v(node) A(n);

    for (auto &itr : A)
        cin >> itr.t >> itr.x >> itr.y;

    int l = -1;
    int r = 1e18;

    while (r - l > 1)
    {
        int mid = l + (r - l) / 2;

        if (good(A, m, mid))
            r = mid;
        else
            l = mid;
    }

    int minTime = r;
    cout << minTime << endl;

    int rem = m;
    for (int i = 0; i < n; i++)
    {
        int cur = f(A, i, r);
        cur = min(cur, rem);
        cout << cur << " ";
        rem -= cur;
    }
    cout << endl;
}


int32_t main()
{
    FastIO;

    // w(T)
    {
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //