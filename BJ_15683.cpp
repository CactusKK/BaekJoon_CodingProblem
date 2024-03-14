#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char map[8][8];

vector<pair<int, int>> laser_direction = {
    {1, 0},{0, 1},{-1, 0},{0, -1}
};

vector<vector<vector<int>>> camera_direction = { //[kind of camera] [kind of camera's laser] [kind of laser]
    {
        {
            {0},
            {1},
            {2},
            {3}
        }
    }, // 1
    {
        {
            {0, 2},
            {1, 3}
        }
    },// 2
    {
        {
            {0, 1},
            {1, 2},
            {2, 3},
            {3, 0}
        }
    },// 3
    {
        {
            {0, 1, 2},
            {1, 2, 3},
            {2, 3, 0},
            {3, 0, 1}
        }
    },// 4
    {
        {
            {0, 1, 2, 3 }
        }
    }// 5
};

vector<pair<int, int>> cameras;


void shot_laser(pair<int, int> position, pair<int, int> direction);


int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] != 0 and map[i][j] != 6) {
                cameras.push_back(make_pair(i, j));
            }
        }
    }



	return 0;
}


void shot_laser( pair<int, int> position, pair<int, int> direction ) {

}