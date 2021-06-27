

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

#define debug(a, b) cout << #a << ": " << a << ", " << #b << ": " << b << endl;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

struct node
{
    int x;
    int y;
};

void solve()
{
    int n, h;
    cin >> n >> h;
    v(node) A(n);
    for (node &p : A)
        cin >> p.x;
    for (node &p : A)
        cin >> p.y;

    bool possible = true;
    for (node &p : A)
        possible &= (p.x + h > p.y);

    if (!possible)
        cout << -1;
    else
    {

        int min_moves = 0;
        for (node p : A)
        {
            int t = p.x;
            int j = (p.y - h + p.x);
            if (j & 1)
                j = j / 2 + 1;
            else
                j /= 2;
            min_moves = max(min_moves, j);
        }
        // min_moves /= 2;
        cout << min_moves;
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