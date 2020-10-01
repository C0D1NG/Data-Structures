#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char str1[100], str2[100];
    int i, j, length = 0, flag = 0;
    cin >> str1;
    length = strlen(str1) - 1;
    for (i = len, j = 0; i >= 0; i--, j++)
        str2[j] = str1[i];
    if (strcmp(str1, str2))
        flag = 1;
    if (flag == 1)
        cout << str1 << " is not a palindrome." << endl;
    else
        cout << str1 << " is a palindrome." << endl;
    return 0;
}