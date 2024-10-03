#include "maze_generator.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
namespace s21 {

MazeGenerator &MazeGenerator::getInstance() {
  static MazeGenerator instance;
  return instance;
}

Maze MazeGenerator::generateMaze(int rows, int cols) {
  Maze maze;
  maze.cols = cols;
  maze.rows = rows;
  maze.onRight.resize(maze.rows, std::vector<int>(maze.cols));
  maze.onBottom.resize(maze.rows, std::vector<int>(maze.cols));
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  std::vector<int> line(cols);

  for (int row = 0; row < rows - 1; row++) {
    fillWithSet(line);
    setRightBorder(line, maze, row);
    setBottomBorder(line, maze, row);
    fixBottomBorder(line, maze, row);
    prepareNewLine(line, maze, row);
  }
  addFinalRow(line, maze);
  return maze;
}

void MazeGenerator::addFinalRow(std::vector<int> &line, Maze &maze) {
  fillWithSet(line);
  setRightBorder(line, maze, maze.rows - 1);
  fixLastLine(line, maze);
}

void MazeGenerator::fixLastLine(std::vector<int> &line, Maze &maze) {
  for (int i = 0; i < maze.cols; i++) {
    if (line[i] != line[i + 1]) {
      maze.onRight[maze.rows - 1][i] = 0;
      mergeSet(line, i);
    }
  }
}

void MazeGenerator::fixBottomBorder(const std::vector<int> &line, Maze &maze,
                                    int row) {
  for (size_t i = 0; i < line.size(); ++i) {
    if (countBottomExits(line, maze, i, row) == 0) {
      maze.onBottom[row][i] = 0;
    }
  }
}

bool MazeGenerator::randomBool() {
  int randomValue = std::rand() % 2;
  return static_cast<bool>(randomValue);
}

void MazeGenerator::fillWithSet(std::vector<int> &line) {
  for (size_t i = 0; i < line.size(); ++i) {
    if (line[i] == 0) {
      line[i] = counter++;
    }
  }
}

void MazeGenerator::setRightBorder(std::vector<int> &line, Maze &maze,
                                   int row) {
  for (size_t i = 0; i < line.size() - 1; ++i) {
    bool choice = randomBool();
    if (choice || line[i] == line[i + 1]) {
      maze.onRight[row][i] = 1;
    } else {
      mergeSet(line, i);
      line[i + 1] = line[i];
    }
  }
}

void MazeGenerator::mergeSet(std::vector<int> &line, int index) {
  int mutableSet = line[index + 1];
  for (size_t j = 0; j < line.size(); ++j) {
    if (line[j] == mutableSet) {
      line[j] = line[index];
    }
  }
}

void MazeGenerator::setBottomBorder(const std::vector<int> &line, Maze &maze,
                                    int row) {
  for (size_t i = 0; i < line.size(); ++i) {
    bool choise = randomBool();
    if (choise == true && countBottomExits(line, maze, i, row) != 1) {
      maze.onBottom[row][i] = 1;
    }
  }
}

int MazeGenerator::countBottomExits(const std::vector<int> &line,
                                    const Maze &maze, int index, int row) {
  int currentSet = line[index];
  int counter = 0;
  for (size_t i = 0; i < line.size(); ++i) {
    if (line[i] == currentSet && maze.onBottom[row][i] == 0) {
      counter++;
    }
  }
  return counter;
}

void MazeGenerator::prepareNewLine(std::vector<int> &line, const Maze &maze,
                                   int row) {
  for (int i = 0; i < maze.cols; ++i) {
    if (maze.onBottom[row][i] == 1) {
      line[i] = 0;
    }
  }
}

}  // namespace s21