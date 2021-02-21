class Solution
{
public:
    bool isNice(string &s, int low, int high)
    {

        bool F1[26] = {0};
        bool F2[26] = {0};

        for (int i = low; i <= high; i++)
            if (s[i] >= 'a' and s[i] <= 'z')
                F1[s[i] - 'a'] = 1;
            else
                F2[s[i] - 'A'] = 1;

        for (int i = 0; i < 26; i++)
            if (F1[i] ^ F2[i])
                return false;

        return true;
    }

    string longestNiceSubstring(string &s)
    {
        int n = s.length();
        for (int length = n; length >= 2; length--)
            for (int l = 0; l + length - 1 < n; l++)
                if (isNice(s, l, l + length - 1))
                    return s.substr(l, length);
        return "";
    }
};