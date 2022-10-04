#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->openGLWidget->update();

  connect(ui->translate_left_x, SIGNAL(clicked()), this, SLOT(TranslateLeft()));
  connect(ui->translate_left_y, SIGNAL(clicked()), this, SLOT(TranslateLeft()));
  connect(ui->translate_left_z, SIGNAL(clicked()), this, SLOT(TranslateLeft()));

  connect(ui->translate_right_x, SIGNAL(clicked()), this,
          SLOT(TranslateRight()));
  connect(ui->translate_right_y, SIGNAL(clicked()), this,
          SLOT(TranslateRight()));
  connect(ui->translate_right_z, SIGNAL(clicked()), this,
          SLOT(TranslateRight()));

  connect(ui->rotate_left_x, SIGNAL(clicked()), this, SLOT(RotateLeft()));
  connect(ui->rotate_left_y, SIGNAL(clicked()), this, SLOT(RotateLeft()));
  connect(ui->rotate_left_z, SIGNAL(clicked()), this, SLOT(RotateLeft()));

  connect(ui->rotate_right_x, SIGNAL(clicked()), this, SLOT(RotateRight()));
  connect(ui->rotate_right_y, SIGNAL(clicked()), this, SLOT(RotateRight()));
  connect(ui->rotate_right_z, SIGNAL(clicked()), this, SLOT(RotateRight()));

  connect(ui->scale_left_x, SIGNAL(clicked()), this, SLOT(ScaleLeft()));
  connect(ui->scale_left_y, SIGNAL(clicked()), this, SLOT(ScaleLeft()));
  connect(ui->scale_left_z, SIGNAL(clicked()), this, SLOT(ScaleLeft()));

  connect(ui->scale_right_x, SIGNAL(clicked()), this, SLOT(ScaleRight()));
  connect(ui->scale_right_y, SIGNAL(clicked()), this, SLOT(ScaleRight()));
  connect(ui->scale_right_z, SIGNAL(clicked()), this, SLOT(ScaleRight()));

  connect(ui->scale_left_all, SIGNAL(clicked()), this, SLOT(ScaleAll()));
  connect(ui->scale_right_all, SIGNAL(clicked()), this, SLOT(ScaleAll()));

  gif_ = new QGifImage;
  timer_ = new QTimer();
  connect(timer_, SIGNAL(timeout()), this, SLOT(MakeGif()));

  LoadSettings();
}

MainWindow::~MainWindow() {
  SaveSettings();
  delete ui;
}

void MainWindow::TranslateLeft() {
  double temp;
  QPushButton *button = (QPushButton *)sender();
  QString but = button->objectName();
  if (!but.compare("translate_left_x")) {
    controller_.GetData().MoveX(
        ui->openGLWidget->geometries->vertices_indices.first, -0.5);
    temp = ui->tr_x->text().toDouble() - 0.5;
    QString str = QString("%1").arg(temp);
    ui->tr_x->setText(str);
  } else if (!but.compare("translate_left_y")) {
    controller_.GetData().MoveY(
        ui->openGLWidget->geometries->vertices_indices.first, -0.5);
    temp = ui->tr_y->text().toDouble() - 0.5;
    QString str = QString("%1").arg(temp);
    ui->tr_y->setText(str);
  } else if (!but.compare("translate_left_z")) {
    controller_.GetData().MoveZ(
        ui->openGLWidget->geometries->vertices_indices.first, -0.5);
    temp = ui->tr_z->text().toDouble() - 0.5;
    QString str = QString("%1").arg(temp);
    ui->tr_z->setText(str);
  }
  ui->openGLWidget->update();
  SaveMemento();
}

void MainWindow::TranslateRight() {
  double temp;
  QPushButton *button = (QPushButton *)sender();
  QString but = button->objectName();
  if (!but.compare("translate_right_x")) {
    controller_.GetData().MoveX(
        ui->openGLWidget->geometries->vertices_indices.first, 0.5);
    temp = ui->tr_x->text().toDouble() + 0.5;
    QString str = QString("%1").arg(temp);
    ui->tr_x->setText(str);
  } else if (!but.compare("translate_right_y")) {
    controller_.GetData().MoveY(
        ui->openGLWidget->geometries->vertices_indices.first, 0.5);
    temp = ui->tr_y->text().toDouble() + 0.5;
    QString str = QString("%1").arg(temp);
    ui->tr_y->setText(str);
  } else if (!but.compare("translate_right_z")) {
    controller_.GetData().MoveZ(
        ui->openGLWidget->geometries->vertices_indices.first, 0.5);
    temp = ui->tr_z->text().toDouble() + 0.5;
    QString str = QString("%1").arg(temp);
    ui->tr_z->setText(str);
  }
  ui->openGLWidget->update();
  SaveMemento();
}

