#ifndef VIEW_H
#define VIEW_H
#include <QFileDialog>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPainter>
#include <chrono>
#include <thread>

#include "../../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

class View : public QMainWindow {
  Q_OBJECT

 public:
  View(QWidget *parent = nullptr);
  ~View();

 private slots:
  void resetGrid();
  void on_mazeOpenFile_clicked();

  void on_generateMazeButton_clicked();

  void on_buildRouteButton_clicked();

  void on_caveOpenFile_clicked();

  void on_generateCaveButton_clicked();

  void on_getNextGenButton_clicked();

  void on_autoGetNextGenButton_clicked();

  void on_stopAutoGenButton_clicked();

 protected:
  void paintEvent(QPaintEvent *event) override;

 private:
  s21::Controller &controller = s21::Controller::getInstance();
  s21::Maze maze;
  s21::Cave cave;
  QGridLayout *grid;
  Ui::View *ui;
  QString styleNo = "border: none; padding: 0; margin: 0;";
  QString styleAll =
      "border: none; padding: 0; margin: 0;border-right: 2px "
      "solid black;border-bottom: 2px solid black;";
  QString styleRight =
      "border: none; padding: 0; margin: 0;border-right: 2px solid black;";
  QString styleBottom =
      "border: none; padding: 0; margin: 0;border-bottom: 2px solid black;";
  QString styleBlack = "background-color: black;";
  bool hasRoute = false;
  bool isMazeShown = false;
  bool exitFromAutoGenFlag = false;
  std::vector<QPoint> route;

  void displayMaze(const s21::Maze &maze);
  void displayCave(const s21::Cave &cave);
  void updateCave(const s21::Cave &cave);
  void updateMaze(const s21::Maze &maze);
  bool equals(const s21::Cave &cave1, s21::Cave &cave2);
  QPoint getLabelCenter(int x, int y);
};
#endif  // VIEW_H
