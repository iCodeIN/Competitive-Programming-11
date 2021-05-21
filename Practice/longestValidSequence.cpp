class Solution
{
public:
    int calculate(string &s, int i, vector<int> &dp, vector<int> &closed)
    {
        int st = 0;
        int cur = 0;
        int n = s.length();

        while (i < n)
        {
            if (s[i] == '(')
                st++;
            else
            {
                if (st == 0)
                    return 0;
                else
                    st--;
            }
            cur++;
            i++;
            if (st == 0)
                return dp[i] + cur;
            else if (st > closed[i])
                return 0;
        }
        return 0;
    }

    int longestValidParentheses(string &s)
    {

        int ans = 0;
        int n = s.length();

        vector<int> dp(n + 1, 0);
        vector<int> closed(n + 1, 0);

        for (int i = s.length() - 1; i >= 0; i--)
        {
            dp[i] = calculate(s, i, dp, closed);
            ans = max(ans, dp[i]);
            closed[i] = closed[i + 1] + (s[i] == ')');
        }
        return ans;
    }
};