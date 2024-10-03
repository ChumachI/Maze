#ifndef A1_MAZE_SRC_MODEL_CAVE_GENERATOR_H_
#define A1_MAZE_SRC_MODEL_CAVE_GENERATOR_H_

#include <random>

#include "../cave.h"

namespace s21 {

/**
 * @brief Класс для генерации и обработки пещер.
 */
class CaveGenerator {
 public:
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
   * @brief Получение экземпляра CaveGenerator (шаблон Singleton).
   * @return Ссылка на экземпляр CaveGenerator.
   */
  static CaveGenerator &getInstance();

 private:
  int counter = 1;

  /**
   * @brief Генерация случайного значения типа bool с заданной вероятностью.
   * @param probability Вероятность в процентах (0-100).
   * @return true, если случайное значение меньше заданной вероятности, иначе
   * false.
   */
  bool randomBool(int probability);

  /**
   * @brief Подсчет количества соседей у клетки в пещере.
   * @param cave Текущее состояние пещеры.
   * @param i Индекс строки клетки.
   * @param j Индекс столбца клетки.
   * @return Количество соседей у клетки.
   */
  int countNeighborhoods(const Cave &cave, int i, int j);

  /**
   * @brief Приватный конструктор для шаблона Singleton.
   */
  CaveGenerator(){};

  CaveGenerator(const CaveGenerator &) = delete;
  CaveGenerator &operator=(const CaveGenerator &) = delete;
};

}  // namespace s21

#endif  // A1_MAZE_SRC_MODEL_CAVE_GENERATOR_H_
