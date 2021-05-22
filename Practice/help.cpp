

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

bool isgood(v(int) & A, int n, int help, int deadline)
{
    priority_queue<int> pq;
    int prev = A[0];
    for (int i = 1; i < n; i++)
    {
        int x = A[i];
        if (x > prev)
            pq.push(x - prev);

        prev = x;
    }

    int ans = 0;
    while (!pq.empty() and help > 0)
    {
        pq.pop();
        help--;
    }

    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    return ans <= deadline;
}
int solve(v(int) & A, int n, int help, int deadline)
{

    int l = 0;
    int r = n + 1;

    while (r - l > 1)
    {
        int m = (l + r) / 2;

        if (isgood(A, m, help, deadline))
            l = m;
        else
            r = m;
    }
    return l;
}

void solve()
{
    int n, help, deadline;
    cin >> n >> help >> deadline;

    swap(help, deadline);
    v(int) A(n);

    for (int i = 0; i < n; i++)
        cin >> A[i];

    int ans = solve(A, n, help, deadline);

    cout << ans - 1 << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //