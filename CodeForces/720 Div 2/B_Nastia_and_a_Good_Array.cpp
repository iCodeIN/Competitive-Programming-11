

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
int p1 = 1000000007, p2 = 1000000009, p3 = 1000000021;
void solve()
{
    int n;
    cin >> n;
    v(int) A(n);
    for (int &x : A)
        cin >> x;
    cout << n - 1 << endl;
    int cur = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int p;
        if (cur == 0)
            p = p1;
        else if (cur == 1)
            p = p2;
        else
            p = p3;
        cout << i + 1 << " " << i + 2 << " ";
        if (A[i] < A[i + 1])
        {
            cout << A[i] << " " << p << endl;
            A[i + 1] = p;
        }
        else
        {
            cout << p << " " << A[i + 1] << endl;
            A[i] = p;
        }
        cur++;
        cur %= 3;
    }
    // for (int i = 0; i < n; i++)
    //     cout << A[i] << " ";
    // cout << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //