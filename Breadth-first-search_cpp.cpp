#include <iostream>
#include <queue>
#include <utility>
#include <cstdlib>
class MazeLabyrinth {
private:
	//x    y
	std::queue<std::pair<int, int>> _dungeon_master;
	char** _map;
	char* _line;
	int _sizeX, _sizeY;
public:
	MazeLabyrinth()
		:_sizeX(20),_sizeY(20),_map(nullptr),_line(nullptr)
	{

	}
	void read_map() {
		while (true) {
			_line = new char[_sizeX];
			int _count = 0;
			char c;
			while ((c=getchar())!='\n') {
				_line[_count++] = c;
			}
			
		}
	}
	void draw_map() {

	}
};


int main()
{
	MazeLabyrinth mzl;
	mzl.read_map();
	return 0;
}
