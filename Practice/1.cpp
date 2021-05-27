// #include <bits/stdc++.h>
// using namespace std;

// #define inf INT_MAX
// #define int long long

// // rec : O(2^n)
// // dp  :  O(n^3)

// // n <= 300
// // recursion -> memoisation(Recursive DP) -> tabulation(Iterative DP)

// map<int, int> dp[301][301];
// int calls = 0;
// int solve(int A[], int n, int cut, int curMax)
// {
//     ++calls;
//     if (n == 0)
//     {
//         if (cut == 0)
//             return curMax;
//         else
//             return inf;
//     }
//     if (dp[n][cut].count(curMax) > 0)
//     {
//         return dp[n][cut][curMax];
//     }
//     // include in the current window
//     int ans1 = solve(A, n - 1, cut, max(curMax, A[n - 1]));
//     // if cut > 0
//     int ans2 = (cut > 0) ? solve(A, n - 1, cut - 1, A[n - 1]) + curMax : ans1;

//     return dp[n][cut][curMax] = min(ans1, ans2);
// }

// int32_t main()
// {
//     int A[] = {1, 5, 3, 4, 5, 1, 1, 1, 1, 1};
//     int k = 3;
//     int n = sizeof(A) / sizeof(int);
//     calls = 0;
//     for (int i = 0; i <= n; i++)
//         for (int j = 0; j <= n; j++)
//             dp[i][j].clear();
//     int ans = solve(A, n - 1, k - 1, A[n - 1]);

//     cout << calls << endl;
// }

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter n";
    cin >> n;
    for (int m = 2; m <= n; m++)
    {

        bool isPrime = true;
        for (int i = 2; i <= m - 1; i++)
        {
            if (m % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime == true)
            cout << m << endl;
    }
}