

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

struct item
{
    int l;
    int r;
    int d;
};

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);

    for (int &x : A)
        cin >> x;

    v(item) Ans;
    for (int i = 0; i < n; i++)
    {
        int temp = A[i];
        int j = i - 1;

        while (j >= 0 and A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }

        if (j + 1 != i)
        {

            item x;
            x.l = j + 2;
            x.r = i + 1;
            x.d = x.r - x.l;
            Ans.push_back(x);
        }
        A[j + 1] = temp;
    }
    cout << Ans.size() << endl;

    for (auto i : Ans)
        cout << i.l << " " << i.r << " " << i.d << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //