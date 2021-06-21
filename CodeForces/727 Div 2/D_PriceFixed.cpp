

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

struct Node
{
    int a;
    int b;
};

void solve()

{
    int n;
    cin >> n;
    v(Node) A(n);
    for (Node &x : A)
        cin >> x.a >> x.b;

    sort(
        A.begin(), A.end(), [](const Node x, const Node y)
        {
            if (x.b != y.b)
                return x.b < y.b;
            return x.a > y.a;
        });

    // for(int i = 0;i < n;i++){
    //     cout << A[i].a << " " << A[i].b << endl;
    // }
    int i = 0;
    int j = n - 1;

    int cur = 0;
    int ans = 0;

    while (i <= n - 1)
    {
        if (cur < A[i].b)
        {
            int req = A[i].b - cur;

            while (j >= i and req > 0)
            {
                if (A[j].a >= req)
                {
                    ans += (req)*2;
                    cur += req;
                    A[j].a -= req;
                    req = 0;
                }
                else
                {
                    ans += (A[j].a) * 2;
                    cur += A[j].a;
                    req -= A[j].a;
                    A[j].a = 0;
                }
                if (A[j].a == 0)
                    j--;
            }
            // cout << ans << " ";
        }
        if (cur >= A[i].b)
            ans += (A[i].a);
        else
            ans += (A[i].a) * 2;

        cur += A[i].a;
        A[i].a = 0;
        // cout << ans << "\n";
        i++;
    }
    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //