

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
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

struct node
{
    int s;
    int e;
};

void solve()
{
    int n, k, f;
    cin >> n >> k >> f;

    v(node) A(n);

    for (auto &x : A)
        cin >> x.s >> x.e;
    A.push_back({0, 0});
    A.push_back({f, f});
    sort(all(A), [](node &a, node &b)
         {
             if (a.s != b.s)
                 return a.s < b.s;
             return a.e < b.e;
         });
    int mx_time = 0;
    int curMax = 0;
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i].s >= A[i - 1].e)
        {
            mx_time += A[i].s - A[i - 1].e;
        }
        else
        {
            A[i].e = max(curMax, A[i].e);
        }
        curMax = A[i].e;
    }

    bool ans = (mx_time >= k);

    if (ans)
        cout << "YES";
    else
        cout << "NO";
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