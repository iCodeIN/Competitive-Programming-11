

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
#include <map>
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

struct node
{
    int id;
    int x;
    int k;
    int ans;
};

bool comp1(node a, node b)
{
    return a.k < b.k;
}

bool comp2(node a, node b)
{
    return a.id < b.id;
}

void solve(v(int) & A, v(node) & Q)
{
    int query = 0;
    int n = A.size();
    int q = Q.size();
    int i = 0;
    while (i < q)
    {
        while (i < q and Q[i].k == query)
        {
            Q[i].ans = A[Q[i].x];
            i++;
        }

        map<int, int> mp;
        bool changed = false;

        for (int x : A)
            mp[x]++;

        for (int i = 0; i < n; i++)
        {
            changed |= (A[i] != mp[A[i]]);
            A[i] = mp[A[i]];
        }

        query++;

        if (!changed)
            break;
    }

    while (i < q)
    {
        Q[i].ans = A[Q[i].x];
        i++;
    }
}

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);

    for (int &x : A)
        cin >> x;

    int q;
    cin >> q;
    v(node) Q(q);
    for (int i = 0; i < q; i++)
    {
        cin >> Q[i].x >> Q[i].k;
        Q[i].id = i;
        Q[i].x--;
    }

    sort(all(Q), comp1);

    solve(A, Q);

    sort(all(Q), comp2);

    for (auto itr : Q)
        cout << itr.ans << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //