#include <iostream>
using namespace std;

class Solution
{

private:
    string sequence;
    string *allPossibleOutcomes;

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
    int size;
    Solution(int n, string *allPossibleOutcomes)
    {
        this->allPossibleOutcomes = allPossibleOutcomes;
        this->sequence.assign(2 * n, 0);
        this->size = 0;
        this->generate(0, n, n);
    }
};

int main()
{
    int n;
    cin >> n;

    string *str = new string[1500];

    Solution x(n / 2, str);

    cout << x.size << endl;

    for (int i = 0; i < 1500; i++)
        cout << str[i] << endl;
}