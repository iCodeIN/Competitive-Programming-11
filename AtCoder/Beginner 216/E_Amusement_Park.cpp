

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <set>
#include <queue>
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

int f(int a, int n)
{

    return (n * ((2 * a) - (n - 1))) / 2;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    priority_queue<int> pq;
    v(int) A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int x : A)
        pq.push(x);
    int ans = 0;
    while (pq.size() > 1 and k > 0)
    {
        int M1 = pq.top();
        pq.pop();
        int M2 = pq.top();

        int choose = M1 - M2 + 1;
        int choosen = min(k, choose);
        ans += f(M1, choosen);
        k -= choosen;
        M1 -= choosen;

        if (M1 > 0)
            pq.push(M1);
    }
    if (k > 0 and pq.size() > 0)
    {
        int M = pq.top();

        ans += f(M, min(M, k));

        pq.pop();
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

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //]