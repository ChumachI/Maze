#ifndef A1_MAZE_SRC_MODEL_MAZE_GENERATOR_H_
#define A1_MAZE_SRC_MODEL_MAZE_GENERATOR_H_

#include "../maze.h"

namespace s21 {

/**
 * @brief Класс для генерации лабиринта.
 */
class MazeGenerator {
 public:
  /**
   * @brief Получение экземпляра MazeGenerator (шаблон Singleton).
   * @return Ссылка на экземпляр MazeGenerator.
   */
  static MazeGenerator &getInstance();

  /**
   * @brief Генерация лабиринта заданных размеров.
   * @param rows Количество строк в лабиринте.
   * @param cols Количество столбцов в лабиринте.
   * @return Объект Maze, представляющий сгенерированный лабиринт.
   */
  Maze generateMaze(int rows, int cols);

 private:
  int counter = 1;

  /**
   * @brief Генерация случайного значения типа bool.
   * @return true с вероятностью 50%, false с вероятностью 50%.
   */
  bool randomBool();

  /**
   * @brief Заполнение вектора значениями множества.
   * @param line Вектор для заполнения.
   */
  void fillWithSet(std::vector<int> &line);

  /**
   * @brief Установка правых границ лабиринта.
   * @param line Вектор, представляющий текущую строку лабиринта.
   * @param maze Объект Maze, представляющий лабиринт.
   * @param row Текущая строка лабиринта.
   */
  void setRightBorder(std::vector<int> &line, Maze &maze, int row);

  /**
   * @brief Объединение множеств в векторе.
   * @param line Вектор, представляющий текущую строку лабиринта.
   * @param index Индекс элемента в векторе.
   */
  void mergeSet(std::vector<int> &line, int index);

  /**
   * @brief Установка нижних границ лабиринта.
   * @param line Вектор, представляющий текущую строку лабиринта.
   * @param maze Объект Maze, представляющий лабиринт.
   * @param row Текущая строка лабиринта.
   */
  void setBottomBorder(const std::vector<int> &line, Maze &maze, int row);

  /**
   * @brief Подсчет количества нижних выходов из множества.
   * @param line Вектор, представляющий текущую строку лабиринта.
   * @param maze Объект Maze, представляющий лабиринт.
   * @param index Индекс элемента в векторе.
   * @param row Текущая строка лабиринта.
   * @return Количество нижних выходов из множества.
   */
  int countBottomExits(const std::vector<int> &line, const Maze &maze,
                       int index, int row);

  /**
   * @brief Подготовка новой строки лабиринта.
   * @param line Вектор, представляющий текущую строку лабиринта.
   * @param maze Объект Maze, представляющий лабиринт.
   * @param row Текущая строка лабиринта.
   */
  void prepareNewLine(std::vector<int> &line, const Maze &maze, int row);

  /**
   * @brief Коррекция нижних границ лабиринта.
   * @param line Вектор, представляющий текущую строку лабиринта.
   * @param maze Объект Maze, представляющий лабиринт.
   * @param row Текущая строка лабиринта.
   */
  void fixBottomBorder(const std::vector<int> &line, Maze &maze, int row);

  /**
   * @brief Добавление последней строки лабиринта.
   * @param line Вектор, представляющий текущую строку лабиринта.
   * @param maze Объект Maze, представляющий лабиринт.
   */
  void addFinalRow(std::vector<int> &line, Maze &maze);

  /**
   * @brief Коррекция последней строки лабиринта.
   * @param line Вектор, представляющий текущую строку лабиринта.
   * @param maze Объект Maze, представляющий лабиринт.
   */
  void fixLastLine(std::vector<int> &line, Maze &maze);

  /**
   * @brief Приватный конструктор для шаблона Singleton.
   */
  MazeGenerator(){};

  MazeGenerator(const MazeGenerator &) = delete;
  MazeGenerator &operator=(const MazeGenerator &) = delete;
};

}  // namespace s21

#endif  // A1_MAZE_SRC_MODEL_MAZE_GENERATOR_H_
