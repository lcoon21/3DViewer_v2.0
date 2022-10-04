#ifndef GEOMETRYENGINE_H
#define GEOMETRYENGINE_H

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <iostream>
#include <vector>

// namespace s21 {

class GeometryEngine : protected QOpenGLFunctions {
 public:
  GeometryEngine();
  virtual ~GeometryEngine();

  void InitCubeGeometry();
  void DrawCubeGeometry(QOpenGLShaderProgram *program);
  void DrawDots(QOpenGLShaderProgram *program);
  std::pair<std::vector<float>, std::vector<unsigned int>> vertices_indices;
  int dot_type = 0;
  int size_vert = 5;

 private:
  QOpenGLBuffer arrayBuf_;
  QOpenGLBuffer indexBuf_;
};

//}  // namespace s21

#endif  // GEOMETRYENGINE_H
