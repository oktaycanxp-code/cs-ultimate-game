#include "map.h"

Map::Map() : Map(20, 20) {}

Map::Map(int width, int height) : width(width), height(height) {
    tiles.resize(height, std::vector<MapCell>(width));
    generateDefaultArena();
}

void Map::generateDefaultArena() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            tiles[y][x] = {true, false, false, false};
        }
    }

    for (int x = 0; x < width; ++x) {
        tiles[0][x].walkable = false;
        tiles[height - 1][x].walkable = false;
    }
    for (int y = 0; y < height; ++y) {
        tiles[y][0].walkable = false;
        tiles[y][width - 1].walkable = false;
    }

    for (int x = 4; x < 8; ++x) {
        tiles[4][x].wall = true;
        tiles[4][x].walkable = false;
        tiles[15][x].wall = true;
        tiles[15][x].walkable = false;
    }

    addBombSite(4, 10);
    addBombSite(15, 10);
}

void Map::addWall(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        tiles[y][x].wall = true;
        tiles[y][x].walkable = false;
    }
}

void Map::addBombSite(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        tiles[y][x].bombSite = true;
    }
}

bool Map::isWalkable(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) return false;
    return tiles[y][x].walkable;
}

bool Map::isBombSite(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) return false;
    return tiles[y][x].bombSite;
}
