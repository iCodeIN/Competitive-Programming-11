

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
    int l;
    int r;
    int amount;
};

bool overlapping(node &a, node &b)
{
    if (a.r < b.l)
        return false;
    return true;
}

void solve()
{
    int n;
    cin >> n;

    v(node) A(n);
    for (node &x : A)
        cin >> x.l >> x.r >> x.amount;
    sort(A.begin(), A.end(), [](const node &a, const node &b)
         {
             if (a.l == b.l)
             {
                 return a.r < b.r;
             }
             return a.l < b.l;
         });
    int ans = 0;
    for (int i = 0; i < n;)
    {
        int cur = A[i].amount;
        int j = i + 1;
        while (j < n and overlapping(A[i], A[j]))
        {
            cur = max(cur, A[j].amount);
            j++;
        }
        i = j;
        ans += cur;
    }
    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //