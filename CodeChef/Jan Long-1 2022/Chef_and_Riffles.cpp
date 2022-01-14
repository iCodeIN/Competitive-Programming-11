// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <bits/stdc++.h>
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
using namespace std;
using LL = long long int;
using LD = long double;
using vi = vector<LL>;
using pii = pair<LL, LL>;
const LL mod = 1e9 + 7;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#define all(x) x.begin(), x.end()
#define double LD
#define endl "\n"
#define ff first
#define int LL
#define ss second
#define v vector
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
void f(v<int> &A)
{
    int i = 0;
    int j = 0;
    v<int> B = A;
    int n = A.size();
    while (j < n)
    {
        B[i] = A[j];
        i++;
        j += 2;
    }

    j = 1;

    while (j < n)
    {
        B[i] = A[j];
        i++;
        j += 2;
    }
    A = B;
}

void solve()
{
    int n;
    cin >> n;

    int k;
    cin >> k;
    v<int> A(n);
    for (int i = 1; i <= n; i++)
        A[i - 1] = i;

    int op = log2(n);
    k %= op;
    while (k--)
        f(A);
    for (int &x : A)
        cout << x << " ";
    cout << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //