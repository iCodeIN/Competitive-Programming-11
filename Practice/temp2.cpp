#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(long long int numerator, long long int denominator)
    {

        if (numerator == 0)
        {
            return "0";
        }

        bool isPointIntroduced = false;
        string s = "";
        unordered_map<long long int, long long int> mp;
        bool numNeg = (numerator < 0);
        bool denNeg = (denominator < 0);

        numerator = abs(numerator);
        denominator = abs(denominator);

        while (1)
        {

            if (numerator < denominator)
            {
                if (isPointIntroduced)
                {
                    numerator *= 10;
                    s += '0';
                }
                else
                {
                    if (s.size() == 0)
                    {
                        s += '0';
                    }
                    s += '.';
                    numerator *= 10;
                    isPointIntroduced = true;
                }
            }
            else
            {

                if (numerator % denominator == 0)
                {
                    s += to_string(numerator / denominator);
                    if (numNeg ^ denNeg)
                    {
                        s = '-' + s;
                    }
                    return s;
                }
                else if (mp.count(numerator) > 0)
                {
                    s.insert(mp[numerator], "(");
                    s += ')';
                    if (numNeg ^ denNeg)
                    {
                        s = '-' + s;
                    }
                    return s;
                }
                else
                {
                    mp[numerator] = s.length();
                    s += to_string(numerator / denominator);
                    numerator %= denominator;
                    if (isPointIntroduced)
                        numerator *= 10;
                }
            }
        }
    }
};
