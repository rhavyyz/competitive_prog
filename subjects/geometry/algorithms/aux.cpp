#include <bits/stdc++.h>
using namespace std;
/*

    Inicialmente vamos declarar as estruturas importantes que devemos ser capazes de representar

*/
#define int long long
// #define map unordered_map
#define endl '\n'
#define double long double


struct angle
{
    int start;
    vector<int> rotations;

    angle(){}
    angle(string & s)
    {
        char back = s.back();

        switch (back)
        {
        case 'S':
            this->start = 270;
            break;
        case 'N':
            this->start = 90;
            break;
        case 'W':
            this->start = 180;
            break;
        case 'E':
            this->start = 0;
            if(s.size() > 1&& s.end()[-2] == 'S')
                this->start =360;
            break;
        default:
            break;
        }

        if(s.size() == 1)
            return;

        vector<char> positive_axis_direction = {'S', 'E', 'N', 'W', 'S', 'E'};

        int back_direction = -1;

        for(int i = 1; i < positive_axis_direction.size() - 1; i++)
        {
            if(positive_axis_direction[i] == back)
            {
                if(positive_axis_direction[i-1] == s.end()[-2])
                    back_direction = 1;

                break;
            }
        }

        for(int i = s.size()-2; i >=0; i--)
        {
            if(s[i] == back)
                rotations.push_back(back_direction);
            else
                rotations.push_back(back_direction*-1);
        }


        // cout << endl << start << endl;
        // for(auto rot : rotations)
        //     cout << rot << ' ';
    }
    double to_angle()
    {
        double val = this->start;


        double base = 45;

        for(auto rot : this->rotations) 
        {
    
            // cout << rot << ' ' << base << endl;
            if(rot != 0)
                val += rot*base;
            base/=2;
        }

        if(val < 0)
            val *= -1;

        return val;
    }

};

int solve()
{
    string s1, s2;

    cin >> s1 >> s2;
 
    angle a1(s1), a2(s2);

    double ans = a1.to_angle() - a2.to_angle();

    // auto ans = (a1 - a2).to_angle();

    if(ans < 0)
        ans *=-1;
    
    if(ans > 180)
        ans = 360 - ans;
    
    cout << fixed << setprecision(7) <<  ans << endl;
    // cout << a1.to_angle() << ' ' << a2.to_angle();


    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}
