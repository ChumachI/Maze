#ifndef A1_MAZE_SRC_MODEL_FILE_LOADER_H_
#define A1_MAZE_SRC_MODEL_FILE_LOADER_H_

#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "../cave.h"
#include "../maze.h"

namespace s21 {

/**
 * @brief Класс Singleton, ответственный за загрузку и сохранение данных о
 * лабиринте и пещере из/в файл.
 */
class FileWorker {
 public:
  /**
   * @brief Получение экземпляра FileWorker (шаблон Singleton).
   * @return Ссылка на экземпляр FileWorker.
   */
  static FileWorker &getInstance();

  /**
   * @brief Загрузка данных о лабиринте из файла.
   * @param fileName Имя файла с данными о лабиринте.
   * @return Объект Maze, представляющий загруженный лабиринт.
   * @throws std::out_of_range, если размер лабиринта превышает максимальные
   * размеры.
   */
  Maze loadMaze(const std::string &fileName);

  /**
   * @brief Сохранение данных о лабиринте в новый файл.
   * @param maze Объект Maze для сохранения.
   */
  void saveMaze(const Maze &maze, const std::string &directory);

  /**
   * @brief Генерация нового имени файла для сохранения лабиринта.
   * @return Строка, представляющая новое имя файла.
   */
  std::string getNewFileName(const std::string &directory);

  /**
   * @brief Загрузка данных о пещере из файла.
   * @param fileName Имя файла с данными о пещере.
   * @return Объект Cave, представляющий загруженную пещеру.
   */
  Cave loadCave(const std::string &fileName);

 private:
  FileWorker() {}  // Приватный конструктор для шаблона Singleton.
  FileWorker(const FileWorker &) = delete;
  FileWorker &operator=(const FileWorker &) = delete;
};

}  // namespace s21

#endif  // A1_MAZE_SRC_MODEL_FILE_LOADER_H_
