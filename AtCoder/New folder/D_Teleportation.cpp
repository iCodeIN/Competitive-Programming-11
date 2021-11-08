

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
#include <set>
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

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);

    set<pair<int, int>> st;
    for (auto &p : A)
        cin >> p.first >> p.second;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
            {
                int a = abs(A[i].first - A[j].first);
                int b = abs(A[i].second - A[j].second);

                while (true)
                {
                    int g = gcd(a, b);
                    a /= g;
                    b /= g;
                    if (g == 1)
                        break;
                }

                if (A[i].first < A[j].first)
                    a = -a;
                if (A[i].second < A[j].second)
                    b = -b;

                st.insert({a, b});
            }

    cout << st.size() << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //