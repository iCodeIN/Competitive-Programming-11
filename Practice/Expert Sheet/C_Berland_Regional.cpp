

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

void solve()
{
    int n;
    cin >> n;

    v(int) A(n), B(n);
    for (int &x : A)
        cin >> x;
    for (int &x : B)
        cin >> x;

    v(v(int)) C(n + 1); // university -> skills
    for (int i = 0; i < n; i++)
    {
        int u = A[i];
        int s = B[i];
        C[u].push_back(s);
    }

    for (int i = 1; i <= n; i++)
    {
        if (C[i].size())
        {
            sort(C[i].begin(), C[i].end(), greater<int>());
            for (int j = 1; j < C[i].size(); j++)
            {
                C[i][j] += C[i][j - 1];
            }
        }
    }
    v(int) Ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= C[i].size(); k++)
        {
            int idx = (C[i].size() / k) * k;
            Ans[k] += C[i][idx - 1];
        }

    for (int i = 1; i <= n; i++)
        cout << Ans[i] << " ";
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