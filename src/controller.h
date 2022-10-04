#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QOpenGLFunctions>

#include "converter.h"
#include "model.h"

namespace s21 {

class Controller {
 public:
  Controller(){};
  ~Controller(){};

  std::pair<std::vector<float>, std::vector<unsigned int>> Start(
      const string &str);

  void RotationX(std::vector<float> &A, double angle);
  void RotationY(std::vector<float> &A, double angle);
  void RotationZ(std::vector<float> &A, double angle);
  void MoveX(std::vector<float> &A, double angle);
  void MoveY(std::vector<float> &A, double angle);
  void MoveZ(std::vector<float> &A, double angle);
  void ScaleX(std::vector<float> &A, double angle);
  void ScaleY(std::vector<float> &A, double angle);
  void ScaleZ(std::vector<float> &A, double angle);
  void ScaleXyz(std::vector<float> &A, double angle);

  void SetAllChange(std::vector<float> &A, const memento &cur,
                    const memento &prev);

  void CheckFileName(const QString &str,
                     std::pair<std::vector<float>, std::vector<unsigned int>>
                         &indices_vertices);

 private:
  Model model_;
  Converter converter_;
};

}  // namespace s21

#endif  // CONTROLLER_H
