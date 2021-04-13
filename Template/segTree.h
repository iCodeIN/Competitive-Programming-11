#include <iostream>
#include <vector>
using namespace std;
#define v(Type) vector<Type>

struct SegTree
{
    v(int) t;
    int size;

    int init = 0;

    int f(int &a, int &b)
    {
        return a + b;
    }

    SegTree(v(int) & A)
    {
        size = 1;
        int n = A.size();
        while (size < n)
            size *= 2;
        t.assign(2 * size, init);
        build(A, 0, 0, size);
    }

    void build(v(int) & A, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < A.size())
                t[x] = A[lx];
            return;
        }

        int m = (lx + rx) >> 1;

        build(A, 2 * x + 1, lx, m);
        build(A, 2 * x + 2, m, rx);

        t[x] = f(t[2 * x + 1], t[2 * x + 2]);
    }

    void set(int &i, int &v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            t[x] = v;
            return;
        }

        int m = (lx + rx) >> 1;

        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);

        t[x] = f(t[2 * x + 1], t[2 * x + 2]);
    }

    int query(int &l, int &r, int x, int lx, int rx)
    {
        if (lx >= r or l >= rx)
            return init;

        if (l <= lx and rx <= r)
            return t[x];

        int m = (lx + rx) >> 1;

        int ans1 = query(l, r, 2 * x + 1, lx, m);
        int ans2 = query(l, r, 2 * x + 2, m, rx);

        return f(ans1, ans2);
    }

    void set(int &i, int &v)
    {
        set(i, v, 0, 0, size);
    }

    int query(int &l, int &r)
    {
        return query(l, r, 0, 0, size);
    }
};