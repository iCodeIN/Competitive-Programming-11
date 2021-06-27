

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

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

struct item
{
    //
    int Min = INT32_MAX;
    int idx = INT32_MAX;
};

class SegmentTree
{
private:
    v(item) tree;
    int size;
    item neutralValue;

    item merge(item &a, item &b)
    {
        //
        item ans;
        ans.Min = min(a.Min, b.Min);
        if (a.Min < b.Min)
            ans.idx = a.idx;
        else if (a.Min == b.Min)
            ans.idx = min(a.idx, b.idx);
        else
            ans.idx = b.idx;
        return ans;
    }

    item single(int val, int idx)
    {
        //
        item ans;
        ans.Min = val;
        ans.idx = idx;
        return ans;
    }

    void init(v(int) & A)
    {
        size = 1;
        while (size < (int)A.size())
            size <<= 1;
        tree.resize(size << 1);
        build(A, 0, 0, size);
    }

    void build(v(int) & A, int x, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            if (lx < (int)A.size())
                tree[x] = single(A[lx], lx);

            return;
        }

        int mx = (lx + rx) >> 1;

        build(A, (x << 1) + 1, lx, mx);
        build(A, (x << 1) + 2, mx, rx);

        tree[x] = merge(tree[(x << 1) + 1], tree[(x << 1) + 2]);
    }

    void update(int &idx, int &val, int x, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            tree[x] = single(val, idx);
            return;
        }

        int mx = (lx + rx) >> 1ll;

        if (idx < mx)
            update(idx, val, (x << 1) + 1, lx, mx);
        else
            update(idx, val, (x << 1) + 2, mx, rx);

        tree[x] = merge(tree[(x << 1) + 1], tree[(x << 1) + 2]);
    }

    item query(int &l, int &r, int x, int lx, int rx)
    {
        if (lx >= r or l >= rx)
            return neutralValue;

        if (l <= lx and rx <= r)
            return tree[x];

        int mx = (lx + rx) >> 1;

        item ans1 = query(l, r, (x << 1) + 1, lx, mx);
        item ans2 = query(l, r, (x << 1) + 2, mx, rx);

        return merge(ans1, ans2);
    }

public:
    SegmentTree(v(int) & A)
    {
        init(A);
        return;
    }

    void update(int &idx, int &val)
    {
        update(idx, val, 0, 0, size);
        return;
    }

    item query(int &l, int &r)
    {
        return query(l, r, 0, 0, size);
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    v(int) A(n);
    for (int &x : A)
        cin >> x;
    v(int) Ans(n, 0);
    SegmentTree st(A);
    for (int s = 0, e = k; e <= n; s++, e++)
    {
        auto p = st.query(s, e);
        // cout << p.Min << ' ' << p.idx << endl;
        Ans[p.idx]++;
    }
    for (int x : Ans)
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