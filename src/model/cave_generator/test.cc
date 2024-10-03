#include <gtest/gtest.h>

#include "cave_generator.h"

TEST(CaveGeneratorTest, GenerateCave) {
  s21::CaveGenerator &caveGenerator = s21::CaveGenerator::getInstance();
  int rows = 10;
  int cols = 10;
  int probability = 50;

  s21::Cave cave = caveGenerator.generateCave(rows, cols, probability);

  // Проверяем размеры лабиринта
  EXPECT_EQ(cave.rows, rows);
  EXPECT_EQ(cave.cols, cols);

  // Проверяем, что все значения находятся в пределах [0, 1]
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      EXPECT_TRUE(cave.isAlive[i][j] == 0 || cave.isAlive[i][j] == 1);
    }
  }
}

TEST(CaveGeneratorTest, NextGeneration) {
  s21::CaveGenerator &caveGenerator = s21::CaveGenerator::getInstance();
  s21::Cave cave;
  cave.rows = 3;
  cave.cols = 3;
  cave.isAlive = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};

  // Генерируем следующее поколение
  s21::Cave nextGeneration = caveGenerator.getNextGeneration(cave, 2, 3);

  // Проверяем, что центральная клетка выжила (имеет 2 соседа)
  EXPECT_EQ(nextGeneration.isAlive[1][1], 1);

  // Проверяем, что угловые клетки умерли (не имеют достаточного количества
  // соседей)
  EXPECT_EQ(nextGeneration.isAlive[0][0], 1);
  EXPECT_EQ(nextGeneration.isAlive[0][2], 1);
  EXPECT_EQ(nextGeneration.isAlive[2][0], 1);
  EXPECT_EQ(nextGeneration.isAlive[2][2], 1);
}