#include "geometryengine.h"
//#include <iostream>

using namespace std;
// using namespace s21;

GeometryEngine::GeometryEngine() : indexBuf_(QOpenGLBuffer::IndexBuffer) {
  initializeOpenGLFunctions();
  arrayBuf_.create();
  indexBuf_.create();
  InitCubeGeometry();
}

GeometryEngine::~GeometryEngine() {
  arrayBuf_.destroy();
  indexBuf_.destroy();
}

void GeometryEngine::InitCubeGeometry() {
  arrayBuf_.bind();
  arrayBuf_.allocate(vertices_indices.first.data(),
                     vertices_indices.first.size() * sizeof(float));
  indexBuf_.bind();
  indexBuf_.allocate(vertices_indices.second.data(),
                     vertices_indices.second.size() * sizeof(unsigned int));
}

void GeometryEngine::DrawCubeGeometry(QOpenGLShaderProgram *program) {
  indexBuf_.bind();
  if (arrayBuf_.isCreated()) {
    arrayBuf_.destroy();
    arrayBuf_.create();
    arrayBuf_.bind();
    arrayBuf_.allocate(vertices_indices.first.data(),
                       vertices_indices.first.size() * sizeof(float));
  }
  arrayBuf_.bind();

  quintptr offset = 0;

  int vertexLocation = program->attributeLocation("a_position");
  program->enableAttributeArray(vertexLocation);
  program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3,
                              sizeof(float) * 3);

  offset += sizeof(float);

  int texcoordLocation = program->attributeLocation("a_texcoord");
  program->enableAttributeArray(texcoordLocation);
  program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2,
                              sizeof(float) * 3);

  glDrawElements(GL_LINES, vertices_indices.second.size(), GL_UNSIGNED_INT,
                 nullptr);
}

void GeometryEngine::DrawDots(QOpenGLShaderProgram *program) {
  if (dot_type == 0) return;
  if (dot_type == 1) {
    glDisable(GL_POINT_SIZE);
    glEnable(GL_POINT_SMOOTH);
  } else {
    glDisable(GL_POINT_SMOOTH);
    glEnable(GL_POINT_SIZE);
  }
  glPointSize(size_vert);
  indexBuf_.bind();
  if (arrayBuf_.isCreated()) {
    arrayBuf_.destroy();
    arrayBuf_.create();
    arrayBuf_.bind();
    arrayBuf_.allocate(vertices_indices.first.data(),
                       vertices_indices.first.size() * sizeof(float));
  }
  arrayBuf_.bind();

  quintptr offset = 0;

  int vertexLocation = program->attributeLocation("a_position");
  program->enableAttributeArray(vertexLocation);
  program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3,
                              sizeof(float) * 3);

  offset += sizeof(float);

  int texcoordLocation = program->attributeLocation("a_texcoord");
  program->enableAttributeArray(texcoordLocation);
  program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2,
                              sizeof(float) * 3);
  glDrawElements(GL_POINTS, vertices_indices.second.size(), GL_UNSIGNED_INT,
                 nullptr);
}
