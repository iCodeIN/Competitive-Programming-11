#include <bits/stdc++.h>
using namespace std;

bool check(string &s, string &t)
{
    // s will be streched to t
    int i = 0;
    int j = 0;

    while (i < s.length() or j < t.length())
    {
        if (i == s.length())
            return false;

        char ch = s[i];
        int f1 = 0;
        while (i < s.length() and s[i] == ch)
            i++, f1++;

        int f2 = 0;
        while (j < t.length() and t[j] == ch)
            j++, f2++;

        if (f2 >= f1 and ((f1 == f2) or (f2 >= 3)) and f1 >= 1)
            continue;
        else
            return false;
    }

    return true;
}

int solve(string s, vector<string> &A)
{
    int ans = 0;
    for (auto &x : A)
        ans += check(x, s);

    return ans;
}

int main()
{
    string a, b;
    cin >> a >> b;

    cout << check(b, a) << endl;
}