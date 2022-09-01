TEST_FLAGS=-I -L -lcheck `pkg-config --cflags --libs check`
CPP_FLAGS=-Wall -Wextra -Werror
DEBUG_FLAG=-g
GCOV_FLAG=--coverage
OBJECTS=s21_matrix.o s21_test.o
FUNCS=s21_matrix.c
TEST_C=s21_test.c s21_matrix.c 
HEADER=s21_matrix.h
EXECUTABLE=s21_test.out
CC=gcc
LINT_WAY=../materials/linters/cpplint.py
LINTCFG_WAY=../materials/linters/CPPLINT.cfg
LINTCFG=CPPLINT.cfg
COPY=cp
PY=python3
EXTENSION=--extensions=c
CHECK_FILES=*.c *.h
CPPCH=cppcheck
DELETE=rm -rf
TO_DELETE=*.o *.a *.gcda *.gcno *.info
OS := $(shell uname -s)

ifeq ($(OS), Darwin)
	CC += -D OS_MAC
	TEST_FLAGS =-lcheck
endif
ifeq ($(OS), linux)
	CC += -D OS_LINUX
	TEST_FLAGS =-lpthread -lcheck -pthread -lrt -lm -lsubunit
endif


all: clean check s21_matrix.a test

check:
	$(CPPCH) $(CHECK_FILES)
	$(COPY) $(LINTCFG_WAY) $(LINTCFG)
	$(PY) $(LINT_WAY) $(EXTENSION) $(CHECK_FILES)

clean:
	$(DELETE) $(TO_DELETE) $(EXECUTABLE) $(LINTCFG)
	
test:
	$(CC) $(DEBUG_FLAG) $(GCOV_FLAG) $(TEST_C) -o $(EXECUTABLE) $(TEST_FLAGS)
	./s21_test.out

gcov_report: test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html


s21_matrix.a:
	$(CC) -c $(FUNCS)
	ar rc s21_matrix.a s21_matrix.o
	ar rc libs21_matrix.a s21_matrix.o
	ranlib s21_matrix.a
	ranlib libs21_matrix.a

valgrind_check:
	CK_FORK=no valgrind --leak-check=full --tool=memcheck -s ./$(EXECUTABLE)

leaks_check:
	CK_FORK=no leaks --atExit -- ./$(EXECUTABLE)

