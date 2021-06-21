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

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

void solve()
{
    int m, n;
    cin >> m >> n;

    v(v(int)) A(m, v(int)(n));
    for (auto x : A)
        for (int &p : x)
            cin >> p;
    int count1 = 0;
    for (int i = 0; i < m; i++)
    {
        int cur = 0;
        for (int j = 0; j < n; j++)
        {
            cur ^= A[i][j];
        }
        count1 += (cur == 1);
    }

    int count2 = 0;
    for (int j = 0; j < n; j++)
    {
        int cur = 0;
        for (int i = 0; i < m; i++)
        {
            cur ^= A[i][j];
        }
        count2 += (cur == 1);
    }
    bool ans = (count1 & 1) or (count2 & 1);

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