

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
    cin.tie(NULL);
// cout.tie(NULL);

#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

struct SegTree
{

    v(v(int)) A;

    SegTree(int n)
    {
        int n_ = 1;
        while (n_ <= n)
            n_ <<= 1;
        A.resize(2 * n_);
    }

    // lx rx tl tr
    // update range [lx,rx] with (x + v - lx)
    void update(int x, int lx, int rx, int tl, int tr, int v)
    {
        if (tl > tr)
            return;
        // zero intersection
        if (tl > rx or lx > tr)
            return;
        // complete interesection
        if (lx <= tl and tr <= rx)
        {
            A[x].push_back(v + tl - lx);
            return;
        }
        int m = (tl + tr) >> 1;
        update(2 * x + 1, lx, rx, tl, m, v);
        update(2 * x + 2, lx, rx, m + 1, tr, v);
    }

    int query(int x, int tl, int tr, int idx)
    {
        if (tl > tr)
            return 0;
        if (idx < tl or idx > tr)
            return 0;
        if (tl == tr)
        {
            int ans = 0;
            for (int y : A[x])
                ans += (y + idx - tl) * (y + idx - tl);
            return ans;
        }
        int ans = 0;
        if (tl <= idx and idx <= tr)
            for (int y : A[x])
                ans += (y + idx - tl) * (y + idx - tl);
        int m = (tl + tr) >> 1;
        ans += query((x << 1) + 1, tl, m, idx);
        ans += query((x << 1) + 2, m + 1, tr, idx);
        return ans;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    v(int) A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    SegTree T(n);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;

            T.update(0, l, r, 1, (int)T.A.size() / 2, x);
        }
        else
        {
            int idx;
            cin >> idx;

            cout << A[idx] + T.query(0, 1, (int)T.A.size() / 2, idx) << endl;
        }
    }
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
