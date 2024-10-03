#include "file_worker.h"

namespace s21 {

FileWorker &FileWorker::getInstance() {
  static FileWorker instance;
  return instance;
}

Maze FileWorker::loadMaze(const std::string &fileName) {
  Maze result;
  result.cols = 0;
  result.rows = 0;
  std::ifstream inputFile(fileName);

  if (inputFile.is_open()) {
    inputFile >> result.rows;
    inputFile >> result.cols;
    if (result.rows > 50 || result.cols > 50) {
      throw std::out_of_range("Invalid maze size. Exceeds maximum dimensions.");
    }
    result.onRight.resize(result.rows, std::vector<int>(result.cols));
    result.onBottom.resize(result.rows, std::vector<int>(result.cols));
    for (int i = 0; i < result.rows; i++) {
      for (int j = 0; j < result.cols; j++) {
        inputFile >> result.onRight[i][j];
      }
    }
    for (int i = 0; i < result.rows; i++) {
      for (int j = 0; j < result.cols; j++) {
        inputFile >> result.onBottom[i][j];
      }
    }
    inputFile.close();
  }
  return result;
}

void FileWorker::saveMaze(const Maze &maze, const std::string &directory) {
  std::string newFileName = getNewFileName(directory);
  std::ofstream outputFile(newFileName);
  if (outputFile.is_open()) {
    outputFile << maze.rows << " " << maze.cols << std::endl;
    for (int i = 0; i < maze.rows; i++) {
      for (int j = 0; j < maze.cols; j++) {
        outputFile << maze.onRight[i][j] << " ";
      }
      outputFile << std::endl;
    }
    outputFile << std::endl;
    for (int i = 0; i < maze.rows; i++) {
      for (int j = 0; j < maze.cols; j++) {
        outputFile << maze.onBottom[i][j] << " ";
      }
      outputFile << std::endl;
    }
    outputFile.close();
  }
}

std::string FileWorker::getNewFileName(const std::string &directory) {
  int maxFileNum = 0;
  for (const auto &entry : std::filesystem::directory_iterator(directory)) {
    std::string name = entry.path().filename();
    std::string currenFileNumStr;
    for (char c : name) {
      if (isdigit(c)) {
        currenFileNumStr += c;
      }
    }
    int currenFileNum = std::stoi(currenFileNumStr);
    if (maxFileNum < currenFileNum) {
      maxFileNum = currenFileNum;
    }
  }
  std::ostringstream oss;
  oss << "./" << directory << "/"
      << "maze" << maxFileNum + 1 << ".txt";
  std::string newFileName = oss.str();
  return newFileName;
}

Cave FileWorker::loadCave(const std::string &fileName) {
  Cave result;
  result.cols = 0;
  result.rows = 0;
  std::ifstream inputFile(fileName);

  if (inputFile.is_open()) {
    inputFile >> result.rows;
    inputFile >> result.cols;
    result.isAlive.resize(result.rows, std::vector<int>(result.cols));
    for (int i = 0; i < result.rows; i++) {
      for (int j = 0; j < result.cols; j++) {
        inputFile >> result.isAlive[i][j];
      }
    }
    inputFile.close();
  }
  return result;
}

};  // namespace s21
