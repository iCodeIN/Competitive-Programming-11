

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

void print(v(int) & A, int s, int e)
{
    cout << s << "," << e << ": ";
    while (s <= e)
        cout << A[s++] << " ";

    cout << endl;
}

void solve()
{
    int n;
    cin >> n;

    v(v(int)) A(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        A[i].resize(m);
        for (int &x : A[i])
            cin >> x;
    }
    int ans = 0;
    for (int k = 0; k < n; k++)
    {
        int i = 0;
        int c1 = 0;
        while (i < (int)A[k].size())
        {
            int j = i + 1;

            while (j < (int)A[k].size() and A[k][j] >= A[k][j - 1])
                j++;

            // print(A[k], i, j - 1);
            int len = j - i;

            c1 += min(len, (int)A[k].size() - j);
            i = j;
            pq.push(len);
        }
        int c2 = 0;
        while (i >= 0)
        {
            int j = i - 1;

            while (j >= 0 and A[k][j] >= A[k][j + 1])
                j--;

            // print(A[k], i, j - 1);
            int len = abs(j - i);

            c2 += min(len, (int)A[k].size() - j);
            i = j;
            // pq.push(len);
        }
        ans += min(c1, c2);
    }
    // cout << ans << endl;
    int i = 0;
    int pre = 0;

    while (pq.size() >= 2)
    {

        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += (a + b);
        pq.push(a + b);
        // cout << a << "," << b << endl;
    }
    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// x1 x2 x3

// (x1 + x2) + (X1+ x2 + x3)