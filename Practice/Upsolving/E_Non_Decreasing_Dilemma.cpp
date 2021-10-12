

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

struct Node
{
    int first = INT32_MAX;
    int last = INT32_MIN;
    int size = 0;
    int left_travel = 0;
    int right_travel = 0;
    int ans = 0;

    bool operator==(Node x)
    {
        return x.first == first and x.last == last and x.size == size and left_travel == x.left_travel and x.right_travel == right_travel and x.ans == ans;
    }
};

template <typename T>
class SegmentTree
{
public:
    vector<T> tree;
    T neutralValue;

    SegmentTree(vector<int> &A)
    {
        int sizeOfArray = A.size();

        int sizeOfTree = 1;

        while (sizeOfTree < sizeOfArray)
            sizeOfTree <<= 1;

        sizeOfTree <<= 1;

        tree.assign(sizeOfTree, neutralValue);

        build(0, -1, sizeOfTree >> 1, A);
    }

    T single(int val)
    {
        T ans;

        //
        //
        //
        ans.size = 1;
        ans.ans = 1;
        ans.left_travel = 1;
        ans.right_travel = 1;
        ans.first = ans.last = val;
        return ans;
    }

    T merge(T leftAns, T rightAns)
    {
        T ans;
        if (leftAns == neutralValue)
            return rightAns;

        if (rightAns == neutralValue)
            return leftAns;

        //
        //
        //
        ans.size = leftAns.size + rightAns.size;
        ans.first = leftAns.first;
        ans.last = rightAns.last;
        ans.ans = (leftAns.last <= rightAns.first) ? leftAns.left_travel * rightAns.right_travel : 0;

        ans.ans += leftAns.ans + rightAns.ans;

        ans.right_travel = (leftAns.right_travel == leftAns.size and leftAns.last <= rightAns.first) ? leftAns.right_travel + rightAns.right_travel : leftAns.right_travel;

        ans.left_travel = (rightAns.left_travel == rightAns.size and leftAns.last <= rightAns.first) ? leftAns.left_travel + rightAns.left_travel : rightAns.left_travel;

        return ans;
    }

    T build(int idx_tree, int l_tree, int r_tree, vector<int> &A)
    {
        // no element
        if (r_tree - l_tree <= 1)
            return neutralValue;

        // single element
        if (r_tree - l_tree == 2)
        {
            tree[idx_tree] = (l_tree + 1 < A.size()) ? single(A[l_tree + 1]) : neutralValue;

            return tree[idx_tree];
        }

        // more than one element
        int m = (l_tree + r_tree) >> 1;
        T leftAns = build(2 * idx_tree + 1, l_tree, m + 1, A);
        T rightAns = build(2 * idx_tree + 2, m, r_tree, A);

        tree[idx_tree] = merge(leftAns, rightAns);

        return tree[idx_tree];
    }

    T update(int idx_tree, int l_tree, int r_tree, int newVal, int idx_arr)
    {

        // no element
        if (r_tree - l_tree <= 1)
            return neutralValue;

        //  in incorrect range
        if (!(l_tree < idx_arr and idx_arr < r_tree))
            return tree[idx_tree];

        // single element
        if (r_tree - l_tree == 2)
        {
            tree[idx_tree] = single(newVal);
            return tree[idx_tree];
        }

        // more than one element
        int m = (l_tree + r_tree) >> 1;
        T leftAns = update(2 * idx_tree + 1, l_tree, m + 1, newVal, idx_arr);
        T rightAns = update(2 * idx_tree + 2, m, r_tree, newVal, idx_arr);
        tree[idx_tree] = merge(leftAns, rightAns);
        return tree[idx_tree];
    }

    T query(int idx_tree, int l_tree, int r_tree, int l_query, int r_query)
    {

        bool ol = check(l_tree + 1, r_tree - 1, l_query + 1, r_query - 1);

        // no overlap
        if (!ol)
            return neutralValue;

        // no element
        if (r_tree - l_tree <= 1)
            return neutralValue;

        // complete overlap
        if (l_query <= l_tree and r_tree <= r_query)
            return tree[idx_tree];

        // partial overlap
        int m = (l_tree + r_tree) >> 1;
        T leftAns = query(2 * idx_tree + 1, l_tree, m + 1, l_query, r_query);
        T rightAns = query(2 * idx_tree + 2, m, r_tree, l_query, r_query);

        return merge(leftAns, rightAns);
    }

    void update(int idx, int newVal)
    {
        update(0, -1, tree.size() >> 1, newVal, idx);
    }

    T query(int l, int r)
    {
        return query(0, -1, tree.size() >> 1, l, r);
    }

    void print()
    {
        for (auto x : tree)
        {
            cout << x.ans << " ";
        }
        cout << endl;
    }

    bool check(int l1, int r1, int l2, int r2)
    {
        if (l2 < l1)
            return check(l2, r2, l1, r1);

        return r1 >= l2;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    v(int) A(n);

    for (int &x : A)
        cin >> x;

    SegmentTree<Node> tree(A);

    while (q--)
    {
        int op;

        cin >> op;

        if (op == 1)
        {
            int idx, val;
            cin >> idx >> val;

            tree.update(idx - 1, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;

            l -= 2;

            auto ans = tree.query(l, r);

            cout << ans.ans << endl;
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