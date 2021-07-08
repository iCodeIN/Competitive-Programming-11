

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
#include <map>
// #include <set>
#include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
#include <vector>
// #include <deque>

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

    priority_queue<int, vector<int>, greater<int>> pq, pq2;
    map<int, int> mp; // ans->group

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    pq2 = pq;

    int ans = 1;
    int group = 0;
    while (pq.size() > 0)
    {

        int prevprev = -1;
        int prev = -1;
        int cur = 0;
        while (1)
        {
            if (pq.size() == 0)
                break;
            int t = pq.top();

            if (prev != -1 and (t - prev > 1))
                break;
            if (prevprev != -1 and t - prevprev > 1)
            {
                pq.push(prev);
                break;
            }

            cur++;
            prevprev = prev;
            prev = t;
            pq.pop();
        }
        mp[cur] = group;
        ans = max(ans, cur);
        group++;
    }

    int req_group = mp[ans];
    v(int) f, b;
    int i = 0;
    while (i <= req_group)
    {

        int prevprev = -1;
        int prev = -1;
        int cur = 0;
        while (1)
        {
            if (pq2.size() == 0)
                break;
            int t = pq2.top();

            if (prev != -1 and (t - prev > 1))
                break;
            if (prevprev != -1 and t - prevprev > 1)
            {
                pq2.push(prev);
                break;
            }
            if (i == req_group)
            {
                if (cur & 1)
                    b.push_back(t);
                else
                    f.push_back(t);
            }

            cur++;
            prevprev = prev;
            prev = t;
            pq2.pop();
        }
        ans = max(ans, cur);
        i++;
    }
    reverse(all(f));
    cout << ans << endl;
    for (int x : f)
        cout << x << " ";
    for (int x : b)
        cout << x << " ";
    cout << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
