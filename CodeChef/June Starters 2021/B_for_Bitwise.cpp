

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
#include <unordered_set>
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

// #define int long long int
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
    bool found = false;

    map<int, int> mp;
    for (int x : A)
        mp[x]++;
    int count = 0;
    for (auto x : mp)
        count += (x.second >= 2);
    if (count >= 2)
        found = true;
    else
    {
        int i = 0;
        for (auto x : mp)
        {
            int f = x.second;

            A[i++] = x.first;
        }

        map<int, int> F;
        n = i;
        for (int i = 0; i < n and !found; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                F[A[i] ^ A[j]]++;
                if (F[A[i] ^ A[j]] == 2)
                {
                    found = true;
                    break;
                }
            }
        }
    }
    if (found)
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