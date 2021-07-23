

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
    int val;
    int idx;
    int ans = 0;
};

void solve()
{
    int n, k;
    cin >> n >> k;

    map<int, int> mp;
    v(node) A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].val;
        A[i].idx = i;
    }

    sort(A.begin(), A.end(), [](node a, node b)
         { return a.val < b.val; });
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int c_ = 0;
        while (j < n and A[j].val == A[i].val)
        {
            if (c_ < k)
            {
                A[j].ans = (c % k == 0) ? k : (c % k);
                c++;
                c_++;
                mp[A[j].ans]++;
            }
            j++;
        }
        i = j - 1;
    }
    int minF = INT32_MAX;
    for (auto x : mp)
    {
        minF = min(minF, x.second);
    }

    for (int i = 0; i < n; i++)
    {
        if (mp[A[i].ans] > minF)
        {
            mp[A[i].ans]--;
            A[i].ans = 0;
        }
    }
    sort(A.begin(), A.end(), [](node a, node b)
         { return a.idx < b.idx; });

    for (auto x : A)
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