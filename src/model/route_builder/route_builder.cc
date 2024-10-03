#include "route_builder.h"

namespace s21 {
RouteBuilder &RouteBuilder::getInstance() {
  static RouteBuilder instance;
  return instance;
}

Route RouteBuilder::buildRoute(const Maze &maze, int fromX, int fromY, int toX,
                               int toY) {
  std::vector<std::vector<int>> map = buildMap(maze, toX, toY);
  Route result = readMap(map, fromX, fromY);
  return result;
}

Route RouteBuilder::readMap(const std::vector<std::vector<int>> &map, int fromX,
                            int fromY) {
  Route result;
  result.cords.push_back({fromX, fromY});
  int x = fromX;
  int y = fromY;
  while (map[y][x] != 0) {
    switch (map[y][x]) {
      case DIRECTION_UP:
        y--;
        break;
      case DIRECTION_RIGHT:
        x++;
        break;
      case DIRECTION_DOWN:
        y++;
        break;
      case DIRECTION_LEFT:
        x--;
        break;
    }
    result.cords.push_back({x, y});
  }

  return result;
}

std::vector<std::vector<int>> RouteBuilder::buildMap(const Maze &maze, int toX,
                                                     int toY) {
  std::vector<std::vector<int>> map(maze.rows, std::vector<int>(maze.cols));
  std::vector<std::vector<int>> checked(maze.rows, std::vector<int>(maze.cols));
  std::queue<std::pair<int, int>> queue;
  queue.push({toX, toY});
  checked[toY][toX] = 1;
  while (queue.size() > 0) {
    std::pair<int, int> currentCords = queue.front();
    int x = currentCords.first;
    int y = currentCords.second;
    queue.pop();

    if (x < maze.cols - 1 && maze.onRight[y][x] == 0 &&
        checked[y][x + 1] == 0) {
      queue.push({x + 1, y});
      map[y][x + 1] = DIRECTION_LEFT;
      checked[y][x + 1] = 1;
    }
    if (x > 0 && maze.onRight[y][x - 1] == 0 && checked[y][x - 1] == 0) {
      queue.push({x - 1, y});
      map[y][x - 1] = DIRECTION_RIGHT;
      checked[y][x - 1] = 1;
    }
    if (y > 0 && maze.onBottom[y - 1][x] == 0 && checked[y - 1][x] == 0) {
      queue.push({x, y - 1});
      map[y - 1][x] = DIRECTION_DOWN;
      checked[y - 1][x] = 1;
    }
    if (y < maze.rows - 1 && maze.onBottom[y][x] == 0 &&
        checked[y + 1][x] == 0) {
      queue.push({x, y + 1});
      map[y + 1][x] = DIRECTION_UP;
      checked[y + 1][x] = 1;
    }
  }
  return map;
}
}  // namespace s21