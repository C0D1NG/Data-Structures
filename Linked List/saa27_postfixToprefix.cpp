// Program in C++ to convert postfix to prefix

#include <bits/stdc++.h>
using namespace std;

// function to convert postfix to prefix expression
void postfixToPrefix(string s)
{
    stack<string> st;

    int length = s.size();

    for (int i = 0; i < length; i++)
    {

        //to check if the scanned character is an operator
        if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
        {

            //to pop the top two operands of the stack 'st'
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();

            //now we will concat the popped operands with the operator
            string temp = s[i] + operand2 + operand1;

            //the concatenated string will be pushed into the stack 'st' again
            st.push(temp);
        }

        //to check if the scanned character is an operand
        else
        {
            //we will just push the operand in the stack
            st.push(string(1, s[i]));
        }
    }

    string ans = "";
    while (!st.empty())
    {
        ans += st.top();//now concatenating all the elements in the stack
        st.pop();//and then popping out the top of the stack
    }
    cout << ans;//final prefix expression
}

// Driver Code
int main()
{
    string exp = "ACD+/EL-*";

    postfixToPrefix(exp);
    return 0;
}