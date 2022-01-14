#include <iostream>
using namespace std;

class Solution
{
private:
    string sequence;
    string *allPossibleOutcomes;
    int size;

    void generate(int position, int remaining_8, int remaining_9)
    {
        if (remaining_8 == 0 and remaining_9 == 0)
        {
            allPossibleOutcomes[size] = sequence;
            size++;
            return;
        }

        if (remaining_8 > 0)
        {
            sequence[position] = '8';
            generate(position + 1, remaining_8 - 1, remaining_9);
        }

        if (remaining_9 > remaining_8)
        {
            sequence[position] = '9';
            generate(position + 1, remaining_8, remaining_9 - 1);
        }
    }

public:
    Solution(int n, string *allPossibleOutcomes)
    {
        this->allPossibleOutcomes = allPossibleOutcomes;
        this->sequence.assign(2 * n, 0);
        this->size = 0;
        this->generate(0, n, n);
    }
};

// Read only Refion starts
struct Result
{
    string *output1;
};

struct Result Play(int input1)
{
    // Read only Region ends
    Result ans;
    ans.output1 = new string[100];
    if (input1 % 2 == 0)
    {
        int n = input1 / 2;
        Solution(n, ans.output1);
    }
    return ans;
}