#include <iostream>
#include <bits/stdc++.h>

int getRomanValue(char symbol)
{
    switch (symbol)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return -1;
    }
}

int romanToInt(string s)
{
    int currentValue, nextValue, res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        //set currentValue
        currentValue = getRomanValue(s[i]);

        //check and set for nextValue
        if (i != s.size() - 1)
        {
            nextValue = getRomanValue(s[i + 1]);
        }

        //logic to work with currentValue and nextValue
        if (i == s.size() - 1 || currentValue >= nextValue)
        {
            res += currentValue;
        }
        else if (currentValue < nextValue)
        {
            res += (nextValue - currentValue);
            ++i;
        }
    }

    return res;
}
