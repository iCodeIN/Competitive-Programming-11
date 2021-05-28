#include <iostream>
using namespace std;

#define debug(x) cout << #x << " : " << x << endl;

int main()
{

    int n;
    cin >> n;

    int t = n / 2;
    debug(n);
    for (int i = -t; i <= t; i++)
    {

        int i_ = abs(i);

        for (int k = 1; k <= i_; k++)
            cout << " ";

        for (int j = 1; j <= n - 2 * i_; j++)
            cout << "*";

        cout << endl;
    }
}
