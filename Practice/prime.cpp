#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool divided = false;
    
    for (int d = 2; d <= n - 1; d++)
    {
        if (n % d == 0)
        {
            divided = true;
        }
    }

    if (divided == true)
    {
        cout << "Not prime" << endl;
    }
    else
    {
        cout << "prime" << endl;
    }
}