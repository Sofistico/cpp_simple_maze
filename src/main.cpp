#include <iostream>
#include <random>

const char WALL = '#';
const char FLOOR = '.';
const int WIDTH = 10;
const int HEIGHT = 10;
const int MAX_MAP_SIZE = WIDTH * HEIGHT;

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

tile* initialize_map() {
    static tile tiles[MAX_MAP_SIZE]{};
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int i = get_index(x, y);
            tiles[i] = {x, y, true};
            std::cout << tiles[i].return_tile();
        }
        std::cout << '\n';
    }

    return tiles;
}

int main() {
    // pointer to an array
    tile* tiles = initialize_map();
    
    return 0;
}
