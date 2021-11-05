#include <iostream>
#include "robot.h"
#include <string>
#include <vector>
using namespace std;

vector <string> directions;

Robot::Robot()
{
    //empty constructor
}

//main constructor
Robot::Robot(const GridPoint robot_position, const GridPoint treasure_position, int max_distance)
{
    cout << "Shortest path: " << shortest_path(robot_position, treasure_position) << endl;
    
    string path_string;

    find_paths(robot_position.x, robot_position.y, 'Z', 0, path_string, max_distance, robot_position, treasure_position);
    for (string &s :directions)
    {
        cout << s << endl;
    }
    cout << "The number of paths are: " << directions.size() << endl;

}

//just for fun to display shortest path in the output
int Robot::shortest_path(const GridPoint robot_origin, const GridPoint treasure_position)
{
    int shortest_possible_distance = abs(robot_origin.x - treasure_position.x) + abs(robot_origin.y - treasure_position.y);
    return shortest_possible_distance;

}

//main recursive function
int Robot::find_paths(int current_x, int current_y, char previous_step, int steps_taken, string running_path, int max_distance, GridPoint robot_position, GridPoint treasure_position)
{
    
    // If robot moves more than max_distance consective times in one direction, it discards that path.
    if(steps_taken > max_distance) 
    {
        return -1;
    }
    //when we reach target, program stores the string of directions in a vector
    //base case
    if((current_x == treasure_position.x) && (current_y == treasure_position.y)) 
    {
        directions.push_back(running_path); //adding to vector "directions"
        return 0;
    }

    //north 
    if(treasure_position.y > current_y) 
    {
        if(previous_step == 'N') 
        {
            find_paths(current_x, current_y + 1, 'N', steps_taken + 1, running_path + 'N', max_distance, robot_position, treasure_position);
        }
        else 
        {
            find_paths(current_x, current_y + 1, 'N', 1, running_path + 'N', max_distance, robot_position, treasure_position);
        }
    }

    //south 
    else if(treasure_position.y < current_y) 
    {
        if(previous_step == 'S')
        {
            find_paths(current_x, current_y - 1, 'S', steps_taken + 1, running_path + 'S', max_distance, robot_position, treasure_position);
        }
        else
        { 
            find_paths(current_x, current_y - 1, 'S', 1, running_path + 'S', max_distance, robot_position, treasure_position);
        }
    }

    //east
    if(treasure_position.x > current_x) 
    {
        if(previous_step == 'E') 
        {
            find_paths(current_x + 1, current_y, 'E', steps_taken + 1, running_path + 'E', max_distance, robot_position, treasure_position);
        }
        else
        {
            find_paths(current_x + 1,  current_y, 'E', 1, running_path + 'E', max_distance, robot_position, treasure_position);
        }
    }

    //west
    else if (treasure_position.x < current_x) 
    {
        if(previous_step == 'W')
        {
            find_paths(current_x - 1,  current_y, 'W', steps_taken + 1, running_path + 'W', max_distance, robot_position, treasure_position);
        }
        else 
        {
            find_paths(current_x - 1,  current_y, 'W', 1, running_path + 'W', max_distance, robot_position, treasure_position);
        }
    }
   return 1;
}