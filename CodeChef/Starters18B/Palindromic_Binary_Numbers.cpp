

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
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

bool isP(int n)
{
    string ans;
    while (n)
    {
        if (n & 1)
            ans += '1';
        else
            ans += '0';

        n >>= 1;
    }

    string temp = ans;
    reverse(all(temp));
    return temp == ans;
}

int A[1001];
v(int) good;
v(int) Ans[1001];

void pre()
{
    for (int i = 1; i <= 1000; i++)
        if (isP(i))
            good.push_back(i);

    int n;
    v(bool) visited(1001, false);
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (q.size())
    {

        auto f = q.front();
        A[f.first] = f.second;

        for (int x : good)
        {
            if (x + f.first <= 1000 and !visited[x + f.first])
            {
                visited[x + f.first] = true;
                q.push({x + f.first, x});
            }
        }
        q.pop();
    }

    for (int i = 1; i <= 1000; i++)
    {

        int x = i;
        while (A[x] != x)
        {
            Ans[i].push_back(A[x]);
            x -= A[x];
        }
        Ans[i].push_back(x);
    }
}
void solve()
{
    int n;
    cin >> n;
    cout << Ans[n].size() << "\n";
    for (int x : Ans[n])
        cout << x << " ";
    cout << endl;
}

int32_t main()
{
    FastIO;

    pre();
    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //