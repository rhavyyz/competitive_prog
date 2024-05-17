#include<bits/stdc++.h>

using namespace std;

/*

    K has its own absolutelly different behavior in relation to the other letters
    So we handle its case with an IF
    To other letter we have two cases 
        - letters before K in alphabetical order
        - letters after K in aplhabetical order
    
    the difference between these two cases is just:
        Letters before K will be placed accourding to their position in the alphabeth 
        While letters after K will be placed accourding to thier position in the 
        alphabeth - 1 because by removing k we place every other letter that comes after
        a position "earlier"


    So let c beeing any letter after K, we can operate over c as a letter that comes
    before K by just doing c = c-1

    So lets define the behavior for the letter from 1 to 25:
        "Drawing" the matrix 5x5 that the problem states and assuming we place 
        the values in the alphabetical order without jumping the 11°:

        1 2 3 4 5 6 7 8 9 10 11 12 1

        0: 0  1  2  3  4
        1: 5  6  7  8  9
        2: 10 11 12 13 14
        3: 15 16 17 18 19
        4: 20 21 22 23 24

        Is easy to se that in the ith row we place the elements in the following order 
        (consider we start at the row 0 and go until 4):

        (i*5 + 1), (i*5 + 2), (i*5 + 3), (i*5 + 4), (i*5 + 5)

        So let c be the position in the alphabeth (with this before and after thing already fixed). 
        With that we can generate the row we are placed by doing

        row = (c-1)/5 + 1

        and for the column value

        col = (c-1)%5 + 1

        (if we set the order begining with 0 intead of 1 we can cut these -1s and that is what i did
        in the code)

*/

int main()
{
    int n; cin >> n;

    string s; cin >> s;

    for(char c : s)
    {
        c-='A';

        

        if(c == 'K'-'A')
        {
            cout << "* *** ";
            continue;
        }
        else if(c > 'K'-'A')
            c--;

        int row = (c / 5) + 1;
        int column = (c % 5) + 1;

        while(row--)
            cout << '*';
        cout << ' ';
        while(column--)
            cout << '*';
        cout << ' ';
    }

    cout << endl;

    return 0;
}