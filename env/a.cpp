#include <bits/stdc++.h>

using std::vector, std::string, std::map, std::pair;


struct city_info {
    string name;
    int x, y;
};

std::vector<std::string> nearest_cities(std::vector<city_info> cities, std::vector<std::string> queries) {

    map<string, city_info> name_to_info;
    map<int, vector<pair<int, string>>> grouped_by_y, grouped_by_x;

    //
    // [1, 10]
    // [1, 5]
    // [1, 3]
    //

    //     |
    // [3, 5, 10]

    for(auto city : cities) {
        name_to_info[city.name] = city;

        grouped_by_x[city.x].push_back({ city.y, city.name });
        grouped_by_y[city.y].push_back({ city.x, city.name } );
    }

    for(auto & [cord, neighbours] : grouped_by_x) {
        std::sort( neighbours.begin(), neighbours.end());
    }

    for(auto & [cord, neighbours] : grouped_by_y) {
        std::sort( neighbours.begin(), neighbours.end());
    }

    vector<string> response;
    for(string query : queries) {

        city_info info = name_to_info[query];
        int x = info.x, y = info.y;        

        int city_position_x = std::lower_bound( grouped_by_x[x].begin(), grouped_by_x[x].end(), y) - grouped_by_x[x].begin();
        int city_position_y = std::lower_bound( grouped_by_y[y].begin(), grouped_by_y[y].end(), x) - grouped_by_y[y].begin();

        int nearest_with_same_x = -1,  nearest_with_same_y = -1; 
        string name_of_nearest_with_same_x = "",  name_of_nearest_with_same_y = ""; 

    // x = 1
    //     |  
    // [3, 5, 10]

        if(city_position_x != 0){
            nearest_with_same_x =  y - grouped_by_x[x][city_position_x-1].first;
            name_of_nearest_with_same_x =  grouped_by_x[x][city_position_x-1].second;
        }

        if(city_position_y != 0) {
            nearest_with_same_y = x - grouped_by_y[x][city_position_y-1].first;
            name_of_nearest_with_same_y =  grouped_by_y[y][city_position_y-1].second;
        }

        if(city_position_x != grouped_by_x[x].size()-1 && 
           nearest_with_same_x != -1 && 
           grouped_by_x[x][city_position_x+1].first - y < nearest_with_same_x) {
            
            nearest_with_same_x = grouped_by_x[x][city_position_x+1].first - y;
            name_of_nearest_with_same_x =  grouped_by_x[x][city_position_x-1].second;
        }
        
        else if(city_position_x != grouped_by_x[x].size()-1 && 
                nearest_with_same_x == -1 && 
                grouped_by_x[x][city_position_x+1].first - y < nearest_with_same_x) {
            nearest_with_same_x = grouped_by_x[x][city_position_x+1].first - y; 
            name_of_nearest_with_same_x =  grouped_by_x[x][city_position_x-1].second;
        }
        

        if(city_position_y != grouped_by_y[y].size()-1 && 
           nearest_with_same_y != -1 && 
           grouped_by_x[y][city_position_y+1].first - x < nearest_with_same_y) {
            
            nearest_with_same_y = grouped_by_y[y][city_position_y+1].first - x;
            name_of_nearest_with_same_y =  grouped_by_x[y][city_position_y-1].second;
        }
        
        else if(city_position_y != grouped_by_y[y].size()-1 && 
                nearest_with_same_y == -1 && 
                grouped_by_x[y][city_position_y+1].first - x < nearest_with_same_y) {
            nearest_with_same_y = grouped_by_y[y][city_position_y+1].first - x; 
            name_of_nearest_with_same_y =  grouped_by_y[y][city_position_y-1].second;
        }
        
        if (nearest_with_same_x == -1 && nearest_with_same_y == -1) {
            response.push_back("");
        } else {
            if (nearest_with_same_x < nearest_with_same_y)
                response.push_back(name_of_nearest_with_same_x);
            else
                response.push_back(name_of_nearest_with_same_y);
        }
    }

    return response;
}


int main() {


    return 0;
}