void MainWindow::RotateLeft() {
  double temp;
  QPushButton *button = (QPushButton *)sender();
  QString but = button->objectName();
  if (!but.compare("rotate_left_x")) {
    controller_.GetData().RotationX(
        ui->openGLWidget->geometries->vertices_indices.first, -10.5);
    temp = ui->rot_x->text().toDouble() - 10.5;
    QString str = QString("%1").arg(temp);
    ui->rot_x->setText(str);
  } else if (!but.compare("rotate_left_y")) {
    controller_.GetData().RotationY(
        ui->openGLWidget->geometries->vertices_indices.first, -10.5);
    temp = ui->rot_y->text().toDouble() - 10.5;
    QString str = QString("%1").arg(temp);
    ui->rot_y->setText(str);
  } else if (!but.compare("rotate_left_z")) {
    controller_.GetData().RotationZ(
        ui->openGLWidget->geometries->vertices_indices.first, -10.5);
    temp = ui->rot_z->text().toDouble() - 10.5;
    QString str = QString("%1").arg(temp);
    ui->rot_z->setText(str);
  }
  ui->openGLWidget->update();
  SaveMemento();
}

void MainWindow::RotateRight() {
  double temp;
  QPushButton *button = (QPushButton *)sender();
  QString but = button->objectName();
  if (!but.compare("rotate_right_x")) {
    controller_.GetData().RotationX(
        ui->openGLWidget->geometries->vertices_indices.first, 10.5);
    temp = ui->rot_x->text().toDouble() + 10.5;
    QString str = QString("%1").arg(temp);
    ui->rot_x->setText(str);
  } else if (!but.compare("rotate_right_y")) {
    controller_.GetData().RotationY(
        ui->openGLWidget->geometries->vertices_indices.first, 10.5);
    temp = ui->rot_y->text().toDouble() + 10.5;
    QString str = QString("%1").arg(temp);
    ui->rot_y->setText(str);
  } else if (!but.compare("rotate_right_z")) {
    controller_.GetData().RotationZ(
        ui->openGLWidget->geometries->vertices_indices.first, 10.5);
    temp = ui->rot_z->text().toDouble() + 10.5;
    QString str = QString("%1").arg(temp);
    ui->rot_z->setText(str);
  }
  ui->openGLWidget->update();
  SaveMemento();
}

void MainWindow::ScaleLeft() {
  double temp;
  QPushButton *button = (QPushButton *)sender();
  QString but = button->objectName();
  if (!but.compare("scale_left_x")) {
    controller_.GetData().ScaleX(
        ui->openGLWidget->geometries->vertices_indices.first, -1.5);
    temp = ui->sc_x->text().toDouble() - 1.5;
    QString str = QString("%1").arg(temp);
    ui->sc_x->setText(str);
  } else if (!but.compare("scale_left_y")) {
    controller_.GetData().ScaleY(
        ui->openGLWidget->geometries->vertices_indices.first, -1.5);
    temp = ui->sc_y->text().toDouble() - 1.5;
    QString str = QString("%1").arg(temp);
    ui->sc_y->setText(str);
  } else if (!but.compare("scale_left_z")) {
    controller_.GetData().ScaleZ(
        ui->openGLWidget->geometries->vertices_indices.first, -1.5);
    temp = ui->sc_z->text().toDouble() - 1.5;
    QString str = QString("%1").arg(temp);
    ui->sc_z->setText(str);
  }
  ui->openGLWidget->update();
  SaveMemento();
}

