

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

    v(v(char)) A(n, v(char)(n, '='));

    for (int i = 0; i < n; i++)
        A[i][i] = 'X';

    v(int) two;

    for (int i = 0; i < n; i++)
        if (s[i] == '2')
            two.push_back(i);

    if (two.size() != 0 and two.size() <= 2)
    {
        cout << "NO\n";
        return;
    }

    if (two.size())
    {
        for (int i = 0; i + 1 < two.size(); i++)
        {
            int p1 = two[i];
            int p2 = two[i + 1];

            A[p1][p2] = '+';
            A[p2][p1] = '-';
        }

        int p1 = two[0];
        int p2 = two.back();

        A[p2][p1] = '+';
        A[p1][p2] = '-';
    }

    cout << "YES" << endl;

    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < n; j++)
            cout << A[i][j];
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //