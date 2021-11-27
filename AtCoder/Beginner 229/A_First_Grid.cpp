// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
// #include <algorithm>
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

#define pair <int, int> pii
#define ff first
#define ss second

#define int long long
#define mod 1000000007ll
#define endl "\n"
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
void solve()
{
    char A[2][3];

    for (int i = 0; i < 2; i++)
        cin >> A[i];

    bool ans = true;

    int c = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            c += (A[i][j] == '#');

    if (c <= 2)
    {
        if (c == 1)
            ans = false;
        else
        {
            if (A[0][0] == '#' and A[1][1] == '#')
                ans = false;
            else if (A[1][0] == '#' and A[0][1] == '#')
                ans = false;
        }
    }
    if (ans)
        cout << "Yes";
    else
        cout << "No";
    cout << endl;
}
int32_t main()
{
    FastIO;

    // w(T)
    {
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //