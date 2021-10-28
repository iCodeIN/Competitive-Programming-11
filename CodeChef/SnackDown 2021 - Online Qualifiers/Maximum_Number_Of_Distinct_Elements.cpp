

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
#include <set>
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
    int v;
    int id;
    int ans;
};

bool comp1(node a, node b)
{
    return a.v > b.v;
}

bool comp2(node a, node b)
{
    return a.id < b.id;
}

void solve()
{
    int n;
    cin >> n;

    v(node) A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i].v;
        A[i].id = i;
    }

    sort(all(A), comp1);
    set<int> st;
    for (int i = 0; i < A[0].v; i++)
        st.insert(i);

    int any = 1e9;
    for (int i = 0; i < n; i++)
    {

        auto itr = st.upper_bound(A[i].v - 1);
        if (itr != st.begin())
        {
            itr--;
            A[i].ans = *itr;
            st.erase(itr);
        }
        else
        {
            A[i].ans = any;
        }
    }

    sort(all(A), comp2);
    for (auto &x : A)
        cout << x.ans << " ";
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