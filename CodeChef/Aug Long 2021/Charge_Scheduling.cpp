

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

struct node
{
    int chargingTime;
    int leavingTime;
    int person;

    bool operator<(node x)
    {

        return this->chargingTime < x.chargingTime;
    }
};

struct node2
{

    int person;
    int start;
    int end;
};

void solve()
{
    int n;
    cin >> n;

    v(node) A(n);

    for (int i = 0; i < n; i++)
        cin >> A[i].chargingTime;
    for (int i = 0; i < n; i++)
        cin >> A[i].leavingTime;
    for (int i = 0; i < n; i++)
        A[i].person = i + 1;

    sort(A.begin(), A.end());

    v(node2) Ans;

    int start = 0;
    for (int i = 0; i < n; i++)
    {
        if (start + A[i].chargingTime <= A[i].leavingTime)
        {
            struct node2 x;

            x.start = start;
            x.end = x.start + A[i].chargingTime;
            x.person = A[i].person;
            Ans.push_back(x);

            start = x.end;
        }
        else
            break;
    }

    cout << Ans.size() << endl;

    for (auto x : Ans)
        cout << x.person << " " << x.start << " " << x.end << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //