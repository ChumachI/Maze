#include <gtest/gtest.h>

#include "route_builder.h"

TEST(RouteBuilderTest, BuildRoute) {
  s21::RouteBuilder &routeBuilder = s21::RouteBuilder::getInstance();

  // Создаем лабиринт 10x10
  s21::Maze maze;
  maze.rows = 10;
  maze.cols = 10;
  maze.onRight = {
      {0, 1, 1, 0, 1, 1, 1, 1, 1, 0}, {1, 0, 1, 1, 0, 1, 1, 1, 0, 0},
      {1, 0, 0, 0, 1, 1, 1, 1, 0, 0}, {1, 0, 0, 0, 1, 0, 1, 0, 1, 0},
      {0, 1, 0, 1, 0, 0, 1, 1, 1, 0}, {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
      {1, 1, 0, 0, 0, 0, 0, 1, 1, 0}, {0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
      {1, 1, 0, 1, 0, 0, 0, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 1, 0, 1, 0}};

  maze.onBottom = {
      {0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
      {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
      {1, 0, 1, 0, 1, 1, 0, 0, 1, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
      {0, 0, 1, 1, 1, 0, 1, 0, 1, 0}, {0, 0, 1, 0, 1, 1, 0, 0, 1, 0},
      {0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

  // Поставим точки from и to
  int fromX = 0, fromY = 0;
  int toX = 9, toY = 9;

  // Создаем маршрут
  s21::Route route = routeBuilder.buildRoute(maze, fromX, fromY, toX, toY);

  // Проверяем, что размер маршрута равен ожидаемому значению
  EXPECT_EQ(route.cords.size(), 33);

  // Проверяем, что координаты маршрута соответствуют ожидаемым
  EXPECT_EQ(route.cords[0].first, fromX);
  EXPECT_EQ(route.cords[0].second, fromY);

  // ... (продолжите проверку координат для остальных точек маршрута)

  EXPECT_EQ(route.cords[32].first, toX);
  EXPECT_EQ(route.cords[32].second, toY);

  fromX = 9, fromY = 9;
  toX = 0, toY = 0;

  // Создаем маршрут
  route = routeBuilder.buildRoute(maze, fromX, fromY, toX, toY);

  // Проверяем, что размер маршрута равен ожидаемому значению
  EXPECT_EQ(route.cords.size(), 33);

  // Проверяем, что координаты маршрута соответствуют ожидаемым
  EXPECT_EQ(route.cords[0].first, fromX);
  EXPECT_EQ(route.cords[0].second, fromY);

  // ... (продолжите проверку координат для остальных точек маршрута)

  EXPECT_EQ(route.cords[32].first, toX);
  EXPECT_EQ(route.cords[32].second, toY);
}
