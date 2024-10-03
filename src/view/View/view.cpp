#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
    grid = new QGridLayout(ui->widget);
}

View::~View()
{
    delete ui;
}

void View::displayCave(const s21::Cave& cave){
    hasRoute = false;
    route.clear();
    resetGrid();
    grid->setContentsMargins(0,0,0,0);
    grid->setSpacing(0);
    for(int i = 0; i < cave.rows; i++){
        for(int j = 0; j < cave.cols; j++){
            QLabel* label = new QLabel();
            if(cave.isAlive[i][j] == 1){
                label->setStyleSheet(styleBlack);
            } else {
                label->setStyleSheet(styleNo);
            }
            grid->addWidget(label,i,j);
        }
    }
}


void View::displayMaze(const s21::Maze& maze){
    hasRoute = false;
    route.clear();
    try{
        resetGrid();
        grid->setContentsMargins(0,0,0,0);
        grid->setSpacing(0);
        for(int i = 0; i < maze.rows; ++i){
            for(int j = 0; j < maze.cols; ++j){
                QLabel* label = new QLabel();
                if(maze.onRight[i][j] == 1 && maze.onBottom[i][j] == 1){
                    label->setStyleSheet(styleAll);
                } else if(maze.onBottom[i][j] == 1){
                    label->setStyleSheet(styleBottom);
                } else if(maze.onRight[i][j] == 1){
                    label->setStyleSheet(styleRight);
                } else {
                    label->setStyleSheet(styleNo);
                }
                grid->addWidget(label,i,j);
            }
        }
    }catch(const std::out_of_range& e){
        ui->messageLabel->setStyleSheet("color: red;");
        ui->messageLabel->setText(e.what());
    }
}

void View::resetGrid(){
    isMazeShown = false;
    QLayoutItem *item;
    while ((item = grid->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
}

void View::on_mazeOpenFile_clicked()
{
    ui->messageLabel->setText("");
    QString fileName = QFileDialog::getOpenFileName(this,"Choose maze file", "./files", "Text Files (*.txt);;All Files (*)");
    maze = controller.loadMaze(fileName.toStdString());
    ui->toX->setMaximum(maze.cols - 1);
    ui->toY->setMaximum(maze.rows - 1);
    ui->fromX->setMaximum(maze.cols - 1);
    ui->fromY->setMaximum(maze.rows - 1);
    displayMaze(maze);
    isMazeShown = true;
}

void View::on_caveOpenFile_clicked()
{
    ui->messageLabel->setText("");
    QString fileName = QFileDialog::getOpenFileName(this,"Choose maze file", "./files", "Text Files (*.txt);;All Files (*)");
    cave = controller.loadCave(fileName.toStdString());
    displayCave(cave);
    isMazeShown = false;
}



void View::on_generateMazeButton_clicked()
{
    int width = ui->mazeWidth->value();
    int height = ui->mazeHeight->value();
    if(width == maze.cols && height == maze.rows && isMazeShown){
        s21::Maze newMaze = controller.generateMaze(height, width);
        updateMaze(newMaze);
    } else {
        ui->fromX->setMaximum(width - 1);
        ui->toX->setMaximum(width - 1);
        ui->fromY->setMaximum(height - 1);
        ui->toY->setMaximum(height - 1);
        maze = controller.generateMaze(height, width);
        displayMaze(maze);
    }
    isMazeShown = true;
    controller.saveMaze(maze);
}

void View::updateMaze(const s21::Maze& newMaze){
    hasRoute = false;
    route.clear();
    for(int i = 0; i < newMaze.rows; ++i){
        for(int j = 0; j < newMaze.cols; ++j){
            if(newMaze.onRight[i][j] == 1 && newMaze.onBottom[i][j] == 1){
                grid->itemAt(i * newMaze.cols + j)->widget()->setStyleSheet(styleAll);
            } else if(newMaze.onBottom[i][j] == 1){
                grid->itemAt(i * newMaze.cols + j)->widget()->setStyleSheet(styleBottom);
            } else if(newMaze.onRight[i][j] == 1){
                grid->itemAt(i * newMaze.cols + j)->widget()->setStyleSheet(styleRight);
            } else {
                grid->itemAt(i * newMaze.cols + j)->widget()->setStyleSheet(styleNo);
            }
        }
    }
    maze = newMaze;
}


void View::on_buildRouteButton_clicked()
{
    if(isMazeShown){
        int fromX = ui->fromX->value();
        int fromY = ui->fromY->value();
        int toX = ui->toX->value();
        int toY = ui->toY->value();
        s21::Route r = controller.buildRoute(maze, fromX,fromY, toX, toY);

        route.clear();
        for(size_t i = 0; i < r.cords.size(); ++i){
            QPoint point = getLabelCenter(r.cords[i].first, r.cords[i].second);
            route.push_back(point);
        }
        hasRoute = true;
        ui->widget->update();
    }

}

QPoint View::getLabelCenter(int x, int y){
    int position = maze.cols * y + x;
    QLabel *label = qobject_cast<QLabel *>(grid->layout()->itemAt(position)->widget());

    if (label) {
        QPoint point = label->mapToGlobal(label->rect().center());
        point.setX(point.x() - 150);
        point.setY(point.y() - 150);
        return point;
    }
    return QPoint();
}

void View::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    if (hasRoute) {
        QPainter painter(this);
        painter.setPen(QPen(Qt::green, 2));
        for(size_t i = 0; i < route.size() - 1; ++i){
            painter.drawLine(route.at(i), route.at(i + 1));
        }
    }
}



void View::on_generateCaveButton_clicked()
{
    hasRoute = false;
    route.clear();
    int width = ui->caveWidth->value();
    int height = ui->caveHight->value();
    int probability = ui->probability->value();
    s21::Cave newCave = controller.generateCave(height, width, probability);
    if(newCave.cols == cave.cols && newCave.rows == cave.rows && !isMazeShown){
        updateCave(newCave);
    } else {
        cave = newCave;
        displayCave(cave);
    }
    isMazeShown = false;
}


void View::on_getNextGenButton_clicked()
{
    int lifeLimit = ui->caveLifeLimit->value();
    int deathLimit = ui->caveDeathLimit->value();
    s21::Cave newCave = controller.getNextGeneration(cave, lifeLimit, deathLimit);
    updateCave(newCave);
    cave = newCave;
}

void View::updateCave(const s21::Cave& newCave){
    for(int i = 0; i < newCave.rows; i++){
        for(int j = 0; j < newCave.cols; j++){
            if(newCave.isAlive[i][j] != cave.isAlive[i][j]){
                if(newCave.isAlive[i][j] == 1){
                    grid->itemAt(i * cave.cols + j)->widget()->setStyleSheet(styleBlack);
                } else {
                    grid->itemAt(i * cave.cols + j)->widget()->setStyleSheet(styleNo);
                }
            }
        }
    }
    cave = newCave;
}


void View::on_autoGetNextGenButton_clicked()
{
    int lifeLimit = ui->caveLifeLimit->value();
    int deathLimit = ui->caveDeathLimit->value();
    exitFromAutoGenFlag = false;
    while(!exitFromAutoGenFlag){
        s21::Cave newCave = controller.getNextGeneration(cave, lifeLimit, deathLimit);
        exitFromAutoGenFlag = equals(cave, newCave);
        updateCave(newCave);
        QCoreApplication::processEvents();
        std::this_thread::sleep_for(std::chrono::milliseconds(ui->autoNextGenSpeed->value()));
    }
}

bool View::equals(const s21::Cave& cave1, s21::Cave& cave2){
    for(int i = 0; i < cave1.rows; i++){
        for(int j = 0; j < cave1.cols; j++){
            if(cave1.isAlive[i][j] != cave2.isAlive[i][j]){
                return false;
            }
        }
    }
    return true;
}


void View::on_stopAutoGenButton_clicked()
{
    exitFromAutoGenFlag = true;
}

