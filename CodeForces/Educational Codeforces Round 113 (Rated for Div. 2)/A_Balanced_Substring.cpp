

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

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    v(int) A(n);
    A[0] = s[0] == 'a';

    for (int i = 1; i < n; i++)
        A[i] += A[i - 1] + (s[i] == 'a');

    bool found = false;
    for (int l = 0; l < n; l++)
        for (int r = l + 1; r < n; r++)
        {

            int fa = A[r] - A[l] + (s[l] == 'a');
            int fb = (r - l + 1) - fa;

            if (fa == fb)
                cout << l + 1 << ' ' << r + 1 << endl, found = true;

            if (found)
                return;
        }

        cout << -1 << ' ' << -1 << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //