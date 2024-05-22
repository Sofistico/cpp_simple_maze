#include <iostream>
#include <random>

const char WALL = '#';
const char FLOOR = '.';
const int WIDTH = 10;
const int HEIGHT = 10;

struct tile {
    int x, y;
    // true is wall and false is floor
    bool is_wall;
    tile(int x, int y, bool is_wall) : x(x), y(y), is_wall(is_wall) {};
    tile() {};

    inline const char return_tile() {
        return is_wall ? WALL : FLOOR;
    };
};

int get_index(int x, int y) {
    return x + (WIDTH * y);
}

int main() {
    tile *tiles[WIDTH * HEIGHT] = {};
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int i = get_index(x, y);
            tiles[i] = new tile{x, y, static_cast<bool>(std::rand() % 2)};
            std::cout << tiles[i]->return_tile();
        }
		std::cout << '\n';
    }

    return 0;
}
