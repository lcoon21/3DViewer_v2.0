#ifndef CONVERTER_H
#define CONVERTER_H

#include <QOpenGLFunctions>

#include "model.h"

namespace s21 {

class Converter {
 public:
  Converter(){};
  ~Converter(){};

  void CheckFileName(const QString& str,
                     std::pair<std::vector<float>, std::vector<unsigned int>>&
                         indices_vertices) {
    if (str.isEmpty() || !str.endsWith(".obj"))
      throw std::invalid_argument("File doesn't exist");
    if (!(indices_vertices.first.empty() && indices_vertices.second.empty())) {
      indices_vertices.first.clear();
      indices_vertices.second.clear();
    }
  }
};

}  // namespace s21

#endif  // CONVERTER_H
