GTEST_CFLAGS = `pkg-config --cflags gtest_main`
GTEST_LIBS = `pkg-config --libs gtest_main`
TEST_DIR=test/
PROJECT_DIR=project/

.PHONY: clean tests all

run : main	
	./main

main : main.o 1.1.IsUnique.o
	g++ -std=c++17 main.o 1.1.IsUnique.o -o main

main.o : main.cc $(PROJECT_DIR)1.1.IsUnique.h $(PROJECT_DIR)1.1.IsUnique.cc
	g++ -std=c++17 -c main.cc $(PROJECT_DIR)1.1.IsUnique.cc


clean :
	rm *.exe
	rm *.o

