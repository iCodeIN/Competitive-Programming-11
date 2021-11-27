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

#define pii pair<int, int>
#define ff first
#define ss second

#define int long long
#define mod 1000000007ll
#define endl "\n"
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
struct node
{
    int f;
    int i;
    bool operator<(node b)
    {
        return f > b.f;
    }
};
void solve()
{
    int n;
    cin >> n;

    vector<node> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i].f;
        A[i].i = i;
    }

    sort(all(A));
    v(int) Ans(n);
    int a = 1;
    int b = -1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            Ans[A[i].i] = a++;
        else
            Ans[A[i].i] = b--;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += A[i].f * abs(Ans[A[i].i]) * 2;
    }
    cout << ans << endl;
    cout << 0 << " ";
    for (int i = 0; i < n; i++)
        cout << Ans[i] << " ";
    cout << endl;
}
int32_t main()
{
    FastIO;

    w(T)
    {
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //