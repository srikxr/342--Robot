#ifndef ROBOT_H_
#define ROBOT_H_

#include <vector>
using namespace std;

struct GridPoint
{
    int x, y;
};


class Robot
{

public:
    vector<string> directions;

    Robot();
    Robot(const GridPoint robot_position, const GridPoint treasure_position, int max_distance);
    int shortest_path(const GridPoint robot_origin, const GridPoint treasure_position);
    int find_paths(int current_x, int current_y, char prev, int shortest_path, string running_path, int max_distance, GridPoint robot_position, GridPoint treasure_position);


private:

    GridPoint robot_position_;
    GridPoint treasure_position_;

    vector<string> directions_;
    int max_distance_;

    string current_path_;

    
};
#endif