

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
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

    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    map<int, int> mp;
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        mp[A[i]]++;
        if (mp[A[i]] == 2)
            ans = true;
    }

    if (!ans)
    {

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (mp.count(A[i] - A[j]) or mp.count(A[j] - A[i]))
                    ans = true;
    }

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