void MainWindow::ScaleRight() {
  double temp;
  QPushButton *button = (QPushButton *)sender();
  QString but = button->objectName();
  if (!but.compare("scale_right_x")) {
    controller_.GetData().ScaleX(
        ui->openGLWidget->geometries->vertices_indices.first, 1.5);
    temp = ui->sc_x->text().toDouble() + 1.5;
    QString str = QString("%1").arg(temp);
    ui->sc_x->setText(str);
  } else if (!but.compare("scale_right_y")) {
    controller_.GetData().ScaleY(
        ui->openGLWidget->geometries->vertices_indices.first, 1.5);
    temp = ui->sc_y->text().toDouble() + 1.5;
    QString str = QString("%1").arg(temp);
    ui->sc_y->setText(str);
  } else if (!but.compare("scale_right_z")) {
    controller_.GetData().ScaleZ(
        ui->openGLWidget->geometries->vertices_indices.first, 1.5);
    temp = ui->sc_z->text().toDouble() + 1.5;
    QString str = QString("%1").arg(temp);
    ui->sc_z->setText(str);
  }
  ui->openGLWidget->update();
  SaveMemento();
}

void MainWindow::ScaleAll() {
  double temp;
  QPushButton *button = (QPushButton *)sender();
  QString but = button->objectName();
  if (!but.compare("scale_left_all")) {
    controller_.GetData().ScaleXyz(
        ui->openGLWidget->geometries->vertices_indices.first, -1.5);
    temp = ui->sc_all->text().toDouble() - 1.5;
  } else if (!but.compare("scale_right_all")) {
    controller_.GetData().ScaleXyz(
        ui->openGLWidget->geometries->vertices_indices.first, 1.5);
    temp = ui->sc_all->text().toDouble() + 1.5;
  }
  QString str = QString("%1").arg(temp);
  ui->sc_all->setText(str);
  ui->openGLWidget->update();
  SaveMemento();
}

void MainWindow::on_color_edges_clicked() {
  *ui->openGLWidget->color = QColorDialog::getColor();
  ui->openGLWidget->paintGL();
  ui->openGLWidget->update();
  SaveMemento();
}

void MainWindow::on_color_back_clicked() {
  *ui->openGLWidget->color_back = QColorDialog::getColor();
  ui->openGLWidget->paintGL();
  ui->openGLWidget->update();
  SaveMemento();
}

void MainWindow::on_color_verticles_clicked() {
  *ui->openGLWidget->color_ver = QColorDialog::getColor();
  ui->openGLWidget->update();
  SaveMemento();
}

void MainWindow::on_open_file_clicked() {
  try {
    QString file_path =
        QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.*");
    controller_.GetData().CheckFileName(
        file_path, ui->openGLWidget->geometries->vertices_indices);
    QFileInfo file_info(file_path);
    QString file_name = file_info.fileName();
    ui->openGLWidget->geometries->vertices_indices =
        controller_.GetData().Start(file_path.toStdString());
    ui->file_name->setText(file_name);
    ui->num_of_verticles->setText(QString::number(
        ui->openGLWidget->geometries->vertices_indices.first.size() / 3));
    ui->num_of_edges->setText(QString::number(
        ui->openGLWidget->geometries->vertices_indices.second.size() / 6));
    ui->tr_x->setText("0");
    ui->tr_y->setText("0");
    ui->tr_z->setText("0");
    ui->rot_x->setText("0");
    ui->rot_y->setText("0");
    ui->rot_z->setText("0");
    ui->sc_x->setText("0");
    ui->sc_y->setText("0");
    ui->sc_z->setText("0");
    ui->sc_all->setText("0");
  } catch (std::exception &ex) {
  }
  memento_state_.clear();
  SaveMemento();
  ui->openGLWidget->geometries->dot_type =
      ui->display_of_verticles->currentIndex();
  ui->openGLWidget->geometries->size_vert =
      ui->size_of_verticles->currentText().toDouble();
  ui->openGLWidget->geometries->InitCubeGeometry();
}

void MainWindow::on_type_of_protection_activated(int index) {
  ui->openGLWidget->check_projection = index;
  ui->openGLWidget->resizeGL(640, 480);
  ui->openGLWidget->update();
  SaveMemento();
}

void MainWindow::on_thickness_of_edges_activated() {
  ui->openGLWidget->line_width =
      ui->thickness_of_edges->currentText().toDouble();
  ui->openGLWidget->update();
  SaveMemento();
}

void MainWindow::on_display_of_verticles_activated(int index) {
  ui->openGLWidget->geometries->dot_type = index;
  ui->openGLWidget->update();
  SaveMemento();
}

void MainWindow::on_size_of_verticles_activated() {
  ui->openGLWidget->geometries->size_vert =
      ui->size_of_verticles->currentText().toInt();
  ui->openGLWidget->update();
  SaveMemento();
}

