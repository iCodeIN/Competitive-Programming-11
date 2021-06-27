

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

void insert(int row, int idx1, int idx2, v(v(int)) & A)
{
    bool found = false;
    for (int y : A[row])
        if (y == idx1 or y == idx2)
            found = true;
    if (!found)
    {
        A[row].push_back(idx1);
        A[row].push_back(idx2);
    }
}

void solve()
{
    int n;
    cin >> n;
    v(int) A(n);
    for (int &x : A)
        cin >> x;
    bool found = false;
    v(v(int)) Indices(1 << 17);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = A[i] ^ A[j];
            insert(x, i, j, Indices);
            found = (int)Indices[x].size() >= 4;
            if (found)
                break;
        }
        if (found)
            break;
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