class Solution
{
public:
    int solve(string &s, int low, int high, vector<int> &mp)
    {
        int ans = 0;
        for (int i = low; i < high;)
        {
            if (s[i] == '(' and s[i + 1] == ')')
                ans++, i += 2;
            else
            {
                int smallAns = solve(s, i + 1, mp[i] - 1, mp);
                ans += 2 * smallAns;
                i = mp[i] + 1;
            }
        }

        return ans;
    }

    int scoreOfParentheses(string &s)
    {
        int len = s.length();

        vector<int> mp(len, -1);
        stack<int> st;

        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                int j = st.top();
                st.pop();
                mp[j] = i;
            }
        }

        return solve(s, 0, len - 1, mp);
    }
};