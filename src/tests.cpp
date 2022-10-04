#include <gtest/gtest.h>

#include "model.h"

using namespace s21;

string file_name = "./obj_files/cube.obj";

TEST(read_file, test1) {
  Model m;
  vector<float> vert_res{1.0,  -1.0, -1.0,      1.0,      -1.0, 1.0,
                         -1.0, -1.0, 1.0,       -1.0,     -1.0, -1.0,
                         1.0,  1.0,  -0.999999, 0.999999, 1.0,  1.000001,
                         -1.0, 1.0,  1.0,       -1.0,     1.0,  -1.0};

  vector<unsigned int> facets_res{
      1, 2, 2, 3, 1, 3, 7, 6, 6, 5, 7, 5, 4, 5, 5, 1, 4, 1, 5, 6, 6, 2, 5, 2,
      2, 6, 6, 7, 2, 7, 0, 3, 3, 7, 0, 7, 0, 1, 1, 3, 0, 3, 4, 7, 7, 5, 4, 5,
      0, 4, 4, 1, 0, 1, 1, 5, 5, 2, 1, 2, 3, 2, 2, 7, 3, 7, 4, 0, 0, 7, 4, 7,
  };

  std::pair<vector<float>, vector<unsigned int>> res = m.Start(file_name);

  for (size_t i = 0; i < vert_res.size(); ++i) {
    ASSERT_LE(fabs(res.first[i] - vert_res[i]), 1e-7);
  }

  for (size_t i = 0; i < facets_res.size(); ++i) {
    ASSERT_LE(fabs(res.second[i] - facets_res[i]), 1e-7);
  }
}

TEST(move_x, test1) {
  Model m;
  vector<float> vert_res{2.0, -1.0, -1.0,      2.0,      -1.0, 1.0,
                         0.0, -1.0, 1.0,       0.0,      -1.0, -1.0,
                         2.0, 1.0,  -0.999999, 1.999999, 1.0,  1.000001,
                         0.0, 1.0,  1.0,       0.0,      1.0,  -1.0};

  std::pair<vector<float>, vector<unsigned int>> res = m.Start(file_name);

  m.MoveX(res.first, 1.0);

  for (size_t i = 0; i < vert_res.size(); ++i) {
    ASSERT_LE(fabs(res.first[i] - vert_res[i]), 1e-7);
  }
}

TEST(move_y, test1) {
  Model m;
  vector<float> vert_res{1.0,  0.0, -1.0,      1.0,      0.0, 1.0,
                         -1.0, 0.0, 1.0,       -1.0,     0.0, -1.0,
                         1.0,  2.0, -0.999999, 0.999999, 2.0, 1.000001,
                         -1.0, 2.0, 1.0,       -1.0,     2.0, -1.0};

  std::pair<vector<float>, vector<unsigned int>> res = m.Start(file_name);

  m.MoveY(res.first, 1.0);

  for (size_t i = 0; i < res.first.size(); ++i) {
    ASSERT_LE(fabs(res.first[i] - vert_res[i]), 1e-7);
  }
}

TEST(move_z, test1) {
  Model m;
  vector<float> vert_res{1.0,  -1.0, 0.0,      1.0,      -1.0, 2.0,
                         -1.0, -1.0, 2.0,      -1.0,     -1.0, 0.0,
                         1.0,  1.0,  0.000001, 0.999999, 1.0,  2.000001,
                         -1.0, 1.0,  2.0,      -1.0,     1.0,  0.0};

  std::pair<vector<float>, vector<unsigned int>> res = m.Start(file_name);

  m.MoveZ(res.first, 1.0);

  for (size_t i = 0; i < res.first.size(); ++i) {
    ASSERT_LE(fabs(res.first[i] - vert_res[i]), 1e-7);
  }
}

TEST(rotation_x, test1) {
  Model m;
  vector<float> vert_res{1,         -0.366025, -1.366025, 1,        -1.366025,
                         0.366025,  -1,        -1.366025, 0.366025, -1.0,
                         -0.366025, -1.366025, 1,         1.366025, -0.366025,
                         0.999999,  0.366025,  1.366026,  -1.0,     0.366025,
                         1.366025,  -1.0,      1.366025,  -0.366025};

  std::pair<vector<float>, vector<unsigned int>> res = m.Start(file_name);

  m.RotationX(res.first, 30.0);

  for (size_t i = 0; i < res.first.size(); ++i) {
    ASSERT_LE(fabs(res.first[i] - vert_res[i]), 1e-6);
  }
}

TEST(rotation_y, test1) {
  Model m;
  vector<float> vert_res{1.366025,  -1, -0.366025, 0.366025,  -1, 1.366025,
                         -1.366025, -1, 0.366025,  -0.366025, -1, -1.366025,
                         1.366025,  1,  -0.366025, 0.366024,  1,  1.366025,
                         -1.366025, 1,  0.366025,  -0.366025, 1,  -1.366025};

  std::pair<vector<float>, vector<unsigned int>> res = m.Start(file_name);

  m.RotationY(res.first, 30.0);

  for (size_t i = 0; i < res.first.size(); ++i) {
    ASSERT_LE(fabs(res.first[i] - vert_res[i]), 1e-6);
  }
}

