#ifndef A1_MAZE_SRC_MODEL_CAVE_H_
#define A1_MAZE_SRC_MODEL_CAVE_H_
#include <vector>
namespace s21 {
/**
 * @brief Структура представляющая пещеру.
 */
struct Cave {
  int cols; /**< Количество столбцов в пещере. */
  int rows; /**< Количество строк в пещере. */
  std::vector<std::vector<int>>
      isAlive; /**< Матрица с информацией о состоянии ячеек в пещере. */
};

}  // namespace s21
#endif  // A1_MAZE_SRC_MODEL_CAVE_H_