#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QTextStream>
#include <QTime>
#include <QTimer>

#include "memento.h"
#include "qgifimage.h"
#include "singleton.h"

QT_BEGIN_NAMESPACE namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void TranslateLeft();
  void TranslateRight();
  void RotateLeft();
  void RotateRight();
  void ScaleLeft();
  void ScaleRight();
  void ScaleAll();

  void on_open_file_clicked();

  void on_type_of_edges_activated(int index);
  void on_type_of_protection_activated(int index);
  void on_thickness_of_edges_activated();
  void on_display_of_verticles_activated(int index);
  void on_size_of_verticles_activated();

  void on_color_edges_clicked();
  void on_color_back_clicked();
  void on_color_verticles_clicked();

  void SaveMemento();
  void SaveSettings();
  void LoadSettings();

  void on_to_JPG_clicked();
  void on_to_GIF_clicked();
  void MakeGif();

  void on_to_Rollback_clicked();

 private:
  Ui::MainWindow *ui;
  s21::Singleton &controller_ = s21::Singleton::GetInstance();
  vector<memento> memento_state_;
  QGifImage *gif_;
  QTimer *timer_;
  int screenshots_;
};
#endif  // MAINWINDOW_H
