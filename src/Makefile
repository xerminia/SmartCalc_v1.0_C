CC = gcc
CFLAGS = -Wall -Werror -Wextra
FLAG = --coverage
OS := $(shell uname -s)

all: clean install tests

build:
	mkdir build
	cd ./build/ && qmake6 ../ && make && mv calc2test.app calc.app

install: build
	mkdir $(HOME)/Desktop/SmartCalc/
	cp -rf build/calc.app $(HOME)/Desktop/SmartCalc/
	make clean

uninstall:
	rm -rf $(HOME)/Desktop/SmartCalc/

dvi:
	open dvi.html

dist:
	rm -rf SmartCalc
	mkdir SmartCalc
	mkdir SmartCalc/src
	cp Makefile *.c *.h *.cpp *.ui *.pro *.pro.user *.html SmartCalc/src/
	tar -cvzf SmartCalc.tar.gz SmartCalc
	mv SmartCalc.tar.gz $(HOME)/Desktop/
	rm -rf SmartCalc/

calc.o:
	$(CC) $(CFLAGS) -c calc.c -o calc.o
	
test.o:
	$(CC) $(CFLAGS) -c test.c -o test.o

tests: calc.o test.o
ifeq ($(OS), Darwin)
	$(CC) test.o calc.o -o tests -lcheck
	./tests
else
	$(CC) test.o calc.o -o tests -lcheck -lsubunit -lrt -lpthread -lm
	./tests
endif

gcov:
ifeq ($(OS), Darwin)
	$(CC) $(FLAG) calc.c test.c -o test -lcheck
else
	$(CC) $(FLAG) s21_matrix.c test.c -o test -lcheck -lsubunit -lrt -lpthread -lm
endif

gcov_report: clean gcov
	./test
	lcov -t “test” -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

clean:
	rm -rf *.o  *.gc* report *.a tests test test.info build

check: tests
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	CK_FORK=no leaks --atExit -- ./tests
