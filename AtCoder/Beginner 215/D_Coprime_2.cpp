

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

// #define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

const int N = 1e5;

int spf[N + 1];

bool check(v(bool) & canUse, int x)
{

    while (x > 1)
    {

        if (!canUse[spf[x]])
            return false;
        x /= spf[x];
    }

    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    spf[1] = 1;

    for (int i = 2; i <= N; i++)
        spf[i] = i;

    for (int i = 2; i * i <= N; i++)
        if (spf[i] == i)
            for (int j = i * i; j <= N; j += i)
                if (spf[j] == j)
                    spf[j] = i;

    v(bool) canUse(N + 1, true);
    v(int) A(n);
    for (int &x : A)
        cin >> x;

    for (int i = 0; i < n; i++)
    {

        while (A[i] != 1)
        {
            int x = spf[A[i]];
            A[i] /= x;
            canUse[x] = false;
        }
    }

    v(int) Ans;

    for (int i = 1; i <= m; i++)
        if (i == 1 or check(canUse, i))
            Ans.push_back(i);

    cout << Ans.size() << endl;

    for (int x : Ans)
        cout << x << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //