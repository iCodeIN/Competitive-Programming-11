// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <iostream>
#include <vector>
#include <algorithm>
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
using namespace std;
// // // //  // // // // // //  // // //
#define all(x) x.begin(), x.end()
#define double LD
#define endl "\n"
#define ff first
#define ss second
#define v vector
#define pii pair<int, int>
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
class Sol
{
public:
    int l, r, k;
    v<v<pii>> mp;
    v<int> A, B;

    void solve(int pos, int count, int a, int b)
    {
        if (count > k)
            return;

        if (pos == l - 1)
        {
            mp[count].push_back({a, b});
            return;
        }

        solve(pos - 1, count, a, b);
        solve(pos - 1, count + 1, a + A[pos], b + B[pos]);
    }

    Sol(v<int> &A, v<int> &B, int l, int r, int k)
    {
        this->A = A;
        this->B = B;
        this->l = l;
        this->r = r;
        this->k = k;
        mp.resize(k + 1);
        solve(r, 0, 0, 0);
    }
};

void filter(v<pii> &A)
{
    int n = A.size();
    if (n == 0)
        return;
    sort(all(A));
    v<int> suf(n);
    suf[n - 1] = n - 1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i].ss > A[suf[i + 1]].ss)
        {
            suf[i] = i;
        }
        else
        {
            suf[i] = suf[i + 1];
        }
    }
    v<pii> temp;
    for (int i = 0; i < n; i++)
    {
        if (suf[i] != i and A[i].ss <= A[suf[i]].ss)
            continue;
        else
            temp.push_back(A[i]);
    }
    A = temp;
}

int lb(v<pii> &cur, int f)
{
    int l = -1;
    int r = cur.size();

    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (cur[m].ff >= f)
            r = m;
        else
            l = m;
    }

    return r;
}
void solve()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    v<int> A(n);
    v<int> B(n);

    for (int &x : A)
        cin >> x;
    for (int &x : B)
        cin >> x;

    int m = n / 2;

    Sol left(A, B, 0, m, k);
    Sol right(A, B, m + 1, n - 1, k);

    int ans = 0;

    for (int i = 0; i <= k; i++)
    {
        filter(left.mp[i]);
        filter(right.mp[i]);
    }

    for (int i = 0; i <= k; i++)
    {
        auto &cur = right.mp[i];
        auto &leftcur = left.mp[k - i];
        bool swapped = false;

        if (leftcur.size() > cur.size())
        {
            swap(cur, leftcur);
            swapped = true;
        }
        sort(all(cur));

        int n = cur.size();

        if (n == 0)
            continue;

        v<int> suf(n);
        suf[n - 1] = n - 1;
        for (int j = n - 2; j >= 0; j--)
            if (cur[j].ss > cur[suf[j + 1]].ss)
                suf[j] = j;
            else
                suf[j] = suf[j + 1];

        //
        for (auto &itr : leftcur)
        {
            int l = ans;
            int r = 1601;

            while (r - l > 1)
            {
                int m = (l + r) / 2;

                bool ok = false;
                int idx = lb(cur, m - itr.ff);

                if (idx < n)
                {
                    idx = suf[idx];
                    int curAns = min(cur[idx].ff + itr.ff, cur[idx].ss + itr.ss);
                    ok = (curAns >= m);
                    ans = max(ans, curAns);
                }

                if (ok)
                    l = m;
                else
                    r = m;
            }
        }
        if (swapped)
            swap(cur, leftcur);
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