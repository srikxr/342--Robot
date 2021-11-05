#include <iostream>
#include "robot.h"
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    //assigning terminal input to struct values and variables
    GridPoint robot_position{atoi(argv[1]), atoi(argv[2])};
    GridPoint treasure_position{atoi(argv[3]), atoi(argv[4])};
    int max_distance = atoi(argv[5]);

    //call Robot constructor
    Robot(robot_position, treasure_position, max_distance);

}

