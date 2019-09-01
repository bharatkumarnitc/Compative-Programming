// Note that here we use std::stack  for Stack operations
#include<bits/stdc++.h>
using namespace std;
int length(char input[])
{
int i=0;
while(input[i])
i++; return i;
}
//function to return priority of operators
int priority(char c)
{
    if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1; } // returns the value when a specific operator operates on two operands
    int evaluate(int op1, int op2, char operate)
    {
        switch (operate)
    {
        case '*': return op2 * op1;
        case '/': return op2 / op1;
        case '+': return op2 + op1;
        case '-': return op2 - op1; default : return 0;
        }
        }
    // convert infix expression to postfix expression
void infixtopostfix(char *input)
    {
        stack<char> s;
        int len = length(input),index=0;
        char output[1000];
        for(int i = 0; i < len; i++)
            {
                if((input[i] >= '0' && input[i] <= '9'))
                {
                    output[index++] = input[i];
                    }
        else if(input[i] == '(')
        {
                    s.push('(');
        }
        else if(input[i] == ')')
        {
            // if the scanned character is an ‘)’, pop and to output string from the stack until an ‘(‘ is encountered.
         while(!s.empty() && s.top() != '(')
               {
                   char c = s.top();
        s.pop();
        output[index++] = c;
        }
        if(s.top() == '(')
             {

                 char c = s.top();
                 s.pop();
                 }
                 }
                 else
                    {
                            while(!s.empty() && priority(input[i]) <= priority(s.top()))
                            { char c = s.top(); s.pop(); output[index++]= c;
                     }
                     s.push(input[i]);
                 }
                 } //pop all the remaining elements from the stack
                 while(!s.empty())
                    {
                        char c = s.top();
                 s.pop(); output[index++] = c;
                 }
                 output[index] = '\0';
                 cout << output << "\n"; //copying to change input expression from calling function evaluatepostfix
                 int i=0;
                 while(i < length(output))
                    {
                        input[i] =
                        output[i]; i++;
                        } input[i] = '\0';
                 }
void evalpostfix(char postfix[])
{
stack<int> s; int i = 0;
char ch;
int val;
int len = length(postfix);
while (i < len)
{
 ch = postfix[i];
 if (isdigit(ch))
 {
     s.push(ch-'0');
    }
    else
    {
        int op1 = s.top();
        s.pop();
        int op2 = s.top();
        s.pop();
        val = evaluate(op1, op2, ch);
        s.push(val);
        }
        i++;
        }
        cout << val;
        }
void evaluatePostfix(char exp[])
{
infixtopostfix(exp);
evalpostfix(exp);
}
//Driver program to test above functions
int main()
{
    char exp[1000];
    cin >> exp;
    evaluatePostfix(exp);
    return 0;
}
