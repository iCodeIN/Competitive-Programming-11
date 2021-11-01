

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

int f(v(int) & A)
{
}

void solve()
{
    v(int) A(3);
    for (int &x : A)
        cin >> x;
    sort(all(A));
    int ans1 = f(A);
    int ans = A[0];

    A[1] -= A[0];
    A[2] -= A[0];
    A[0] -= A[0];

    int m = min(A[1], A[2] - A[1]);
    ans += m;

    A[1] -= m;
    A[2] -= 2 * m;
    if (A[1] > 0)
    {
        ans += 2 * (A[1] / 3);
        ans += (A[1] % 3 == 2);
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

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/*

    1 1 1 1 1 1 1 1 1 1 1
    2 2 2    
    3 3

    1 1 1 1 1 
    2 2 2 3 3  
    1 1 1 1 1 1   
  
*/