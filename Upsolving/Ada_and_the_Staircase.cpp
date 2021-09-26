#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int n;
        cin >> n;

        int k;
        cin >> k;

        vector<int> Heights(n);
        for (int i = 0; i < n; i++)
        {
            cin >> Heights[i];
        }

        int minStepsToBeAdded = 0;
        int prevHeight = 0;
        for (int i = 0; i < n; i++)
        {
            int currentHeight = Heights[i];

            if (currentHeight - prevHeight > k)
            {
                if ((currentHeight - prevHeight) % k == 0)
                {
                    minStepsToBeAdded += (((currentHeight - prevHeight)) / k) - 1;
                }
                else
                {
                    minStepsToBeAdded += ((currentHeight - prevHeight)) / k;
                }
            }

            prevHeight = currentHeight;
        }

        cout << minStepsToBeAdded << "\n";
    }
}
