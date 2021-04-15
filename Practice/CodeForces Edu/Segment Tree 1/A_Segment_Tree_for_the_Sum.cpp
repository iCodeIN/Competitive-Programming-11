
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
// #include <cmath>
// #include <algorithm>
// #include <unordered_map>
// #include <map>
// #include <set>
// #include <unordered_set>
//------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define v(Type) vector<Type>
#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)
// #define int long long int
#define mod 1000000007ll
#define endl "\n"

struct Node
{
    int val = 0;
};

struct SegmentTree
{
private:
    v(Node) tree;
    int size;
    Node neutralValue;
    Node base;

    Node merge(Node &a, Node &b)
    {
        Node ans;
        ans.val = a.val + b.val;
        return ans;
    }

    void build(v(int) & A, int x, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            if (lx < A.size())
            {
                base.val = A[lx];
                tree[x] = base;
            }
            return;
        }

        int mx = (lx + rx) >> 1;
        build(A, (2 * x) + 1, lx, mx);
        build(A, (2 * x) + 2, mx, rx);

        tree[x] = merge(tree[(2 * x) + 1], tree[(2 * x) + 2]);
    }

    void update(int &idx, int &val, int x, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            base.val = val;
            tree[x] = base;
            return;
        }

        int mx = (lx + rx) >> 1;

        if (idx < mx)
            update(idx, val, (2 * x) + 1, lx, mx);
        else
            update(idx, val, (2 * x) + 2, mx, rx);

        tree[x] = merge(tree[(2 * x) + 1], tree[(2 * x) + 2]);
    }

    Node query(int &l, int &r, int x, int lx, int rx)
    {
        if (lx >= r or l >= rx)
            return neutralValue;

        if (rx - lx == 1)
            return tree[x];

        int mx = (lx + rx) >> 1;
        Node ans1 = query(l, r, 2 * x + 1, lx, mx);
        Node ans2 = query(l, r, 2 * x + 2, mx, rx);
        Node ans = merge(ans1, ans2);
        return ans;
    }

public:
    SegmentTree(v(int) & A)
    {
        size = 1;
        int n = A.size();
        while (size < n)
            size *= 2;
        tree.assign((2 * size) + 1, neutralValue);
        build(A, 0, 0, size);
    }

    void update(int &idx, int &val)
    {
        update(idx, val, 0, 0, size);
    }

    Node query(int &l, int &r)
    {
        return query(l, r, 0, 0, size);
    }
};

//------------------------------------------------------------------------------
void solve()
{
    int n, q;
    cin >> n >> q;
    v(int) A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    SegmentTree st(A);
    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int i, v;
            cin >> i >> v;
            st.update(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            Node ans = st.query(l, r);
            cout << ans.val << endl;
        }
    }
}
//------------------------------------------------------------------------------
int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}
//------------------------------------------------------------------------------
