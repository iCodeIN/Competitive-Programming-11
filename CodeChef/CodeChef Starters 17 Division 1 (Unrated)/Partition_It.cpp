

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
#include <set>
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

int N = 1e5;
v(int) P;
void seive()
{
    v(bool) isP(N + 1, true);
    isP[0] = false;
    isP[1] = false;
    for (int i = 2; i * i <= N; i++)
        if (isP[i])
            for (int j = i * i; j <= N; j += i)
                isP[j] = false;

    for (int i = 2; i <= N; i++)
        if (isP[i])
            P.push_back(i);
}

void solve()
{

    int n, k;
    cin >> n >> k;

    set<int> st;
    st.insert(1);

    for (int p : P)
    {
        if ((int)st.size() > k)
            break;
        if (p > n)
            break;
        if (2 * p > n)
            st.insert(p);
    }

    if (k <= (int)st.size())
    {
        cout << "Yes\n";
        for (int x : st)
            if (k == 0)
                break;
            else
                cout << x << " ", k--;
    }
    else if (k >= n - (int)st.size())
    {
        cout << "Yes\n";

        for (int i = 1; i <= n; i++)
            if (st.count(i) == 0)
                cout << i << " ", k--;

        for (int x : st)
            if (k == 0)
                break;
            else
                cout << x << " ", k--;
    }
    else
    {
        cout << "No";
    }

    cout << endl;
}

int32_t main()
{
    FastIO;
    seive();
    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// 1 24 3
