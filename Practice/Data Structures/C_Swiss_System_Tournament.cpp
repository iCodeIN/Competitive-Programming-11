

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
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
    int id;
    int win;
};

bool operator<(node a, node b)
{

    bool ans = (a.win != b.win) ? a.win > b.win : a.id < b.id;

    return !ans;
}

void play(priority_queue<node> &prev, priority_queue<node> &cur, v(string) & A, int round)
{

    while (prev.size() > 0)
    {
        auto p1 = prev.top();
        prev.pop();
        auto p2 = prev.top();
        prev.pop();

        // Here, G stands for rock, C stands for scissors, and P stands for paper. (These derive from Japanese.)

        if (A[p1.id][round] > A[p2.id][round])
            swap(p1, p2);

        // C
        // G
        // P

        if (A[p1.id][round] == 'C') // sis
        {
            if (A[p2.id][round] == 'G') // rock
                p2.win++;

            else if (A[p2.id][round] == 'P') // paper
                p1.win++;
        }
        else if (A[p1.id][round] == 'G') // rock
        {
            if (A[p2.id][round] == 'P') // paper
                p2.win++;
        }

        cur.push(p1);
        cur.push(p2);
    }
}

void print(priority_queue<node> pq)
{

    while (pq.size() > 0)
    {
        auto f = pq.top();

        cout << f.id + 1 << endl;
        pq.pop();
    }
}

void solve()
{

    int n, m;
    cin >> n >> m;

    v(string) A(2 * n);

    for (string &s : A)
        cin >> s;

    priority_queue<node> even;
    priority_queue<node> odd;

    for (int i = 0; i < 2 * n; i++)
    {
        node temp;
        temp.id = i;
        temp.win = 0;
        even.push(temp);
    }

    for (int i = 1; i <= m; i++)
    {
        if (i & 1)
            play(even, odd, A, i - 1);
        else
            play(odd, even, A, i - 1);
        // cout << "round " << i << endl;
        // print(even);
        // print(odd);
        // cout << endl;
    }

    // cout << odd.size() << ' ' << even.size() << endl;

    if (odd.size())
        print(odd);
    else
        print(even);
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //