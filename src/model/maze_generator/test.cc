#include <gtest/gtest.h>

#include "maze_generator.h"

TEST(MazeGeneratorTest, GenerateMaze) {
  s21::MazeGenerator &generator = s21::MazeGenerator::getInstance();

  // Генерация лабиринта
  s21::Maze maze = generator.generateMaze(50, 50);

  // Проверка размеров лабиринта
  EXPECT_EQ(maze.rows, 50);
  EXPECT_EQ(maze.cols, 50);

  // Проверка наличия правых и нижних границ
  for (int i = 0; i < maze.rows; i++) {
    for (int j = 0; j < maze.cols; j++) {
      if (j < maze.cols - 1) {
        EXPECT_TRUE(maze.onRight[i][j] == 0 || maze.onRight[i][j] == 1);
      }
      if (i < maze.rows - 1) {
        EXPECT_TRUE(maze.onBottom[i][j] == 0 || maze.onBottom[i][j] == 1);
      }
    }
  }
}