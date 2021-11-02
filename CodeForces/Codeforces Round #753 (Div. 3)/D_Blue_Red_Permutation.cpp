

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

    v(int) A(n);
    for (int &x : A)
        cin >> x;

    v(int) dec, inc;

    for (int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'B')
            dec.push_back(A[i]);
        else
            inc.push_back(A[i]);
    }
    sort(all(dec));
    int current = 1;
    for (int i = 0; i < dec.size(); i++)
    {
        if (current > dec[i])
        {
            cout << "NO\n";
            return;
        }
        dec[i] = current++;
    }
    sort(all(inc));
    for (int i = 0; i < inc.size(); i++)
    {
        if (current < inc[i])
        {
            cout << "NO\n";
            return;
        }
        inc[i] = current;
        current++;
    }
    cout << "YES\n";
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //