

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

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int f(int n, int a, int b)
{
    return (a * n) + b;
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    v(int) A;

    for (int i = 0; i < n; i++)
    {
        int c = 0;
        int j = i;
        while (j < n and s[j] == s[i])
            j++, c++;

        i = j - 1;
        A.push_back(c);
    }

    int ans1 = n * (a + b);
    int ans2 = ans1;
    n = A.size();

    for (int start = 0; start < n; start++)
    {
        int i = start - 1;
        int j = start + 1;
        int cur = f(A[start], a, b);
        while (i >= 0 or j < n)
        {
            int l = (i >= 0) ? A[i--] : 0;
            int r = (j < n) ? A[j++] : 0;

            cur += f(l + r, a, b);
        }
        ans2 = max(ans2, cur);
    }
    // cout << ans1 << " " << ans2 << " ";
    cout << max(ans1, ans2) << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //