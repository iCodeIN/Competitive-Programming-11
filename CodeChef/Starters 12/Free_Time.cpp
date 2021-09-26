

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
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

struct interval
{
    int s;
    int e;
};

bool operator<(interval &a, interval &b)
{
    if (a.s != b.s)
        return a.s < b.s;

    return a.e < b.e;
}

int intersection(interval a, interval b)
{

    if (a.s > b.s)
        return intersection(b, a);

    if (b.s >= a.e)
        return 0;

    return min(a.e, b.e) - b.s;
}

void solve()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    v(interval) A(n), B(m);

    for (interval &x : A)
        cin >> x.s >> x.e;

    for (interval &x : B)
        cin >> x.s >> x.e;

    sort(all(A));
    sort(all(B));

    int i = 0;
    int j = 0;

    int ans = 0;
    
    while (i < n and j < m)
    {
        int current = intersection(A[i], B[j]);

        int m = min(A[i].e, B[j].e);

        i += (m == A[i].e);
        j += (m == B[j].e);

        ans += current;
    }

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