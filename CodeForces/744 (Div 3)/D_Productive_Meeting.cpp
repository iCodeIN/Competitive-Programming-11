

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

// #define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

struct item
{
    int p1;
    int p2;
};

const int N = 1e6;
static item Ans[N + 1];

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);

    priority_queue<pair<int, int>> pq;
    for (int &x : A)
        cin >> x;
    int i = 1;
    for (int x : A)
    {

        if (x > 0)
            pq.push({x, i});
        i++;
    }
    int j = -1;
    while (pq.size() >= 2)
    {
        auto f = pq.top();
        pq.pop();
        auto s = pq.top();
        pq.pop();

        ++j;
        Ans[j].p1 = f.second;
        Ans[j].p2 = s.second;

        f.first--;
        s.first--;

        if (f.first > 0)
            pq.push(f);
        if (s.first > 0)
            pq.push(s);
    }

    cout << j + 1 << endl;

    for (int i = 0; i <= j; i++)
        cout << Ans[i].p1 << ' ' << Ans[i].p2 << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //