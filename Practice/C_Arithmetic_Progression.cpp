

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
#include <map>
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
    sort(all(A));

    map<int, int> mp;

    for (int i = 1; i < n; i++)
        mp[A[i] - A[i - 1]]++;

    if (mp.size() > 2)
        cout << 0;
    else if (mp.size() == 2)
    {
        auto b = mp.begin();
        b++;
        auto a = mp.begin();
        if (b->first != 2 * a->first or b->second != 1)
            cout << 0;
        else
        {
            int d = a->first;
            cout << 1 << endl;
            for (int i = 1; i < n; i++)
                if (A[i] - A[i - 1] != d)
                    cout << A[i - 1] + d << endl;
        }
    }
    else if (mp.size() == 1)
    {
        int d = mp.begin()->first;

        if (d == 0)
        {
            cout << 1 << endl;
            cout << A[0] << endl;
        }
        else if (n == 2)
        {
            cout << 2 + (d % 2 == 0) << endl;
            cout << A[0] - d << " ";
            if (d % 2 == 0)
                cout << A[0] + d / 2 << " ";
            cout << A[0] + 2 * d << endl;
        }
        else
        {
            cout << 2 << endl;
            cout << A[0] - d << " " << A[n - 1] + d << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //