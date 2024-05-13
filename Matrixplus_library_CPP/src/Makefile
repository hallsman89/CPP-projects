COMPILER = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra
TARGETS = s21_matrix_oop.cc
GCOV = -fprofile-arcs -ftest-coverage -fPIC -pthread
GTEST = -lgtest -lgtest_main

all: gcov_report

gcov_report: test
	lcov -t "matrix" -o matrix.info -c -d .
	genhtml -o report matrix.info
	open report/index.html

test: clean
	${COMPILER} ${FALGS} tests_matrix_oop.cc -c
	${COMPILER} ${FLAGS} ${GCOV} ${TARGETS} tests_matrix_oop.o -o test ${GTEST}
	./test

style:
	cp ./../materials/linters/.clang-format ./
	clang-format -i *.cc
	rm .clang-format

s21_matrix_oop.a : s21_matrix_oop.o
	ar rc libs21_matrix_oop.a *.o
	ranlib libs21_matrix_oop.a
	cp libs21_matrix_oop.a s21_matrix_oop.a

s21_matrix_oop.o:
	${COMPILER} ${FLAGS} -c  ${TARGETS}

clean:
	rm -rf *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno *.a tests_s21_matrix *.css *.html vgcore* report *.info *.gz *.log test