

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

int f(v(int) & A, int s)
{
    int c = 0;
    while (s + 1 < (int)(A.size()))
    {

        if (A[s] > A[s + 1])
            swap(A[s], A[s + 1]), c++;
        s += 2;
    }
    return true;
}

bool sorted(v(int) & A)
{

    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        if (A[i] < A[i - 1])
            return false;
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

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (sorted(A))
            break;

        if (i & 1)
        {
            ans += f(A, 0);
        }
        else
        {
            ans += f(A, 1);
        }
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