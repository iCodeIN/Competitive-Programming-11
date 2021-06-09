

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
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
#define deb(x) cout << #x << " : " << x << endl;

struct node
{
    int Max = 0;
    int Min = 0;
    node() {}
    node(int a, int b)
    {
        Max = a;
        Min = b;
    }
};

int Area(int up, int down, int left, int right)
{

    int ans = (up - down) * (right - left);
    return ans;
}

void add(vector<pair<int, node>> &A, map<int, node> &mp, v(node) & suf)
{

    int i = 0;
    for (auto &line : mp)
    {
        A[i] = line;
        i++;
    }
    int n = A.size();
    suf[n - 1] = A[n - 1].second;

    for (int i = n - 2; i >= 0; i--)
    {
        suf[i].Min = min(A[i].second.Min, suf[i + 1].Min);
        suf[i].Max = max(A[i].second.Max, suf[i + 1].Max);
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> temp(n);

    for (int i = 0; i < n; i++)
        cin >> temp[i].first >> temp[i].second;

    map<int, node> mpX;
    map<int, node> mpY;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        x = temp[i].first;
        y = temp[i].second;

        auto itrX = mpX.find(x);
        auto itrY = mpY.find(y);

        if (itrX == mpX.end())
        {
            node tempY(y, y);
            mpX[x] = tempY;
        }
        else
        {
            itrX->second.Max = max(itrX->second.Max, y);
            itrX->second.Min = min(itrX->second.Min, y);
        }

        if (itrY == mpY.end())
        {
            node tempX(x, x);
            mpY[y] = tempX;
        }
        else
        {
            itrY->second.Max = max(itrY->second.Max, x);
            itrY->second.Min = min(itrY->second.Min, x);
        }
    }

    vector<pair<int, node>> A(mpX.size());
    vector<pair<int, node>> B(mpY.size());
    v(node) sufA(A.size());
    v(node) sufB(B.size());
    add(A, mpX, sufA);
    add(B, mpY, sufB);

    int u1 = A[0].second.Max;
    int d1 = A[0].second.Min;
    int l1 = A[0].first;
    int r1 = A[0].first;
    int ans = Area(sufA[0].Max, sufA[0].Min, A[0].first, A.back().first);
    for (int i = 0; i + 1 < (int)A.size(); i++)
    {
        r1 = A[i].first;
        d1 = min(d1, A[i].second.Min);
        u1 = max(u1, A[i].second.Max);
        int cur = Area(u1, d1, l1, r1) + Area(sufA[i + 1].Max, sufA[i + 1].Min, A[i + 1].first, A.back().first);
        ans = min(ans, cur);
    }

    u1 = B[0].first;
    d1 = B[0].first;
    l1 = B[0].second.Min;
    r1 = B[0].second.Max;

    for (int i = 0; i + 1 < (int)B.size(); i++)
    {
        u1 = B[i].first;
        l1 = min(l1, B[i].second.Min);
        r1 = max(r1, B[i].second.Max);
        int cur = Area(u1, d1, l1, r1) + Area(B.back().first, B[i + 1].first, sufB[i + 1].Min, sufB[i + 1].Max);
        ans = min(ans, cur);
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