

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

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);
    for (int &x : A)
        cin >> x;

    v(int) B(33, 0);

    for (int i = 0; i < n; i++)
    {
        int x = A[i];

        int j = 0;
        while (x)
        {
            if (x & 1)
                B[j]++;

            j++;
            x >>= 1;
        }
    }

    int mx = 0;

    for (int i = 0; i < 33; i++)
        mx = gcd(mx, B[i]);

    v(int) Ans;

    if (mx == 0)
    {
        for (int i = 0; i < n; i++)
            Ans.push_back(i + 1);
    }
    else
    {
        for (int i = 1; i * i <= mx; i++)
        {

            if (mx % i == 0)
            {
                Ans.push_back(i);

                if (i * i != mx)
                {
                    Ans.push_back(mx / i);
                }
            }
        }
        sort(all(Ans));
    }
    for (int x : Ans)
        cout << x << ' ';
    cout << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //