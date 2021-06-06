

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
#include <map>
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

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);

    map<int, int> mp;
    set<int> initial;
    set<int> extra;

    v(int) Ans;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        initial.insert(A[i]);
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (initial.find(abs(A[i] - A[j])) == initial.end())
                extra.insert(abs(A[i] - A[j]));

    int s = 0;
    while (initial.size() <= 300 and extra.size() > 0)
    {

        for (int x : extra)
        {
            Ans.push_back(x);
            initial.insert(x);
        }
        extra.clear();

        for (int i = 0; i < n; i++)
        {
            for (int j = s; j < (int)Ans.size(); j++)
            {
                if (initial.find(abs(A[i] - Ans[j])) == initial.end())
                {
                    extra.insert(abs(A[i] - Ans[j]));
                }
            }
        }

        s = Ans.size();
    }

    bool ans = (extra.size() == 0 and initial.size() <= 300);

    if (ans)
    {
        cout << "YES\n";
        cout << initial.size() << endl;
        for (int x : initial)
            cout << x << " ";
    }
    else
        cout << "NO";

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