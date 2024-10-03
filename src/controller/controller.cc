#include "controller.h"
namespace s21 {
Controller &Controller::getInstance() {
  static Controller instance;
  return instance;
}
Maze Controller::loadMaze(const std::string &fileName) {
  return fileWorker.loadMaze(fileName);
}
void Controller::saveMaze(const Maze &maze) {
  fileWorker.saveMaze(maze, "files");
}
Maze Controller::generateMaze(int rows, int cols) {
  return mazeGenerator.generateMaze(rows, cols);
}

Cave Controller::loadCave(const std::string &fileName) {
  return fileWorker.loadCave(fileName);
}

Cave Controller::generateCave(int rows, int cols, int probability) {
  return caveGenerator.generateCave(rows, cols, probability);
}

Route Controller::buildRoute(const Maze &maze, int fromX, int fromY, int toX,
                             int toY) {
  return routeBuilder.buildRoute(maze, fromX, fromY, toX, toY);
}

Cave Controller::getNextGeneration(const Cave &cave, int liveLimit,
                                   int deathLimit) {
  return caveGenerator.getNextGeneration(cave, liveLimit, deathLimit);
}

}  // namespace s21