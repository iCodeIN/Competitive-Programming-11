

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
int f(v(int) & A)
{
    int c1 = 0;
    int c2 = 0;
    int n = A.size();
    for (int i = 0; i < n and A[i] == A[0]; i++)
    {
        c1++;
    }
    c2 = n - c1;
    return c1 * c2;
}

void solve()
{
    int n;
    cin >> n;
    v(int) A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int sum = 0;
    for (int x : A)
        sum += x;

    int s = sum / n;
    for (int &x : A)
        x = s;
    for (int i = n - 1, j = 1; j <= sum % n; j++, i--)
        A[i]++;

    int ans = f(A);
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