

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

bool f(v(int) & A, int i, int j, int x)
{
    while (i <= j)
    {
        if (A[i] != A[j])
        {
            if (A[i] == x)
                i++;
            else if (A[j] == x)
                j--;
            else
                return false;
        }
        else
        {
            i++, j--;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);

    for (int &x : A)
        cin >> x;

    int i = 0;
    int j = n - 1;

    while (i <= j and A[i] == A[j])
        i++, j--;

    bool ans = i > j;

    if (!ans)
        ans = f(A, i, j, A[i]) or f(A, i, j, A[j]);

    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //