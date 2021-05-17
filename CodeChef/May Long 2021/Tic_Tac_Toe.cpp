

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

int count(v(string) & board, char ch)
{
    int ans = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            ans += (ch == board[i][j]);
    return ans;
}

bool check(v(string) & board, char ch)
{
    string p = "";
    for (int i = 0; i < 3; i++)
        p += ch;

    // rows
    for (int i = 0; i < 3; i++)
        if (board[i] == p)
            return true;

    // cols
    string temp = "";
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
            temp += board[i][j];

        if (temp == p)
            return true;
        temp = "";
    }

    // d1
    temp = "";
    for (int i = 0, j = 0; i < 3; i++, j++)
        temp += board[i][j];

    if (temp == p)
        return true;

    temp = "";

    for (int i = 2, j = 0; i >= 0; i--, j++)
        temp += board[i][j];

    return (temp == p);
}

void solve()
{
    v(string) board(3);

    for (int i = 0; i < 3; i++)
        cin >> board[i];

    int x = count(board, 'X');
    int z = count(board, 'O');

    int filled = x + z;
    bool xWin = check(board, 'X');
    bool zWin = check(board, 'O');

    int ans = 0;

    if ((x - z != 0 and x - z != 1) or (xWin and zWin) or (x - z == 0 and xWin) or (x - z == 1 and zWin))
        ans = 3;
    else if (xWin or zWin or (filled == 9))
        ans = 1;
    else
        ans = 2;

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