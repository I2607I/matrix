TEST_FLAGS=-I -L -lcheck `pkg-config --cflags --libs check`
CPP_FLAGS=-Wall -Wextra -Werror
DEBUG_FLAG=-g
GCOV_FLAG=--coverage
OBJECTS=matrix.o test.o
FUNCS=matrix.c
TEST_C=test.c matrix.c 
HEADER=matrix.h
EXECUTABLE=test.out
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


all: clean matrix.a test

clean:
	$(DELETE) $(TO_DELETE) $(EXECUTABLE) $(LINTCFG)
	
test:
	$(CC) $(DEBUG_FLAG) $(GCOV_FLAG) $(TEST_C) -o $(EXECUTABLE) $(TEST_FLAGS)
	./test.out

gcov_report: test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	xdg-open report/index.html


matrix.a:
	$(CC) -c $(FUNCS)
	ar rc matrix.a matrix.o
	ar rc libs_matrix.a matrix.o
	ranlib matrix.a
	ranlib libs_matrix.a

valgrind_check: all
	CK_FORK=no valgrind --leak-check=full --tool=memcheck -s ./$(EXECUTABLE)

leaks_check:
	CK_FORK=no leaks --atExit -- ./$(EXECUTABLE)