void MainWindow::on_type_of_edges_activated(int index) {
  ui->openGLWidget->line_type = index;
  ui->openGLWidget->update();
  SaveMemento();
}

void MainWindow::on_to_JPG_clicked() {
  QImage screen = this->ui->openGLWidget->grabFramebuffer();
  QString file_path =
      QFileDialog::getSaveFileName(this, "Save image as...", QDir::homePath(),
                                   "BMP-file (*.bmp);;JPEG-file (*.jpeg)");
  if (!file_path.isEmpty() || !file_path.isNull()) screen.save(file_path);
}

void MainWindow::MakeGif() {
  if (screenshots_ < 50) {
    QImage screen = this->ui->openGLWidget->grabFramebuffer();
    gif_->addFrame(screen, 5);
    ++screenshots_;
  }
  if (screenshots_ == 50) {
    timer_->stop();
    screenshots_ = 0;
    QString file_path = QFileDialog::getSaveFileName(
        this, "Save gif as...", QDir::homePath(), "GIF-file (*.gif)");
    if (!file_path.isEmpty() || !file_path.isNull()) gif_->save(file_path);
    delete gif_;
    gif_ = new QGifImage;
  }
}

void MainWindow::on_to_GIF_clicked() { timer_->start(150); }

void MainWindow::SaveMemento() {
  memento state;
  state.type_of_protection_ = ui->type_of_protection->currentIndex();
  state.type_of_edges_ = ui->type_of_edges->currentIndex();
  state.thickness_of_edges_ = ui->thickness_of_edges->currentIndex();
  state.display_of_verticles_ = ui->display_of_verticles->currentIndex();
  state.size_of_verticles_ = ui->size_of_verticles->currentIndex();
  ui->openGLWidget->color->getRgb(&state.color_[0], &state.color_[1],
                                  &state.color_[2], &state.color_[3]);
  ui->openGLWidget->color_back->getRgb(
      &state.color_back_[0], &state.color_back_[1], &state.color_back_[2],
      &state.color_back_[3]);
  ui->openGLWidget->color_ver->getRgb(
      &state.color_ver_[0], &state.color_ver_[1], &state.color_ver_[2],
      &state.color_ver_[3]);
  state.tr_x_ = ui->tr_x->text().toDouble();
  state.tr_y_ = ui->tr_y->text().toDouble();
  state.tr_z_ = ui->tr_z->text().toDouble();
  state.rot_x_ = ui->rot_x->text().toDouble();
  state.rot_y_ = ui->rot_y->text().toDouble();
  state.rot_z_ = ui->rot_z->text().toDouble();
  state.sc_x_ = ui->sc_x->text().toDouble();
  state.sc_y_ = ui->sc_y->text().toDouble();
  state.sc_z_ = ui->sc_z->text().toDouble();
  state.sc_all_ = ui->sc_all->text().toDouble();
  memento_state_.push_back(state);
}

void MainWindow::on_to_Rollback_clicked() {
  if (memento_state_.empty() || memento_state_.size() == 1) return;
  memento cur = memento_state_.back();
  memento_state_.pop_back();
  memento prev = memento_state_.back();

  ui->type_of_protection->setCurrentIndex(prev.type_of_protection_);
  ui->openGLWidget->check_projection = ui->type_of_protection->currentIndex();
  ui->openGLWidget->resizeGL(640, 480);

  ui->type_of_edges->setCurrentIndex(prev.type_of_edges_);
  ui->openGLWidget->line_type = ui->type_of_edges->currentIndex();

  ui->thickness_of_edges->setCurrentIndex(prev.thickness_of_edges_);
  ui->openGLWidget->line_width =
      ui->thickness_of_edges->currentText().toDouble();

  ui->display_of_verticles->setCurrentIndex(prev.display_of_verticles_);
  ui->openGLWidget->geometries->dot_type =
      ui->display_of_verticles->currentIndex();

  ui->size_of_verticles->setCurrentIndex(prev.size_of_verticles_);
  ui->openGLWidget->geometries->size_vert =
      ui->size_of_verticles->currentText().toDouble();

  ui->openGLWidget->color->setRgb(prev.color_[0], prev.color_[1],
                                  prev.color_[2], prev.color_[3]);
  ui->openGLWidget->color_back->setRgb(prev.color_back_[0], prev.color_back_[1],
                                       prev.color_back_[2],
                                       prev.color_back_[3]);
  ui->openGLWidget->color_ver->setRgb(prev.color_ver_[0], prev.color_ver_[1],
                                      prev.color_ver_[2], prev.color_ver_[3]);

  ui->tr_x->setText(QString("%1").arg(prev.tr_x_));
  ui->tr_y->setText(QString("%1").arg(prev.tr_y_));
  ui->tr_z->setText(QString("%1").arg(prev.tr_z_));
  ui->rot_x->setText(QString("%1").arg(prev.rot_x_));
  ui->rot_y->setText(QString("%1").arg(prev.rot_y_));
  ui->rot_z->setText(QString("%1").arg(prev.rot_z_));
  ui->sc_x->setText(QString("%1").arg(prev.sc_x_));
  ui->sc_y->setText(QString("%1").arg(prev.sc_y_));
  ui->sc_z->setText(QString("%1").arg(prev.sc_z_));
  ui->sc_all->setText(QString("%1").arg(prev.sc_all_));

  controller_.GetData().SetAllChange(
      ui->openGLWidget->geometries->vertices_indices.first, cur, prev);
  ui->openGLWidget->update();
}

