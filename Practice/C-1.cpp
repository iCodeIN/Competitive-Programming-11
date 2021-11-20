#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool comp(vector<ll> &A, vector<ll> &B)
{
    return A[1] > B[1];
}

ll solve(vector<vector<ll>> &A, ll truckSize)
{

    sort(A.begin(), A.end(), comp);

    ll ans = 0;
    ll n = A.size();

    for (int i = 0; i < n; i++)
    {
        int x = min(truckSize, A[i][0]);
        ans += 1ll * x * A[i][1];
        truckSize -= x;
    }

    return ans;
}

long int getMaxUnit(int num, vector<int> &boxes, int unitSize, vector<int> &unitsPerBox, long truckSize)
{
    vector<vector<ll>> A(num);

    for (int i = 0; i < num; i++)
    {
        A[i].push_back(boxes[i]);
        A[i].push_back(unitsPerBox[i]);
    }
    return solve(A, truckSize);
}

int main()
{
    ll num;
    cin >> num;

    vector<int> A(num);

    for (auto &x : A)
        cin >> x;

    int numSize;
    cin >> numSize;
    vector<int> B(num);

    for (auto &x : B)
        cin >> x;

    ll t;

    cin >> t;

    cout << getMaxUnit(num, A, numSize, B, t);
}
