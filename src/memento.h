#ifndef MEMENTO_H
#define MEMENTO_H

#include <algorithm>

typedef struct memento {
  int type_of_protection_;
  int type_of_edges_;
  int thickness_of_edges_;
  int display_of_verticles_;
  int size_of_verticles_;
  int color_[4];
  int color_back_[4];
  int color_ver_[4];
  double tr_x_;
  double tr_y_;
  double tr_z_;
  double rot_x_;
  double rot_y_;
  double rot_z_;
  double sc_x_;
  double sc_y_;
  double sc_z_;
  double sc_all_;
} memento;

namespace s21 {

class Memento {
 public:
  Memento(memento m) {
    m_.type_of_protection_ = m.type_of_protection_;
    m_.type_of_edges_ = m.type_of_edges_;
    m_.thickness_of_edges_ = m.thickness_of_edges_;
    m_.display_of_verticles_ = m.display_of_verticles_;
    m_.size_of_verticles_ = m.size_of_verticles_;
    std::swap(m_.color_, m.color_);
    std::swap(m_.color_back_, m.color_back_);
    std::swap(m_.color_ver_, m.color_ver_);
    m_.tr_x_ = m.tr_x_;
    m_.tr_y_ = m.tr_y_;
    m_.tr_z_ = m.tr_z_;
    m_.rot_x_ = m.rot_x_;
    m_.rot_y_ = m.rot_y_;
    m_.rot_z_ = m.rot_z_;
    m_.sc_x_ = m.sc_x_;
    m_.sc_y_ = m.sc_y_;
    m_.sc_z_ = m.sc_z_;
    m_.sc_all_ = m.sc_all_;
  }
  ~Memento(){};

  memento GetMemento() { return m_; }

 private:
  memento m_;
};

}  // namespace s21

#endif  // MEMENTO_H
