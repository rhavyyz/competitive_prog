#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n; cin >> n;

    while(n--)
    {
        string s; cin >> s;


        stack<char> pilha;

        bool ok = true;

        for(char c : s)
        {
            if(c == '(' || c== '{'|| c== '[')
            {
                pilha.push(c);
                continue;
            }

            if(pilha.size() == 0)
            {
                ok = false;
                break;
            }
            char top = pilha.top();
            
            if(top == '{' && c == '}' )
            {
                pilha.pop();
                continue;
            }


            if(top == '[' && c == ']')
            {
                pilha.pop();
                continue;
            }


            if(top == '(' && c == ')' )
            {
                pilha.pop();
                continue;
            }

            ok = false;
            break;

        }

        if(pilha.size())
            ok = false;

        if(ok)
            cout << 'S' << endl;

        else
            cout << 'N' << endl;

    }

    return 0;
}