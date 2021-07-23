#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testCases;
    cin >> testCases;

    while (testCases--)
    {

        int bobMaxCandies;
        int limakMaxCandies;

        cin >> limakMaxCandies >> bobMaxCandies;

        int candiesToBeEaten = 1;

        while (true)
        {
            if (candiesToBeEaten % 2 == 0)
            {

                if (bobMaxCandies < candiesToBeEaten)
                {
                    cout << "Limak\n"; // Limak Wins
                    break;
                }
                else
                {
                    bobMaxCandies -= candiesToBeEaten;
                }
            }
            else
            {
                if (limakMaxCandies < candiesToBeEaten)
                {
                    cout << "Bob\n"; // Bob Wins
                    break;
                }
                else
                {
                    limakMaxCandies -= candiesToBeEaten;
                }
            }
            candiesToBeEaten++;
        }
    }
}