TEST(rotation_z, test1) {
  Model m;
  vector<float> vert_res{1.366025,  -0.366025, -1,        1.366025,  -0.366025,
                         1,         -0.366025, -1.366025, 1,         -0.366025,
                         -1.366025, -1,        0.366025,  1.366025,  -0.999999,
                         0.366025,  1.366025,  1,         -1.366025, 0.366025,
                         1,         -1.366025, 0.366025,  -1};

  std::pair<vector<float>, vector<unsigned int>> res = m.Start(file_name);

  m.RotationZ(res.first, 30.0);

  for (size_t i = 0; i < res.first.size(); ++i) {
    ASSERT_LE(fabs(res.first[i] - vert_res[i]), 1e-6);
  }
}

TEST(scale_x, test1) {
  Model m;
  vector<float> vert_res{1, -1, -1, 1,  -1, 1,  -1,        -1,
                         1, -1, -1, -1, 1,  1,  -0.999999, 0.999999,
                         1, 1,  -1, 1,  1,  -1, 1,         -1};

  std::pair<vector<float>, vector<unsigned int>> res = m.Start(file_name);

  m.ScaleX(res.first, 1.0);

  for (size_t i = 0; i < res.first.size(); ++i) {
    ASSERT_LE(fabs(res.first[i] - vert_res[i]), 1e-6);
  }
}

TEST(scale_x, test2) {
  Model m;
  vector<float> vert_res{1, -1, -1, 1,  -1, 1,  -1,        -1,
                         1, -1, -1, -1, 1,  1,  -0.999999, 0.999999,
                         1, 1,  -1, 1,  1,  -1, 1,         -1};

  std::pair<vector<float>, vector<unsigned int>> res = m.Start(file_name);

  m.ScaleX(res.first, -1.0);

  for (size_t i = 0; i < res.first.size(); ++i) {
    ASSERT_LE(fabs(res.first[i] - vert_res[i]), 1e-6);
  }
}

TEST(scale_y, test1) {
  Model m;
  vector<float> vert_res{1, -1, -1, 1,  -1, 1,  -1,        -1,
                         1, -1, -1, -1, 1,  1,  -0.999999, 0.999999,
                         1, 1,  -1, 1,  1,  -1, 1,         -1};

  std::pair<vector<float>, vector<unsigned int>> res = m.Start(file_name);

  m.ScaleY(res.first, 1.0);

  for (size_t i = 0; i < res.first.size(); ++i) {
    ASSERT_LE(fabs(res.first[i] - vert_res[i]), 1e-6);
  }
}

TEST(scale_y, test2) {
  Model m;
  vector<float> vert_res{1, -1, -1, 1,  -1, 1,  -1,        -1,
                         1, -1, -1, -1, 1,  1,  -0.999999, 0.999999,
                         1, 1,  -1, 1,  1,  -1, 1,         -1};

  std::pair<vector<float>, vector<unsigned int>> res = m.Start(file_name);

  m.ScaleY(res.first, -1.0);

  for (size_t i = 0; i < res.first.size(); ++i) {
    ASSERT_LE(fabs(res.first[i] - vert_res[i]), 1e-6);
  }
}

TEST(scale_z, test1) {
  Model m;
  vector<float> vert_res{1, -1, -1, 1,  -1, 1,  -1,        -1,
                         1, -1, -1, -1, 1,  1,  -0.999999, 0.999999,
                         1, 1,  -1, 1,  1,  -1, 1,         -1};

  std::pair<vector<float>, vector<unsigned int>> res = m.Start(file_name);

  m.ScaleZ(res.first, 1.0);

  for (size_t i = 0; i < res.first.size(); ++i) {
    ASSERT_LE(fabs(res.first[i] - vert_res[i]), 1e-6);
  }
}

TEST(scale_z, test2) {
  Model m;
  vector<float> vert_res{1, -1, -1, 1,  -1, 1,  -1,        -1,
                         1, -1, -1, -1, 1,  1,  -0.999999, 0.999999,
                         1, 1,  -1, 1,  1,  -1, 1,         -1};

  std::pair<vector<float>, vector<unsigned int>> res = m.Start(file_name);

  m.ScaleZ(res.first, -1.0);

  for (size_t i = 0; i < res.first.size(); ++i) {
    ASSERT_LE(fabs(res.first[i] - vert_res[i]), 1e-6);
  }
}

TEST(scale_xyz, test1) {
  Model m;
  vector<float> vert_res{
      1.0 * 2,  -1.0 * 2, -1.0 * 2,      1.0 * 2,      -1.0 * 2, 1.0 * 2,
      -1.0 * 2, -1.0 * 2, 1.0 * 2,       -1.0 * 2,     -1.0 * 2, -1.0 * 2,
      1.0 * 2,  1.0 * 2,  -0.999999 * 2, 0.999999 * 2, 1.0 * 2,  1.000001 * 2,
      -1.0 * 2, 1.0 * 2,  1.0 * 2,       -1.0 * 2,     1.0 * 2,  -1.0 * 2};

  std::pair<vector<float>, vector<unsigned int>> res = m.Start(file_name);

  m.ScaleXyz(res.first, 2.0);

  for (size_t i = 0; i < res.first.size(); ++i) {
    ASSERT_LE(fabs(res.first[i] - vert_res[i]), 1e-7);
  }
}

TEST(scale_xyz, test2) {
  Model m;
  vector<float> vert_res{1, -1, -1, 1,  -1, 1,  -1,        -1,
                         1, -1, -1, -1, 1,  1,  -0.999999, 0.999999,
                         1, 1,  -1, 1,  1,  -1, 1,         -1};

  std::pair<vector<float>, vector<unsigned int>> res = m.Start(file_name);

  m.ScaleXyz(res.first, -1);

  for (size_t i = 0; i < res.first.size(); ++i) {
    ASSERT_LE(fabs(res.first[i] - vert_res[i]), 1e-6);
  }
}
