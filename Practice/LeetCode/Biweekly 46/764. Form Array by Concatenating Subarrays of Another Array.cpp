class Solution
{
public:
    int isPart(vector<int> &A, int l, int r, vector<int> &B)
    {
        int temp = l;
        while (temp <= r and A[temp] != B[0])
            temp++;
        l = temp;
        if (r - temp + 1 >= B.size())
        {
            int i = temp;
            int j = 0;
            for (i = l, j = 0; i <= r and j < B.size(); i++, j++)
                if (A[i] != B[j])
                    return isPart(A, l + 1, r, B);
            if (j == B.size())
                return i;
        }

        return -1;
    }

    bool canChoose(vector<vector<int>> &groups, vector<int> &nums)
    {

        int n = nums.size();
        int k = 0;
        for (int i = 0; i < groups.size(); i++)
        {
            k = isPart(nums, k, n - 1, groups[i]);
            if (k == -1)
                return false;
        }
        return true;
    }
};