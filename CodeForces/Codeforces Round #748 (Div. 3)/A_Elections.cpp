

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
#include <map>
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
    int v;
    int id;
    int ans;
};

bool comp1(node a, node b)
{
    return a.v < b.v;
}

bool comp2(node a, node b)
{
    return a.id < b.id;
}
void solve()
{
    v(node) A(3);

    for (int i = 0; i < 3; i++)
    {
        cin >> A[i].v;
        A[i].id = i;
    }

    sort(A.begin(), A.end(), comp1);

    for (int i = 0; i < 2; i++)
        A[i].ans = A[2].v - A[i].v + 1;

    A[2].ans = A[2].v == A[1].v;
    sort(A.begin(), A.end(), comp2);

    for (int i = 0; i < 3; i++)
        cout << A[i].ans << " ";

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