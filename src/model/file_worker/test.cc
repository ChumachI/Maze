#include <gtest/gtest.h>

#include "file_worker.h"

TEST(FileWorkerTest, GetNewFileName) {
  // Создаем временную директорию для теста
  std::filesystem::create_directory("test_files");

  // Создаем несколько файлов в директории
  std::ofstream file1("test_files/maze1.txt");
  std::ofstream file2("test_files/maze2.txt");

  // Получаем экземпляр FileWorker
  s21::FileWorker &fileWorker = s21::FileWorker::getInstance();

  // Получаем новое имя файла
  std::string newFileName = fileWorker.getNewFileName("test_files");

  // Проверяем, что новое имя файла соответствует ожиданиям
  EXPECT_EQ(newFileName, "./test_files/maze3.txt");

  // Удаляем временную директорию и ее содержимое
  std::filesystem::remove_all("test_files");
}

TEST(FileWorkerTest, LoadCave) {
  // Создаем временный файл с данными
  std::ofstream file("test_cave.txt");
  file << "3 4\n";  // 3 rows, 4 cols
  file << "1 0 1 0\n";
  file << "0 1 0 1\n";
  file << "1 1 1 0\n";
  file.close();

  // Получаем экземпляр FileWorker
  s21::FileWorker &fileWorker = s21::FileWorker::getInstance();

  // Загружаем пещеру из файла
  s21::Cave cave = fileWorker.loadCave("test_cave.txt");

  // Проверяем размеры и содержимое пещеры
  EXPECT_EQ(cave.rows, 3);
  EXPECT_EQ(cave.cols, 4);
  EXPECT_EQ(cave.isAlive[0], std::vector<int>({1, 0, 1, 0}));
  EXPECT_EQ(cave.isAlive[1], std::vector<int>({0, 1, 0, 1}));
  EXPECT_EQ(cave.isAlive[2], std::vector<int>({1, 1, 1, 0}));

  // Удаляем временный файл
  std::filesystem::remove("test_cave.txt");
}

TEST(FileWorkerTest, SaveMaze) {
  // Создаем временный объект Maze
  s21::Maze maze;
  maze.rows = 3;
  maze.cols = 4;
  maze.onRight = {{1, 0, 1, 0}, {0, 1, 0, 1}, {1, 1, 1, 0}};
  maze.onBottom = {{0, 1, 0, 1}, {1, 0, 1, 0}, {0, 0, 0, 1}};

  // Получаем экземпляр FileWorker
  s21::FileWorker &fileWorker = s21::FileWorker::getInstance();
  std::filesystem::create_directory("test_files");
  // Сохраняем лабиринт в файл
  fileWorker.saveMaze(maze, "test_files");

  // Читаем содержимое сохраненного файла
  std::ifstream inputFile("test_files/maze1.txt");
  std::string fileContents;
  if (inputFile.is_open()) {
    char c;
    while (inputFile.get(c)) {
      fileContents += c;
    }
    inputFile.close();
  }
  std::filesystem::remove_all("test_files");
  // Проверяем, что содержимое файла соответствует ожиданиям
  std::string expectedContents =
      "3 4\n1 0 1 0 \n0 1 0 1 \n1 1 1 0 \n\n0 1 0 1 \n1 0 1 0 \n0 0 0 1 \n";
  EXPECT_EQ(fileContents, expectedContents);
}

TEST(FileWorkerTest, LoadMaze_ValidFile) {
  // Создаем временный файл с данными
  std::ofstream file("test_maze.txt");
  file << "3 4\n";  // 3 rows, 4 cols
  file << "1 0 1 0\n";
  file << "0 1 0 1\n";
  file << "1 1 1 0\n";
  file << "\n";
  file << "0 1 0 1\n";
  file << "1 0 1 0\n";
  file << "0 0 0 1\n";
  file.close();

  // Получаем экземпляр FileWorker
  s21::FileWorker &fileWorker = s21::FileWorker::getInstance();

  // Загружаем лабиринт из файла
  s21::Maze maze = fileWorker.loadMaze("test_maze.txt");

  // Проверяем размеры и содержимое лабиринта
  EXPECT_EQ(maze.rows, 3);
  EXPECT_EQ(maze.cols, 4);
  EXPECT_EQ(maze.onRight[0], std::vector<int>({1, 0, 1, 0}));
  EXPECT_EQ(maze.onRight[1], std::vector<int>({0, 1, 0, 1}));
  EXPECT_EQ(maze.onRight[2], std::vector<int>({1, 1, 1, 0}));
  EXPECT_EQ(maze.onBottom[0], std::vector<int>({0, 1, 0, 1}));
  EXPECT_EQ(maze.onBottom[1], std::vector<int>({1, 0, 1, 0}));
  EXPECT_EQ(maze.onBottom[2], std::vector<int>({0, 0, 0, 1}));

  // Удаляем временный файл
  std::filesystem::remove("test_maze.txt");
}

TEST(FileWorkerTest, LoadMaze_InvalidSize) {
  // Создаем временный файл с недопустимыми размерами
  std::ofstream file("invalid_size_maze.txt");
  file << "51 49\n";  // Invalid size
  file.close();

  // Получаем экземпляр FileWorker
  s21::FileWorker &fileWorker = s21::FileWorker::getInstance();

  // Пытаемся загрузить лабиринт с недопустимыми размерами
  EXPECT_THROW(fileWorker.loadMaze("invalid_size_maze.txt"), std::out_of_range);

  // Удаляем временный файл
  std::filesystem::remove("invalid_size_maze.txt");
}
