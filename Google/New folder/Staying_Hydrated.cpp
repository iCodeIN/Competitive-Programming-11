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
struct rectangle
{
    int x1;
    int y1;
    int x2;
    int y2;
};

int f(rectangle r, int x, int y)
{

    if (r.x1 <= x and x <= r.x2 and r.y1 <= y and y <= r.y2)
        return 0;
    int ans1 = min(abs(r.y1 - y), abs(r.y2 - y));

    if (r.x1 <= x and x <= r.x2)
    {
    }
    else
    {
        ans1 += min(abs(r.x1 - x), abs(r.x2 - x));
    }

    int ans2 = min(abs(r.x1 - x), abs(r.x2 - x));

    if (r.y1 <= y and y <= r.y2)
    {
    }
    else
    {
        ans2 += min(abs(r.y1 - y), abs(r.y2 - y));
    }

    return min(ans1, ans2);
}

void solve()
{
    int n;
    cin >> n;

    v(rectangle) A(n);
    for (auto &p : A)
        cin >> p.x1 >> p.y1 >> p.x2 >> p.y2;

    int minDist = 1e18;
    int ans_x, ans_y;

    for (int x = -100; x <= 100; x++)
    {
        for (int y = -100; y <= 100; y++)
        {
            int curDist = 0;

            for (int i = 0; i < n; i++)
            {
                curDist += f(A[i], x, y);
            }

            if (curDist < minDist)
            {
                ans_x = x;
                ans_y = y;
                minDist = curDist;
            }
        }
    }
    cout << ans_x << ' ' << ans_y << endl;
}

int32_t main()
{
    FastIO;
    int test = 1;
    w(T)
    {
        cout << "Case #" << test++ << ": ";
        solve();
    }
    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //