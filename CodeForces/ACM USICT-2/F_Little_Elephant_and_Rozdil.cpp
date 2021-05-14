

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
    int val;
    int idx;
};
void solve()
{
    int n;
    cin >> n;
    v(node) A(n);
    int i = 1;
    for (auto &x : A)
    {
        cin >> x.val;
        x.idx = i++;
    }
    bool ans = (n == 1);
    if (n > 1)
    {
        sort(A.begin(), A.end(), [](node &a, node &b)
             {
                 if (a.val != b.val)
                     return a.val < b.val;
                 return a.idx < b.idx;
             });
        ans = (A[0].val != A[1].val);
    }

    if (ans)
        cout << A[0].idx << endl;
    else
        cout << "Still Rozdil" << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //