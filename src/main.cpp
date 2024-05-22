#include <iostream>
#include <random>

const char WALL = '#';
const char FLOOR = '.';
const int WIDTH = 50;
const int HEIGHT = 50;
const int MAX_MAP_SIZE = WIDTH * HEIGHT;
const int MAX_ROOMS = 4;
const int MAX_ROOM_SIZE = 8;
const int MIN_ROOM_SIZE = 4;

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

int get_x(int i) {
    return i / WIDTH;
}
int get_y(int i) {
    return i % WIDTH;
}

tile* initialize_map() {
    static tile tiles[MAX_MAP_SIZE]{};
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int i = get_index(x, y);
            tiles[i] = {x, y, true};
            // std::cout << tiles[i].return_tile();
        }
        // std::cout << '\n';
    }

    return tiles;
}

void create_rooms(tile* arr) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        int randomInt = std::rand() % MAX_MAP_SIZE;
        int size = (std::rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1)) + MIN_ROOM_SIZE;
        int x = get_x(randomInt);
        int y = get_y(randomInt);
        int max_x = x + size;
        int max_y = y + size;

        // Ensure max_x and max_y do not exceed map boundaries
        if (max_x > WIDTH) {
            max_x = WIDTH;
        }
        if (max_y > HEIGHT) {
            max_y = HEIGHT;
        }
        for (int xi = x; xi < max_x; xi++) {
            for (int yi = y; yi < max_y; yi++) {
                int index = get_index(xi, yi);
                tile* tile = arr + index;
                tile->is_wall = false;
            }
        }
    }
}

void print_map(tile* arr) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int i = get_index(x, y);
            std::cout << arr[i].return_tile();
        }
        std::cout << '\n';
    }
}

int main() {
    // pointer to an array
    tile* tiles = initialize_map();
    create_rooms(tiles);
    print_map(tiles);
    std::getchar();
    return 0;
}
