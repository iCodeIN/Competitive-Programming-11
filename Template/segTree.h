#include <vector>
#include <iostream>
using namespace std;

#define v(type) vector<type>
#define int long long

struct Node
{
    //

    Node()
    {
    }
};

class SegmentTree
{
private:
    v(Node) tree;
    int size;
    //
    Node neutralValue;

    Node merge(Node &a, Node &b)
    {
        Node ans;
        //
        return ans;
    }

    void build(v(int) & A, int x, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            if (lx < (int)A.size())
            {
                Node temp;
                //
                tree[x] = temp;
            }
            return;
        }

        int mx = (lx + rx) >> 1ll;
        build(A, (x << 1ll) + 1ll, lx, mx);
        build(A, (x << 1ll) + 2ll, mx, rx);
        tree[x] = merge(tree[(x << 1ll) + 1ll], tree[(x << 1ll) + 2ll]);
    }

    void update(int idx, int val, int x, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            Node temp;
            //
            tree[x] = temp;
            return;
        }

        int mx = (lx + rx) >> 1ll;

        if (idx < mx)
            update(idx, val, (x << 1ll) + 1ll, lx, mx);
        else
            update(idx, val, (x << 1ll) + 2ll, mx, rx);

        tree[x] = merge(tree[(x << 1ll) + 1ll], tree[(x << 1ll) + 2ll]);
    }

    Node query(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r or l >= rx)
            return neutralValue;

        if (rx - lx == 1)
            return tree[x];

        int mx = (lx + rx) >> 1ll;
        Node ans1 = query(l, r, (x << 1ll) + 1ll, lx, mx);
        Node ans2 = query(l, r, (x << 1ll) + 2ll, mx, rx);
        Node ans = merge(ans1, ans2);
        return ans;
    }

public:
    SegmentTree(v(int) & A)
    {
        size = 1;
        while (size < (int)A.size())
            size <<= 1;
        tree.assign(size << 1ll, neutralValue);
        build(A, 0, 0, size);
    }

    void update(int idx, int val)
    {
        update(idx, val, 0, 0, size);
    }

    Node query(int l, int r)
    {
        return query(l, r, 0, 0, size);
    }
};
