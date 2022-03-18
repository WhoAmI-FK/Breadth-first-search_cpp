// Unfinished, requires rework
#include <iostream>
#include <queue>
#include <utility>
#include <cstdlib>
#include "windows.h"

class MazeLabyrinth {
private:
	//x    y
	std::queue<std::pair<int, int>> _dungeon_master;
	char** _map;
	char* _line;
	size_t _sizeX, _sizeY;
	std::pair<int, int> _start;
	std::pair<int, int> _finish;
public:
	explicit MazeLabyrinth()
		:_sizeX(20),_sizeY(20),_map(nullptr),_line(nullptr)
	{
	}
	void setStart(const std::pair<int,int>& Num) {
		_start = Num;
	}
	void setFinish(const std::pair<int,int>& Num) {
		_finish = Num;
	}
	void resize(char* str, size_t& len,const size_t by) {
		char* tmp = new char[len + by];
		strcpy_s(tmp, len, str);
		len += by;
		delete[] _line;
		_line = tmp;
	}
	void enlargeMap(char** map, size_t& len) {
		// need to complete
	}
	void read_map() {
		int _y = 0;
		char c;
		c = getchar();
		while (true) {
			_line = new char[_sizeX];
			int _count = 0;
			fflush(stdin);
			while ((c = getchar()) != '\n') {
				if (_count == _sizeX) {
					resize(_line, _sizeX, 1);
				}
				_line[_count++] = c;
			}
			_line[_count] = '\0';
			if (_count < (_sizeX-1)) {
				resize(_line, _sizeX, _count - _sizeX);
			}
			if (_map == nullptr) {
				_map = new char* [_sizeY];
			}
			_map[_y] = _line;
			if (_map != nullptr && _y != 0) {
				if (strcmp((_map[0]), (_map[_y])) == 0) {
					break;
				}
			}
			_y++;
		}
		_sizeY = _y+1;
	}
	void draw_map() {
		for (int i = 0; i < _sizeY; ++i) {
			for (int j = 0; j < _sizeX; ++j) {
				std::cout << _map[i][j];
			}
			std::cout << std::endl;
		}
	}
	~MazeLabyrinth() {
		delete[] _line;
		delete[] _map;
	}
	void Start() {
		int input;
		std::cout << "Insert coordinates for S:\t";
		std::cin >> input;
		_start.first = input;
		std::cin >> input;
		_start.second = input;
		std::cout << "\nInsert coordinates for F:\t";
		std::cin >> input;
		_finish.first = input;
		std::cin >> input;
		_finish.second = input;
		std::cout << _finish.first << " " << _finish.second << std::endl;
		std::cout << "\nInsert map:\n";
		read_map();
		system("pause");
		system("cls");
		std::cout << "starting location (marked S): (" << _start.first << ", " << _start.second << ")\n";
		std::cout << "End location (marked F): (" << _finish.first << ", " << _finish.second << ")\n";
		_dungeon_master.push(_start);
		std::cout << "\n\nqueue: (" << _dungeon_master.front().first << ", " << _dungeon_master.front().second << ")\n\n";
		draw_map();
		begin_search();
	}
	void impossibleToReach() {
		std::cout << "\n\nThere is no proper way to reach the finish point.\n\n";
	}
	void move(int x, int y) {
		_map[y][x] = '.';
		_dungeon_master.push(std::pair<int, int>(x, y));
		std::cout << " (" << x << ", " << y << "), ";
	}
	void begin_search() {
		while (true) {
			if (_dungeon_master.empty()) {
				impossibleToReach();
				return;
			}
			else {
				int x, y;
				x = _dungeon_master.front().first;
				y = _dungeon_master.front().second;
				system("pause");
				system("cls");
				std::cout << "starting location (marked S): (" << _start.first << ", " << _start.second << ")\n";
				std::cout << "End location (marked F): (" << _finish.first << ", " << _finish.second << ")\n";
				std::cout << "\n\nqueue: ";
				if (_map[y][x + 1] == ' ' || _map[y][x+1]=='F') {
					move(x + 1, y);
				}
				if (_map[y][x - 1] == ' ' || _map[y][x-1]=='F') {
					move(x-1, y);
				} 
				if (_map[y - 1][x] == ' ' || _map[y-1][x] == 'F') {
					move(x, y-1);
				}
				if (_map[y + 1][x] == ' ' || _map[y+1][x]=='F') {
					move(x,y+1);
				}
				if (_dungeon_master.front().first == _finish.first && _dungeon_master.front().second == _finish.second) {
					system("pause");
					system("cls");
					draw_map();
					std::cout << "\n\nSuccess.\n\n";
					break;
				}
				_dungeon_master.pop();
				std::cout << "\n\n";
				draw_map();

			}
		}
	}
};


int main()
{
	MazeLabyrinth mzl;
	mzl.Start();
	return 0;
}
