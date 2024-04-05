#include <iostream>

#include <stack>

#include <fstream>

#include <string>

using namespace std;

bool delimitersOk(const string &expression)
{
    stack<char>chr;

    for(char ch: expression)
    {
        if(ch == '(' || ch == '[')
        {
            chr.push(ch);
        }
        else if(ch == ')' || ch == ']')
        {
            if(chr.empty() || (ch == ')' && chr.top() != '(') || (ch == ']' && chr.top() != '['))
            {
                return false;
            }
            else
            {
                chr.pop();
            }
        }
    }
    return chr.empty();
}

int main()
{
    ifstream inf("input.txt");

    if(!inf)
    {
        cout << "Error!!";
    }

    else
    {
        int totalWords;

        inf >> totalWords;
        for(int i = 0; i < totalWords; i++)
        {
            string words;

            inf >> words;

            if(delimitersOk(words))
            {
                cout << "valid" << endl;
            }
            else
            {
                cout << "invalid" << endl;
            }
        }
    }

    inf.close();
    return 0;
}