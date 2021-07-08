#include <iostream>
#include <unordered_map>
using namespace std;

void print(unordered_map<int, int> &mp)
{

    for (auto x : mp)
    {
        cout << x.first << "->" << x.second << endl;
    }
    cout << "---------------------------------------\n";
}

int solve(int A[], int n)
{
    unordered_map<int, int> mp;
    int maxFreq = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp.count(A[i]) == 0)
        {
            // mp.insert({A[i], 1});
            mp[A[i]] = 1;
        }
        else
            mp[A[i]]++;
        maxFreq = max(maxFreq, mp[A[i]]);
        // print(mp);
    }
    for (int i = 0; i < n; i++)
    {
        if (mp[A[i]] == maxFreq)
        {
            return A[i];
        }
    }
}

int main()
{
    int A[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int ans = solve(A, n);

    cout << ans << endl;
}