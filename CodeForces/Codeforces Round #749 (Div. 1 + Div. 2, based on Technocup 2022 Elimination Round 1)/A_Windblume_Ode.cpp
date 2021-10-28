

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

struct node
{
    int v;
    int id;
};

bool comp1(node a, node b)
{
    return a.v < b.v;
}

bool isPrime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

void solve()
{
    int n;
    cin >> n;
    v(node) odd, even;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        node cur;
        cin >> cur.v;
        cur.id = i + 1;
        sum += cur.v;

        if (cur.v & 1)
            odd.push_back(cur);

        else
            even.push_back(cur);
    }

    sort(all(odd), comp1);

    if (!isPrime(sum))
    {
        cout << n << endl;
        for (int i = 0; i < n; i++)
            cout << i + 1 << " ";
    }
    else
    {
        cout << n - 1 << endl;
        for (int i = 0; i < n; i++)
        {
            if (i + 1 != odd[0].id)
                cout << i + 1 << " ";
        }
    }
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