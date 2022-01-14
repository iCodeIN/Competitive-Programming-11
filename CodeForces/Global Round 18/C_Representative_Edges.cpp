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

struct node
{
    int a_num;
    int a_den;
    int d_num;
    int d_den;

    bool operator<(node b)
    {
        pair<pii, pii> a_ = {{this->a_num, this->a_den}, {this->d_num, this->d_den}};
        pair<pii, pii> b_ = {{b.a_num, b.a_den}, {b.d_num, b.d_den}};
        return a_ < b_;
    }
};

int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;

    v<int> A(n);
    int ans = n - 1;

    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int l = 0; l < n; l++)
    {
        for (int r = l + 1; r < n; r++)
        {
            int a_num = (A[l] * r - A[r] * l);
            int d_num = A[r] - A[l];
            int changes = 0;

            for (int j = 0; j < n; j++)
            {
                int LHS = A[j] * (r - l);
                int RHS = a_num + j * d_num;
                changes += LHS != RHS;
            }
            ans = min(ans, changes);
        }
    }
    cout << ans << endl;
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
