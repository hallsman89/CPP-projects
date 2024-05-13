CXX = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra
GCOV = -fprofile-arcs -ftest-coverage -fPIC -pthread
FILES = *.cc model/*.cc
GTEST = -lgtest -lgtest_main 
OS = $(shell uname)

ifeq (${OS}, Linux)
	TEST_FLAGS = -lcheck -lpthread -lm -D_GNU_SOURCE -lrt -lsubunit
else
	TEST_FLAGS = -lcheck
endif

all: clean gcov_report

gcov_report: test
	mkdir report
	gcovr --html-details -o report/coverage.html
	open ./report/coverage.html

ifeq (${OS}, Linux)
	cd report && firefox index.html
else
	cd report && open index.html
endif

test: clean
	${CXX} ${TARGETS} ${FLAGS} ${GCOV} ${GTEST} ${FILES} -o test test_dir/test.cc 
	./test


calc.a : calc.o
	ar rc libs21_calc.a *.o
	ranlib libs21_calc.a
	cp libs21_calc.a calc.a

calc.o: ${FILES}
	${GXX} ${CFLAGS} -c ${FILES}

clean:
	rm -rf *.o gcov_report *.a *.gcda *.gcno report calc.info

rebuild: clean calc.a

install:clean
	mkdir build
	cd build && cmake ../view/CMakeLists.txt && make
	cp -rf build/view.app $(HOME)/Desktop/calculator.app

uninstall: clean
	rm -rf build
	rm -rf $(HOME)/Desktop/Calculator.app

dvi:
	doxygen Doxyfile
	open html/index.html

dist:
	mkdir SmartCalc_v2.0/
	mkdir SmartCalc_v2.0/src
	cp Makefile *.cc *.h model/*.cc model/headers/*.h view/*.cpp view/*.h SmartCalc_v2.0/src/
	tar cvzf SmartCalc_v2.0.tgz SmartCalc_v2.0/
	rm -rf SmartCalc_v2.0/
