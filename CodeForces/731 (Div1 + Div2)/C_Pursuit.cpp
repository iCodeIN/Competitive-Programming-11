

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
int score(v(int) & A, int m, bool max)
{
    int n = A.size();
    int k = m - (m / 4);
    if (max)
    {
        int ans = 0;
        if (m >= n)
        {
            if (m - n >= k)
                ans = k * 100;
            else
                ans = ((m - n) * 100) + A[(k - m + n - 1)];
        }
        else
            ans = A[k - 1];
        return ans;
    }
    else
    {
        return A[min(k - 1, n - 1)];
    }
}

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);
    v(int) B(n);

    for (int &x : A)
        cin >> x;
    for (int &x : B)
        cin >> x;

    sort(all(A), greater<int>());
    sort(all(B), greater<int>());

    for (int i = 1; i < n; i++)
        A[i] += A[i - 1];
    for (int i = 1; i < n; i++)
        B[i] += B[i - 1];

    int ans = 0;

    int l = n - 1;
    int r = 1000000000;

    while (r - l > 1)
    {
        int m = (l + r) >> 1;

        int s1 = score(A, m, 1);
        int s2 = score(B, m, 0);

        if (s1 >= s2)
            r = m;
        else
            l = m;
        // cout << s1 << " " << s2 << " " << r << endl;
    }
    ans = r - n;

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //