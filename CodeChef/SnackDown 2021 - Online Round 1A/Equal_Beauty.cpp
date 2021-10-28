

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
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

int f(v(int) & A, bool first)
{
    int n = A.size();

    int start = 1;
    int end = n - 1;

    if (first)
    {

        while (start <= end and A[start] == A[0])
            start++;
    }

    else
    {
        start--;
        end--;

        while (end >= start and A[end] == A[n - 1])
            end--;
    }

    int ans = 0;

    for (int i = start; i <= end; i++)
    {
        int m = (start + end) >> 1;

        ans += abs(A[i] - A[m]);
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);

    for (int &x : A)
        cin >> x;

    sort(all(A));

    int m = A[0];
    int M = A[n - 1];
    set<int> st;
    int ans = INT64_MAX;

    for (int i = 0; i < n - 1; i++)
    {

        if (i == 0)
        {
            ans = min(ans, f(A, true));
            continue;
        }
        else if (i == n - 2)
        {
            ans = min(ans, f(A, false));
        }

        int dif1 = A[i] - m;     // [0....i]
        int dif2 = M - A[i + 1]; // [i+1.....n-1]

        if (dif1 <= dif2)
        {
            ans = min(ans, dif2 - dif1);
        }
        else
        {
            if (i != n - 2)
                ans = min(ans, dif1 - dif2);
            int exp = M - dif1;
            if (i != n - 2)
                ans = min(ans, A[i + 1] - exp);
            auto itr = st.lower_bound(exp);

            if (itr != st.end())
            {
                ans = min(ans, *itr - exp);
            }

            if (itr != st.begin())
            {
                itr--;
                ans = min(ans, exp - *itr);
            }
        }

        st.insert(A[i]);
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