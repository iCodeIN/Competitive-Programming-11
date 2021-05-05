void mergeTwoSortedArrays(int input[], int si, int ei)
{
    int size = ei - si + 1;
    int mid = (si + ei) / 2;
    int *output = new int[size];
    int i = si;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= ei)
    {
        if (input[i] < input[j])
        {
            output[k] = input[i];
            k++;
            i++;
        }
        else
        {
            output[k] = input[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        output[k] = input[i];
        i++;
        k++;
    }
    while (j <= ei)
    {
        output[k] = input[j];
        j++;
        k++;
    }

    int m = 0;
    for (int i = si; i <= ei; i++)
    {
        input[i] = output[m];
        m++;
    }
    delete[] output;
}

void mergeSort_helper(int input[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = (si + ei) / 2;
    mergeSort_helper(input, si, mid);
    mergeSort_helper(input, mid + 1, ei);

    mergeTwoSortedArrays(input, si, ei);
}

void mergeSort(int input[], int size)
{
    return mergeSort_helper(input, 0, size - 1);
}

int tripletSum(int input[], int size, int x)
{
    mergeSort(input, size);
    int c = 0;
    for (int k = 0; k < size - 3; k++)
    {
        x = size - input[k];
        int i = x + 1;
        int j = size - 1;
        /*if(input[i]+input[j]<x){
                i++;
            }
      if(input[i]+input[j]>x){
                j--;
            }*/

        while (i < j)
        {

            if (input[i] + input[j] == x)
            {
                if (input[i] == input[j])
                {
                    int n = 0;
                    int j1 = j, i1 = i;
                    while (1)
                    {
                        if (input[j1] == input[j])
                        {
                            j1--;
                            n++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    j = j1;
                    i = i1;
                    c = c + (n * (n - 1)) / 2;
                }
                int m = 0;
                int n = 0;
                int j1 = j, i1 = i;
                while (1)
                {
                    if (input[j1] == input[j])
                    {
                        j1--;
                        m++;
                    }
                    else
                    {
                        break;
                    }
                }

                while (1)
                {
                    if (input[i1] == input[i])
                    {
                        i1++;
                        n++;
                    }
                    else
                    {
                        break;
                    }
                }

                i = i1;
                j = j1;

                c = c + (m * n);
            }
            else if (input[i] + input[j] < x)
            {
                i++;
            }
            else if (input[i] + input[j] > x)
            {
                j--;
            }
        }
    }

    return c;
}
