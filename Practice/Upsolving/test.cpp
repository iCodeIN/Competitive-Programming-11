#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int ans = 0;
};

#include "segTree.h"

int main()
{

    int n;
    cin >> n;

    int q;
    cin >> q;

    vector<int> A(n);

    for (int &x : A)
        cin >> x;

    SegmentTree<Node> Tree(A);

    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int idx, newVal;
            cin >> idx >> newVal;

            Tree.update(idx - 1, newVal);
        }
        else
        {
            int l, r;
            cin >> l >> r;

            l -= 2;

            auto ans = Tree.query(l, r);

            cout << ans.ans << endl;
        }
    }
}