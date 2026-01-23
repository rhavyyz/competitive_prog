#include<bits/stdc++.h>

using namespace std;

class Solution {


    vector<vector<bool>> is_visited;
public:


    
    bool is_out_of_bounds(int pos_x, int pos_y) {
        return !(pos_x >= 0 && pos_y >= 0 && 
               pos_x < is_visited[0].size() && pos_y < is_visited.size());
    }
    int counting_islands_dfs(int pos_x, int pos_y, vector<vector<char>>& grid) {
     
        cout << pos_x << ' ' << pos_y << endl;

        if (pos_x == 3 && pos_y == 4){
            cout << is_out_of_bounds(pos_x, pos_y) << endl; 
            cout << is_visited[pos_y][pos_x] << endl;
            cout << (grid[pos_y][pos_x] == '0') << endl;
        }

        if ( 
             is_out_of_bounds(pos_x, pos_y) || 
             is_visited[pos_y][pos_x] ||
             grid[pos_y][pos_x] == '0'
           )
            return   cout << pos_x << ' ' << pos_y << endl, 0;
cout << pos_x << ' ' << pos_y << endl;
        is_visited[pos_y][pos_x] = true;

        counting_islands_dfs(pos_x + 1, pos_y, grid);
        counting_islands_dfs(pos_x - 1, pos_y, grid);
        counting_islands_dfs(pos_x, pos_y - 1, grid);
        counting_islands_dfs(pos_x, pos_y + 1, grid);

        return 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        is_visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

        cout << " aaai " << is_visited.size() << ' '  << is_visited[0].size() << endl;

        int numberOfIslands = 0;

        for(int y = 0; y < grid.size(); y++){

            for(int x = 0; x < grid[0].size(); x++){
                numberOfIslands+= counting_islands_dfs(x, y, grid);
            }
        }


        return numberOfIslands;
    }
};
int main()
{




    vector<vector<char>> grid = {
        {'1','1','0','0','1'},
        {'1','1','0','0','1'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution s;

    cout <<  s.numIslands(grid) << endl;;
    return 0;
}