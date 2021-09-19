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
    int s;
    int e;
    int h;
};
bool comp(node a, node b)
{
    return a.h > b.h;
}

void solve()
{
    int d, n, k;
    cin >> d >> n >> k;

    v(node) A(n);

    for (node &x : A)
        cin >> x.h >> x.s >> x.e;

    sort(A.begin(), A.end(), comp);

    v(int) H1(d + 2, 0), H2(d + 2, 0), count1(d + 2, 0), count2(d + 2, 0);

    int i = 0;
    int ans = 0;
    int k_ = k;
    while (i < n and k_ > 0)
    {

        int j = 0;

        while (i < n and j < k_)
        {
            H1[A[i].s] += A[i].h;
            H1[A[i].e + 1] -= A[i].h;

            count1[A[i].s] += 1;
            count1[A[i].e + 1] -= 1;

            i++;
            j++;
        }

        for (int i = 1; i <= d; i++)
            count1[i] += count1[i - 1], H1[i] += H1[i - 1];

        int MAX_sofar = 0;

        for (int i = 1; i <= d; i++)
        {
            count2[i] += count1[i];
            if (count2[i] < k)
                MAX_sofar = max(MAX_sofar, count2[i]);
            count1[i] = 0;
        }
        bool gotit = false;
        for (int i = 1; i <= d; i++)
        {
            H2[i] += H1[i];
            if (count2[i] <= k)
                ans = max(H2[i], ans);
            H1[i] = 0;
        }

        k_ = k - MAX_sofar;
    }
    cout << ans << endl;
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