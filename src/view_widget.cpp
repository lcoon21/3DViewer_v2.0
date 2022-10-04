#include "view_widget.h"

view_widget::~view_widget() {
  makeCurrent();
  delete texture;
  delete geometries;
  doneCurrent();
}

void view_widget::initializeGL() {
  initializeOpenGLFunctions();
  glClearColor(0, 0, 0, 1);
  InitShaders();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  geometries = new GeometryEngine;
}

void view_widget::InitShaders() {
  if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vshader.glsl"))
    close();

  if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                       ":/fshader.glsl"))
    close();

  if (!program.link()) close();
  if (!program.bind()) close();
}

void view_widget::InitColors() {
  glClearColor(color_back->redF(), color_back->greenF(), color_back->blueF(),
               0);

  int vertexLocation = program.attributeLocation("vertex");
  int colorLocation = program.uniformLocation("color");

  program.enableAttributeArray(vertexLocation);
  program.setUniformValue(colorLocation, *color);
  program.disableAttributeArray(vertexLocation);
}

void view_widget::InitColorsVer() {
  glClearColor(color_back->redF(), color_back->greenF(), color_back->blueF(),
               0);

  int vertexLocation = program.attributeLocation("vertex");
  int colorLocation = program.uniformLocation("color");

  program.enableAttributeArray(vertexLocation);
  program.setUniformValue(colorLocation, *color_ver);
  program.disableAttributeArray(vertexLocation);
}

void view_widget::resizeGL(int w, int h) {
  qreal aspect = qreal(w) / qreal(h ? h : 1);
  const qreal zNear = 0.1, zFar = 1000.0, fov = 45.0;

  projection.setToIdentity();
  if (check_projection == 1) {
    QRectF orthoRectangle;
    orthoRectangle.setHeight(h);
    orthoRectangle.setWidth(w);
    projection.ortho(-10.0, 10.0, -10.0, 10.0, -100, 100);
  } else {
    projection.perspective(fov, aspect, zNear, zFar);
  }
}

void view_widget::paintGL() {
  glLineWidth(line_width);
  InitColors();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  QMatrix4x4 matrix;
  matrix.translate(0.0, 0.0, -5.0);
  matrix.rotate(rotation);

  program.setUniformValue("mvp_matrix", projection * matrix);

  if (line_type) {
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2, 58360);
    geometries->DrawCubeGeometry(&program);
    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_LINE_STIPPLE);
  } else {
    geometries->DrawCubeGeometry(&program);
  }
  InitColorsVer();
  geometries->DrawDots(&program);
}
