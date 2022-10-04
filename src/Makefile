CC = g++ -std=c++17 -Wall -Werror -Wextra
SOURCE = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)

OS=$(shell uname)
ifeq ($(OS), Linux)
QMAKE = /home/fbillye/Qt/6.2.4/gcc_64/bin/qmake
FLAGS += -lm -lpthread -lrt -lsubunit
OPEN = open ./report
NAME = untitled
endif

all: install tests

install:
	mkdir build
	qmake ./3dv_plus.pro -o ./build/Makefile_qt
	cd build && make -f Makefile_qt

uninstall: clean

tests:
	$(CC) model.cpp tests.cpp -o testing.out -lgtest -lgtest_main
	./testing.out

dvi:
	open dvi.pdf

dist: clean
	mkdir Archive_3DViewer_v2.0/
	mkdir Archive_3DViewer_v2.0/src
	cp Makefile *.h *.pro *.cpp *.ui *.pro Archive_3DViewer_v2.0/src/
	tar cvzf Archive_3DViewer_v2.0.tgz Archive_3DViewer_v2.0/
	rm -rf Archive_3DViewer_v2.0/

gcov_report:
	$(CC) tests.cpp model.cpp -fprofile-arcs -ftest-coverage -lgtest -lgtest_main
	./a.out
	lcov -t "3DViewer_v2.0" -o 3DViewer_v2.info -c -d .
	genhtml -o report 3DViewer_v2.info
	open ./report/index.html

check:
	cp -f ../materials/linters/.clang-format .clang-format
	clang-format -n $(SOURCE)
	clang-format -n $(HEADERS)
	rm -rf .clang-format
	CK_FORK=no leaks --atExit -- ./testing.out

clean:
	rm -rf *.out *.o *.a
	rm -rf *.gcda *.gcno *.info
	rm -rf report s21_test
	rm -rf *.tgz s21_test
	rm -rf ./build*
	rm -rf *.user

rebuild: clean all
