#include <vector>
#include <iostream>
using namespace std;

#define v(type) vector<type>
#define int long long

struct item
{
    //
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
    }

    item single(int val)
    {
        //
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
                tree[x] = single(A[lx]);

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
            tree[x] = single(val);
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
