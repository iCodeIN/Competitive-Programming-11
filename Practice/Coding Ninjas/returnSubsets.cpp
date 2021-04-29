#include <bits/stdc++.h>
using namespace std;

// A : [1,2,3,5,7]
// n : 5
// A.size()
vector<vector<int>> returnSubsets(int *A, int n)
{
    if (n == 0)
    {
        vector<vector<int>> ans(1);
        return ans;
    }

    vector<vector<int>> smallAns = returnSubsets(A, n - 1);
    int smallsize = smallAns.size();

    vector<vector<int>> ans;

    for (int i = 0; i < smallsize; i++)
    {
        ans.push_back(smallAns[i]);
    }
    for (int i = 0; i < smallsize; i++)
    {
        ans.push_back(smallAns[i]);
    }
    for (int i = smallsize; i < ans.size(); i++)
    {
        ans[i].push_back(A[n - 1]);
    }
    return ans;
}

// 1 -> element choosen
// 0 -> element rejected
void printSubsets(int *A, int n, string output = "")
{
    if (n == 0)
    {
        for (int i = 0; i < output.length(); i++)
            if (output[i] == '1')
                cout << A[i] << " ";
        cout << endl;
        return;
    }

    printSubsets(A, n - 1, output + '0');
    printSubsets(A, n - 1, output + '1');
}

int solve(int *A, int n, int k, int sum = 0)
{
    if (n == 0)
    {
        if (sum == k)
            return 1;
        else
            return 0;
    }

    int ans1 = solve(A, n - 1, k, sum);
    int ans2 = solve(A, n - 1, k, sum + A[n - 1]);

    return ans1 + ans2;
}

int solve(int *A, int n, int k)
{
    if (n == 0)
    {
        if (k == 0)
            return 1;
        else
            return 0;
    }

    int ans1 = solve(A, n - 1, k);
    int ans2 = solve(A, n - 1, k - A[n - 1]);

    return ans1 + ans2;
}

int main()
{
    int *A = new int[4];

    for (int i = 0; i < 4; i++)
        A[i] = i + 1;

    printSubsets(A, 4);
    // vector<vector<int>> Ans = returnSubsets(A, 4);

    // for (int i = 0; i < Ans.size(); i++)
    // {
    //     for (int j = 0; j < Ans[i].size(); j++)
    //         cout << Ans[i][j] << " ";

    //     cout << endl;
    // }
}
