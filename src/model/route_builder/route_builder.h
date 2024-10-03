#ifndef A1_MAZE_SRC_MODEL_ROUTE_BUILDER_H_
#define A1_MAZE_SRC_MODEL_ROUTE_BUILDER_H_

#include <queue>
#include <utility>

#include "../maze.h"
#include "route.h"

#define DIRECTION_UP 1
#define DIRECTION_RIGHT 2
#define DIRECTION_DOWN 3
#define DIRECTION_LEFT 4

namespace s21 {

/**
 * @brief Класс RouteBuilder отвечает за построение маршрута внутри лабиринта
 * от указанной стартовой точки до конечной точки.
 */
class RouteBuilder {
 public:
  /**
   * @brief Получает единственный экземпляр RouteBuilder.
   * @return Ссылка на экземпляр RouteBuilder.
   */
  static RouteBuilder &getInstance();

  /**
   * @brief Строит маршрут внутри лабиринта от указанной стартовой точки до конечной точки.
   * @param maze Лабиринт, для которого строится маршрут.
   * @param fromX X-координата стартовой точки.
   * @param fromY Y-координата стартовой точки.
   * @param toX X-координата конечной точки.
   * @param toY Y-координата конечной точки.
   * @return Объект Route, представляющий рассчитанный маршрут.
   */
  Route buildRoute(const Maze &maze, int fromX, int fromY, int toX, int toY);

 private:
  /**
   * @brief Конструктор по умолчанию для RouteBuilder.
   */
  RouteBuilder() {}

  /**
   * @brief Удаленный конструктор копирования для обеспечения паттерна синглтона.
   */
  RouteBuilder(const RouteBuilder &) = delete;

  /**
   * @brief Удаленный оператор присваивания для обеспечения паттерна синглтона.
   */
  RouteBuilder &operator=(const RouteBuilder &) = delete;

  /**
   * @brief Строит карту направлений внутри лабиринта с использованием поиска в ширину.
   * @param maze Лабиринт, для которого строится карта.
   * @param toX X-координата конечной точки.
   * @param toY Y-координата конечной точки.
   * @return 2D-вектор, представляющий карту направлений.
   */
  std::vector<std::vector<int>> buildMap(const Maze &maze, int toX, int toY);

  /**
   * @brief Считывает карту и строит из нее маршрут.
   * @param map Карта направлений внутри лабиринта.
   * @param fromX X-координата стартовой точки.
   * @param fromY Y-координата стартовой точки.
   * @return Объект Route, представляющий рассчитанный маршрут.
   */
  Route readMap(const std::vector<std::vector<int>> &map, int fromX, int fromY);
};

}  // namespace s21

#endif  // A1_MAZE_SRC_MODEL_ROUTE_BUILDER_H_
