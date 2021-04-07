#include <bits/stdc++.h>
using namespace std;

pair<int, string> dp[1000][1000];

pair<int, string> solve(int A[], int W[], int n, int capacity)
{
    if (capacity == 0 or n == 0)
        return {0, ""};
    pair<int, string> temp = {-1, ""};
    auto ans2 = solve(A, W, n - 1, capacity);
    auto ans1 = (W[n - 1] <= capacity) ? solve(A, W, n - 1, capacity - W[n - 1]) : temp;
    if (ans1 != temp)
    {
        ans1.first += A[n - 1];
        ans1.second += "1";
    }
    ans2.second += "0";
    auto ans = (ans1.first > ans2.first) ? ans1 : ans2;
    if (ans1.first > ans2.first)
    {
        return ans1;
    }
    return ans2;
}

int main()
{
    int A[] = {100, 90, 70, 50, 40};
    int W[] = {20, 21, 50, 54, 100};

    int n = 5;
    int capacity = 100;
    auto ans = solve(A, W, n, capacity);

    cout << ans.first << endl;
    cout << ans.second << endl;
}