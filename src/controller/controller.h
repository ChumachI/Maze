#ifndef A1_MAZE_SRC_CONTROLLER_CONTROLLER_H_
#define A1_MAZE_SRC_CONTROLLER_CONTROLLER_H_

#include "../model/cave_generator/cave_generator.h"
#include "../model/file_worker/file_worker.h"
#include "../model/maze_generator/maze_generator.h"
#include "../model/route_builder/route_builder.h"

namespace s21 {

/**
 * @brief Контроллер, управляющий взаимодействием между моделью и
 * представлением.
 */
class Controller {
 public:
  /**
   * @brief Получение экземпляра Controller (шаблон Singleton).
   * @return Ссылка на экземпляр Controller.
   */
  static Controller &getInstance();

  /**
   * @brief Загрузка лабиринта из файла.
   * @param fileName Имя файла с лабиринтом.
   * @return Объект Maze, представляющий загруженный лабиринт.
   */
  Maze loadMaze(const std::string &fileName);

  /**
   * @brief Сохранение лабиринта в файл.
   * @param maze Объект Maze, представляющий лабиринт для сохранения.
   */
  void saveMaze(const Maze &maze);

  /**
   * @brief Генерация лабиринта заданных размеров.
   * @param rows Количество строк в лабиринте.
   * @param cols Количество столбцов в лабиринте.
   * @return Объект Maze, представляющий сгенерированный лабиринт.
   */
  Maze generateMaze(int rows, int cols);

  /**
   * @brief Загрузка пещеры из файла.
   * @param fileName Имя файла с пещерой.
   * @return Объект Cave, представляющий загруженную пещеру.
   */
  Cave loadCave(const std::string &fileName);

  /**
   * @brief Генерация пещеры заданных размеров с заданной вероятностью живых
   * клеток.
   * @param rows Количество строк в пещере.
   * @param cols Количество столбцов в пещере.
   * @param probability Вероятность живой клетки в процентах (0-100).
   * @return Объект Cave, представляющий сгенерированную пещеру.
   */
  Cave generateCave(int rows, int cols, int probability);

  /**
   * @brief Получение следующего поколения пещеры на основе текущего состояния.
   * @param cave Текущее состояние пещеры.
   * @param liveLimit Минимальное количество соседей для выживания живой клетки.
   * @param deathLimit Максимальное количество соседей для выживания мертвой
   * клетки.
   * @return Объект Cave, представляющий следующее поколение пещеры.
   */
  Cave getNextGeneration(const Cave &cave, int liveLimit, int deathLimit);

  /**
   * @brief Построение маршрута в лабиринте.
   * @param maze Объект Maze, представляющий лабиринт.
   * @param fromX Координата X начальной точки маршрута.
   * @param fromY Координата Y начальной точки маршрута.
   * @param toX Координата X конечной точки маршрута.
   * @param toY Координата Y конечной точки маршрута.
   * @return Объект Route, представляющий построенный маршрут в лабиринте.
   */
  Route buildRoute(const Maze &maze, int fromX, int fromY, int toX, int toY);

 private:
  Controller() {}
  Controller(const Controller &) = delete;
  Controller &operator=(const Controller &) = delete;

  FileWorker &fileWorker = FileWorker::getInstance();
  MazeGenerator &mazeGenerator = MazeGenerator::getInstance();
  RouteBuilder &routeBuilder = RouteBuilder::getInstance();
  CaveGenerator &caveGenerator = CaveGenerator::getInstance();
};

}  // namespace s21

#endif  // A1_MAZE_SRC_CONTROLLER_CONTROLLER_H_
