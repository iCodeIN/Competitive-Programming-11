

// // // cin
// // // It is used to read a word or character.
// // // It terminates on encountering whitespace or endline charater (’\n’)

// // // cin.get(char_array,number_of_characters,delimiter)
// // // To read characters including special characters like ’ ', ‘\n’ and ‘\t’.

// // // cin.getline(char_array,max_Size,delimiter)
// // // It is used to read a sentence or a paragraph.
// // // It terminates on encountering endline character.
// // // It also reads the whitespace.

// // // Difference?

// // // The get() function is much like getline() but rather than read and discard the newline character, get() leaves that character in the input queue.

// // // get() leaves the delimiter in the queue thus letting you able to consider it as part of the next input.

// // // Explanation:
// // // cin.getline() reads input up to ‘\n’ and stops

// // // cin.get() reads input up to ‘\n’ and keeps ‘\n’ in the stream

// // // For example :

// // char str1[100];
// // char str2[100];
// // cin.getline(str1, 100);
// // cin.get(str2, 100);
// // cout << str1 << " " << str2;

// // input : 1 2 3 4 output 1 2 3 4 // the output expexted

// //     When reverse them
// //         For example :

// //     char str1[100];
// // char str2[100];
// // cin.get(str2, 100);
// // cin.getline(str1, 100);
// // cout << str1 << " " << str2;

// // input : 1 2 3 4 output 1 2 // the output unexpexted because cin.getline() read the ‘\n’

// //     // Usage:
// //     // If you are talking about the newline character from a console input, it makes perfect sense to discard it, but if we consider input from a file, you can use as “delimiter” the beginning of the next field.

// //     // Hope, this would help.
// //     // Give a like, if you are satisfied.

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     char str1[100];
//     char str2[100];

//     // cin.get(str1,100); // aaaa bbbb
//     // cin.get(str2,100); // (empty)

//     cin.getline(str1,100); // aaaa bbbb
//     cin.getline(str2,100); // cccc

//     cout << "str1 = " << str1 << endl;
//     cout << "str2 = " << str2 << endl;
//     return 0;
// }

// // get and getLine functions => defined only for char arrays
// //                             (Not defined for string class)

// // We should avoid get and use get line
// // if we want to take input of strings having spaces

// // cin <- cin.getLine()

#include <bits/stdc++.h>
using namespace std;

int main()
{
    char n;
    n = cin.get();
    int number = 0;
    int charac = 0;
    int spaces = 0;
    while (n != '$')
    {
        if (n >= 'a' && n <= 'z')
        {
            charac++;
        }
        else if (n == 32 || n == 10 || n == 9)
        {
            spaces++;
        }
        else if (n >= 48 && n <= 57)
        {
            number++;
        }
        n = cin.get();
    }
    cout << charac << " " << number << " " << spaces;
}