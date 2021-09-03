

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define all(x) x.begin(), x.end()

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <iostream>
#include <vector>using namespace std;

#define v(Type) vector<Type>

int dfs(int root, v(int) Adj[], v(bool) & good, int parent)
{

    if (!good[root])
        return 0;

    int ans = 1;

    for (int x : Adj[root])
        if (x != parent)
            ans += dfs(x, Adj, good, root);

    return ans;
}

void solve()
{

    int n;
    cin >> n;

    v(int) Adj[n + 1];

    for (int i = 0; i < n - 1; i++)
    {

        int u, v;
        cin >> u >> v;

        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    int firstBenchers;
    cin >> firstBenchers;

    v(bool) good(n + 1, true);

    for (int i = 0; i < firstBenchers; i++)
    {
        int x;
        cin >> x;

        good[x] = false;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
        ans = max(ans, dfs(i, Adj, good, 0));

    cout << ans << endl;
}

int32_t main()
{
    // FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <iostream>
using namespace std;
void swap(int *a, int *s);
void quick(int input[], int n);
void quick1(int input[], int lb, int ub);
int partition(int input[], int lb, int ub);
int main()
{
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i];
    }
    delete[] input;
}
void quick(int input[], int n)
{
    int lb = 0;
    int ub = n - 1;
    quick1(input, lb, ub);
}
void quick1(int input[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(input, lb, ub);
        quick1(input, lb, loc - 1);
        quick1(input, loc + 1, ub);
    }
}
int partition(int input[], int lb, int ub)
{
    int start = lb;
    int end = ub;
    int pivot = input[0];
    while (start < end)
    {
        while (input[start] <= pivot)
        {
            start--;
        }
        while (pivot < input[end])
        {
            end--;
        }
        if (start < end)
        {
            swap(&input[start], &input[end]);
        }
    }
    swap(&input[0], &input[end]);
    return end;
}
void swap(int *a, int *s)
{
    int temp = *a;
    *a = *s;
    *s = temp;
}