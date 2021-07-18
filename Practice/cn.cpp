#include <iostream>
using namespace std;
class DynamicArray
{
    int *data;
    int capacity;
    int nextIndex;

public:
    DynamicArray()
    {
        data = new int[5];
        capacity = 5;
        nextIndex = 0;
    }
    void add(int element)
    {
        if (nextIndex == capacity)
        {
            int *newdata = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            capacity = capacity * 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    void print() const
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main() //main
{
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.print();
}