#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int max_index = 8;

void trun_gaer(int gear_index, int index_direction, int rotate_direction);
void trun_gaer_first(int gear_index, int index_direction, int rotate_direction);

struct Gear {
	string cog;
	int head_index = 0;
};

Gear gears[4];

int main() {
	for (int i = 0; i < 4; i++) 
	{
		cin >> gears[i].cog;
	}

	int t;
	cin >> t;

	int gear_index, rotation_direction;
	while (t > 0) {
		cin >> gear_index >> rotation_direction;

		trun_gaer_first(gear_index, 1, rotation_direction);
		trun_gaer_first(gear_index, -1, rotation_direction);

		//rotate now gear
		gears[gear_index].head_index += rotation_direction;
		gears[gear_index].head_index += 8;
		gears[gear_index].head_index %= 8;
		t--;
	}

	int result = 0;
	for (int i = 0; i < 4; i++) {
		if (gears[i].cog[gears[i].head_index] == '0') {
			result += pow(2, i);
		}
	}

	cout << result;

	return 0;
}

void trun_gaer(int gear_index, int index_direction, int rotate_direction) {
	if (gear_index + index_direction >= 0 and gear_index + index_direction <= 3) {
		//오른쪽 기어와 비교
		if (index_direction > 0) {
			//현재 기어의 R과 옆 기어의 L을 비교
			int right = (gears[gear_index].head_index + 2) % max_index;
			int left = (gears[gear_index + index_direction].head_index + 6) % max_index;

			if (gears[gear_index].cog[right] != gears[gear_index + index_direction].cog[left]) {
				trun_gaer(gear_index + index_direction, index_direction, rotate_direction * (-1));
			}
		}
		else {
			//현재 기어의 L과 옆 기어의 R을 비교
			int left = (gears[gear_index].head_index + 6) % max_index;
			int right = (gears[gear_index + index_direction].head_index + 2) % max_index;

			if (gears[gear_index].cog[left] != gears[gear_index + index_direction].cog[right]) {
				trun_gaer(gear_index + index_direction, index_direction, rotate_direction * (-1));
			}
		}
	}

	//rotate now gear
	gears[gear_index].head_index += rotate_direction;
	gears[gear_index].head_index += 8;
	gears[gear_index].head_index %= 8;
}

void trun_gaer_first(int gear_index, int index_direction, int rotate_direction) {
	if (gear_index + index_direction >= 0 and gear_index + index_direction <= 3) {
		//오른쪽 기어와 비교
		if (index_direction > 0) {
			//현재 기어의 R과 옆 기어의 L을 비교
			int right = (gears[gear_index].head_index + 2) % max_index;
			int left = (gears[gear_index + index_direction].head_index + 6) % max_index;

			if (gears[gear_index].cog[right] != gears[gear_index + index_direction].cog[left]) {
				trun_gaer(gear_index + index_direction, index_direction, rotate_direction * (-1));
			}
		}
		else {
			//현재 기어의 L과 옆 기어의 R을 비교
			int left = (gears[gear_index].head_index + 6) % max_index;
			int right = (gears[gear_index + index_direction].head_index + 2) % max_index;

			if (gears[gear_index].cog[left] != gears[gear_index + index_direction].cog[right]) {
				trun_gaer(gear_index + index_direction, index_direction, rotate_direction * (-1));
			}
		}
	}
}