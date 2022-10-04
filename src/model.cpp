#include "model.h"

using namespace s21;

Model::~Model() {
  vertexes_.clear();
  facets_.clear();
}

std::pair<vector<float>, vector<unsigned int>> Model::Start(const string &str) {
  if (!(vertexes_.empty() && facets_.empty())) {
    vertexes_.clear();
    facets_.clear();
  }
  if (str.empty()) {
    throw std::logic_error("Path of file is empty!");
  } else {
    Open(str);
  }
  return std::make_pair(vertexes_, facets_);
}

void Model::Open(const string &str1) {
  std::ifstream in(str1);
  if (!in.is_open()) {
    throw std::invalid_argument("File is empty");
  }
  string line;
  float x, y, z;
  while (getline(in, line)) {
    if (line[0] == 'v' && line[1] == ' ') {
      std::istringstream iss(line.substr(2));
      iss >> x >> y >> z;
      vertexes_.push_back(x);
      vertexes_.push_back(y);
      vertexes_.push_back(z);
    } else if (line[0] == 'f' && line[1] == ' ') {
      int s = 0, cnt = 0;
      vector<unsigned int> temp_facets_;
      int cnt_words = CountWords(line);
      while (cnt != cnt_words) {
        int num;
        string very_temp = line.substr(1);
        if (very_temp[s] == ' ' && isdigit(very_temp[s + 1])) {
          std::istringstream iss(very_temp.substr(s + 1));
          iss >> num;
          temp_facets_.push_back(num);
          cnt++;
        }
        s++;
      }
      for (int i = 0, len = temp_facets_.size() - 1; i < len; ++i) {
        facets_.push_back(temp_facets_[i] - 1);
        facets_.push_back(temp_facets_[i + 1] - 1);
      }
      facets_.push_back(temp_facets_[0] - 1);
      facets_.push_back(temp_facets_[temp_facets_.size() - 1] - 1);
      temp_facets_.clear();
    }
  }
  in.close();
}

int Model::CountWords(const string &str) {
  int cnt = 1;
  for (int i = 0, len = str.length(); i < len; ++i) {
    if (str[i] == ' ' && isdigit(str[i - 1]) && isdigit(str[i + 1])) {
      cnt++;
    }
  }
  return cnt;
}

void Model::RemoveMatrix() {
  vertexes_.clear();
  facets_.clear();
}

double Model::GradToRad(double grad) { return grad * M_PI / 180; }

void Model::RotationX(vector<float> &A, double angle) {
  angle = GradToRad(angle);
  for (size_t i = 0; i < A.size(); i += 3) {
    double y = A[i + 1];
    double z = A[i + 2];
    A[i + 1] = cos(angle) * y - sin(angle) * z;
    A[i + 2] = sin(angle) * y + cos(angle) * z;
  }
}

void Model::RotationY(vector<float> &A, double angle) {
  angle = GradToRad(angle);
  for (size_t i = 0; i < A.size(); i += 3) {
    double x = A[i];
    double z = A[i + 2];
    A[i] = cos(angle) * x - sin(angle) * z;
    A[i + 2] = sin(angle) * x + cos(angle) * z;
  }
}

void Model::RotationZ(vector<float> &A, double angle) {
  angle = GradToRad(angle);
  for (size_t i = 0; i < A.size(); i += 3) {
    double x = A[i];
    double y = A[i + 1];
    A[i] = cos(angle) * x - sin(angle) * y;
    A[i + 1] = sin(angle) * x + cos(angle) * y;
  }
}

void Model::MoveX(vector<float> &A, double a) {
  for (size_t i = 0; i < A.size(); i += 3) {
    A[i] += a;
  }
}

void Model::MoveY(vector<float> &A, double a) {
  for (size_t i = 0; i < A.size(); i += 3) {
    A[i + 1] += a;
  }
}

void Model::MoveZ(vector<float> &A, double a) {
  for (size_t i = 0; i < A.size(); i += 3) {
    A[i + 2] += a;
  }
}

void Model::ScaleX(vector<float> &A, double k) {
  for (size_t i = 0; i < A.size(); i += 3) {
    if (k > 0) {
      A[i] *= k;
    } else if (k < 0) {
      A[i] /= (-1) * k;
    }
  }
}

void Model::ScaleY(vector<float> &A, double k) {
  for (size_t i = 0; i < A.size(); i += 3) {
    if (k > 0) {
      A[i + 1] *= k;
    } else if (k < 0) {
      A[i + 1] /= (-1) * k;
    }
  }
}

void Model::ScaleZ(vector<float> &A, double k) {
  for (size_t i = 0; i < A.size(); i += 3) {
    if (k > 0) {
      A[i + 2] *= k;
    } else if (k < 0) {
      A[i + 2] /= (-1) * k;
    }
  }
}

void Model::ScaleXyz(vector<float> &A, double k) {
  for (size_t i = 0; i < A.size(); i += 3) {
    if (k > 0) {
      A[i] *= k;
      A[i + 1] *= k;
      A[i + 2] *= k;
    } else if (k < 0) {
      A[i] /= -k;
      A[i + 1] /= -k;
      A[i + 2] /= -k;
    }
  }
}

void Model::SetAllChange(vector<float> &A, const memento &cur,
                         const memento &prev) {
  if (prev.rot_x_ - cur.rot_x_ != 0) RotationX(A, prev.rot_x_ - cur.rot_x_);
  if (prev.rot_y_ - cur.rot_y_ != 0) RotationY(A, prev.rot_y_ - cur.rot_y_);
  if (prev.rot_z_ - cur.rot_z_ != 0) RotationZ(A, prev.rot_z_ - cur.rot_z_);
  if (prev.tr_x_ - cur.tr_x_ != 0) MoveX(A, prev.tr_x_ - cur.tr_x_);
  if (prev.tr_y_ - cur.tr_y_ != 0) MoveY(A, prev.tr_y_ - cur.tr_y_);
  if (prev.tr_z_ - cur.tr_z_ != 0) MoveZ(A, prev.tr_z_ - cur.tr_z_);
  if (prev.sc_x_ - cur.sc_x_ != 0) ScaleX(A, prev.sc_x_ - cur.sc_x_);
  if (prev.sc_y_ - cur.sc_y_ != 0) ScaleY(A, prev.sc_y_ - cur.sc_y_);
  if (prev.sc_z_ - cur.sc_z_ != 0) ScaleZ(A, prev.sc_z_ - cur.sc_z_);
  if (prev.sc_all_ - cur.sc_all_ != 0) ScaleXyz(A, prev.sc_all_ - cur.sc_all_);
}
