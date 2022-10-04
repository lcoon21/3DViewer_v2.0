#include "controller.h"

using namespace s21;

std::pair<std::vector<float>, std::vector<unsigned int>> Controller::Start(
    const string &str) {
  std::pair<vector<float>, vector<unsigned int>> vectors = model_.Start(str);
  return vectors;
}

void Controller::RotationX(std::vector<float> &A, double angle) {
  model_.RotationX(A, angle);
}

void Controller::RotationY(std::vector<float> &A, double angle) {
  model_.RotationY(A, angle);
}

void Controller::RotationZ(std::vector<float> &A, double angle) {
  model_.RotationZ(A, angle);
}

void Controller::MoveX(std::vector<float> &A, double angle) {
  model_.MoveX(A, angle);
}

void Controller::MoveY(std::vector<float> &A, double angle) {
  model_.MoveY(A, angle);
}

void Controller::MoveZ(std::vector<float> &A, double angle) {
  model_.MoveZ(A, angle);
}

void Controller::ScaleX(std::vector<float> &A, double angle) {
  model_.ScaleX(A, angle);
}

void Controller::ScaleY(std::vector<float> &A, double angle) {
  model_.ScaleY(A, angle);
}

void Controller::ScaleZ(std::vector<float> &A, double angle) {
  model_.ScaleZ(A, angle);
}

void Controller::ScaleXyz(std::vector<float> &A, double angle) {
  model_.ScaleXyz(A, angle);
}

void Controller::CheckFileName(
    const QString &str, std::pair<std::vector<float>, std::vector<unsigned int>>
                            &indices_vertices) {
  converter_.CheckFileName(str, indices_vertices);
}

void Controller::SetAllChange(std::vector<float> &A, const memento &cur,
                              const memento &prev) {
  model_.SetAllChange(A, cur, prev);
}
