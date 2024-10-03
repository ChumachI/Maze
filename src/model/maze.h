#ifndef A1_MAZE_SRC_MODEL_MAZE_H_
#define A1_MAZE_SRC_MODEL_MAZE_H_
#include <vector>
namespace s21 {
/**
 * @brief Структура представляющая лабиринт.
 */
struct Maze {
  int cols; /**< Количество столбцов в лабиринте. */
  int rows; /**< Количество строк в лабиринте. */
  std::vector<std::vector<int>>
      onRight; /**< Матрица с информацией о правых стенах. */
  std::vector<std::vector<int>>
      onBottom; /**< Матрица с информацией о нижних стенах. */
};

}  // namespace s21
#endif  // A1_MAZE_SRC_MODEL_MAZE_H_