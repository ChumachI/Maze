#include "cave_generator.h"

#include <iostream>
namespace s21 {
CaveGenerator &CaveGenerator::getInstance() {
  static CaveGenerator instance;
  return instance;
}

Cave CaveGenerator::generateCave(int rows, int cols, int probability) {
  Cave result;
  result.rows = rows;
  result.cols = cols;
  result.isAlive.resize(rows, std::vector<int>(cols));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      bool isAlive = randomBool(probability);
      if (isAlive) {
        result.isAlive[i][j] = 1;
      }
    }
  }

  return result;
}

bool CaveGenerator::randomBool(int probability) {
  int randomValue = 1 + std::rand() % 100;
  return randomValue < probability;
}

Cave CaveGenerator::getNextGeneration(const Cave &cave, int liveLimit,
                                      int deathLimit) {
  Cave result;
  result.rows = cave.rows;
  result.cols = cave.cols;
  result.isAlive.resize(cave.rows, std::vector<int>(cave.cols));
  for (int i = 0; i < cave.rows; i++) {
    for (int j = 0; j < cave.cols; j++) {
      int neighbs = countNeighborhoods(cave, i, j);
      if (cave.isAlive[i][j] == 0 && neighbs > liveLimit) {
        result.isAlive[i][j] = 1;
      } else if (cave.isAlive[i][j] == 1 && neighbs < deathLimit) {
        result.isAlive[i][j] = 0;
      } else {
        result.isAlive[i][j] = cave.isAlive[i][j];
      }
    }
  }
  return result;
}
int CaveGenerator::countNeighborhoods(const Cave &cave, int i, int j) {
  int counter = 0;
  for (int k = i - 1; k <= i + 1; k++) {
    for (int m = j - 1; m <= j + 1; m++) {
      if (k == i && m == j) {
        continue;
      } else if (k < 0 || k == cave.rows || m < 0 || m == cave.cols) {
        counter++;
      } else {
        counter += cave.isAlive[k][m];
      }
    }
  }
  return counter;
}
}  // namespace s21