void MainWindow::SaveSettings() {
  QString path = "";
  path += QCoreApplication::applicationDirPath();
  path += "/settings.cfg";
  QFile file(path);
  if (file.open(QIODevice::ReadWrite)) {
    QTextStream t_stream(&file);
    t_stream.flush();
    t_stream << ui->type_of_protection->currentIndex() << '\n';
    t_stream << ui->type_of_edges->currentIndex() << '\n';
    t_stream << ui->thickness_of_edges->currentIndex() << '\n';
    t_stream << ui->display_of_verticles->currentIndex() << '\n';
    t_stream << ui->size_of_verticles->currentIndex() << '\n';
    int red, green, blue, alpha;
    ui->openGLWidget->color->getRgb(&red, &green, &blue, &alpha);
    t_stream << red << ' ' << green << ' ' << blue << ' ' << alpha << '\n';
    ui->openGLWidget->color_back->getRgb(&red, &green, &blue, &alpha);
    t_stream << red << ' ' << green << ' ' << blue << ' ' << alpha << '\n';
    ui->openGLWidget->color_ver->getRgb(&red, &green, &blue, &alpha);
    t_stream << red << ' ' << green << ' ' << blue << ' ' << alpha << '\n';
    file.close();
  }
}

void MainWindow::LoadSettings() {
  QString path = "";
  path = QCoreApplication::applicationDirPath();
  path += "/settings.cfg";
  QFile file(path);
  if (file.open(QIODevice::ReadOnly)) {
    QTextStream t_stream(&file);
    QString str = t_stream.readLine();

    ui->type_of_protection->setCurrentIndex(str.toInt());
    ui->openGLWidget->check_projection = ui->type_of_protection->currentIndex();
    ui->openGLWidget->resizeGL(640, 480);

    str = t_stream.readLine();
    ui->type_of_edges->setCurrentIndex(str.toInt());
    ui->openGLWidget->line_type = ui->type_of_edges->currentIndex();

    str = t_stream.readLine();
    ui->thickness_of_edges->setCurrentIndex(str.toInt());
    ui->openGLWidget->line_width =
        ui->thickness_of_edges->currentText().toDouble();

    str = t_stream.readLine();
    ui->display_of_verticles->setCurrentIndex(str.toInt());

    str = t_stream.readLine();
    ui->size_of_verticles->setCurrentIndex(str.toInt());

    str = t_stream.readLine();
    QList<QString> clr = str.split(' ');
    ui->openGLWidget->color->setRgb(clr[0].toInt(), clr[1].toInt(),
                                    clr[2].toInt(), clr[3].toInt());
    clr.clear();

    str = t_stream.readLine();
    clr = str.split(' ');
    ui->openGLWidget->color_back->setRgb(clr[0].toInt(), clr[1].toInt(),
                                         clr[2].toInt(), clr[3].toInt());
    clr.clear();

    str = t_stream.readLine();
    clr = str.split(' ');
    ui->openGLWidget->color_ver->setRgb(clr[0].toInt(), clr[1].toInt(),
                                        clr[2].toInt(), clr[3].toInt());
    file.close();
  }
  ui->openGLWidget->update();
}
