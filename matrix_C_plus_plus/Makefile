all:  clean matrix.a test

matrix.a: clean matrix_oop.o
	ar rcs matrix.a matrix_oop.o
	ranlib $@
	cp $@ lib$@
	ranlib lib$@

matrix_oop.o: matrix_oop.cpp
	g++ -c -o matrix_oop.o matrix_oop.cpp

test:  clean matrix.a
	g++ --coverage matrix_oop.cpp matrix_test.cpp -o matrix_test.out -lgtest -I -L -lcheck `pkg-config --cflags --libs check`
	./matrix_test.out

gcov_report: test
	lcov -t "test" -o test.info -c -d ./
	genhtml -o report test.info
	xdg-open report/index.html

clean:
	rm -rf ./*.o ./*.a ./a.out ./*.gcno ./*.gcda ./report *.info ./*.info report ./Test ./*out