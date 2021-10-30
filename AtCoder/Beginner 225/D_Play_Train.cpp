

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
    int n, q;
    cin >> n >> q;

    v(int) Front(n + 1, -1), Rear(n + 1, -1);
    v(int) frontAns(n + 1), rearAns(n + 1);
    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int x, y;
            cin >> x >> y;

            Rear[x] = y;
            Front[y] = x;
        }
        else if (op == 2)
        {
            int x, y;
            cin >> x >> y;
            Front[Rear[x]] = -1;
            Rear[x] = -1;
        }
        else
        {
            int x;
            cin >> x;
            int i = 0;
            int j = 0;
            int current = x;
            while (current != -1)
            {
                rearAns[i++] = current;
                current = Rear[current];
            }
            current = Front[x];
            while (current != -1)
            {
                frontAns[j++] = current;
                current = Front[current];
            }
            cout << i + j << " ";
            j--;
            while (j >= 0)
                cout << frontAns[j--] << " ";
            j = 0;
            while (j < i)
                cout << rearAns[j++] << " ";

            cout << endl;
        }
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