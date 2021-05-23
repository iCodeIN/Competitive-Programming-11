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

void solve(v(int) & A, vector<pair<int, int>> &t, int i, int cur, int g, int day)
{
    while (i < 10)
    {
        if (A[i] <= cur)
        {
            if (t[i].first == -1)
                t[i].first = day;
            t[i].second = day;
            cur -= A[i];
        }
        else
        {
            if (cur == 0)
            {
                solve(A, t, i, g, g, day + 1);
                break;
            }
            else if (cur != g)
            {
                if (t[i].first == -1)
                    t[i].first = day;
                A[i] -= cur;
                cur = 0;
                solve(A, t, i, g, g, day + 1);
                break;
            }
            else
            {
                int d_req = (A[i] / g);
                day += d_req;
                A[i] -= (A[i] / g) * g;
                solve(A, t, i, g, g, day + 1);
                break;
            }
        }
        i++;
    }
}

void solve()
{
    int g, p;
    cin >> g >> p;

    v(int) A(10);

    for (int i = 0; i <= 9; i++)
        cin >> A[i];

    vector<pair<int, int>> t(10, {-1, -1});

    int day = 1;

    solve(A, t, 0, p, p, 1);

    cout << t[g - 1].first << " " << t[g - 1].second << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //