#ifndef MODEL_H
#define MODEL_H

#include <stdint.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "memento.h"

using std::string;
using std::vector;

namespace s21 {

class Model {
 public:
  Model(){};
  ~Model();

  std::pair<vector<float>, vector<unsigned int>> Start(const string &str);
  void Open(const string &str1);
  int CountWords(const string &str);
  void RemoveMatrix();

  double GradToRad(double grad);
  void RotationX(vector<float> &A, double angle);
  void RotationY(vector<float> &A, double angle);
  void RotationZ(vector<float> &A, double angle);
  void MoveX(vector<float> &A, double a);
  void MoveY(vector<float> &A, double a);
  void MoveZ(vector<float> &A, double a);
  void ScaleX(vector<float> &A, double k);
  void ScaleY(vector<float> &A, double k);
  void ScaleZ(vector<float> &A, double k);
  void ScaleXyz(vector<float> &A, double k);

  void SetAllChange(vector<float> &A, const memento &cur, const memento &prev);

 private:
  vector<float> vertexes_;
  vector<unsigned int> facets_;
};

}  // namespace s21

#endif  // MODEL_H
