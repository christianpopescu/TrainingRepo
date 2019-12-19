GTEST_CFLAGS = `pkg-config --cflags gtest_main`
GTEST_LIBS = `pkg-config --libs gtest_main`
TEST_DIR=test/
PROJECT_DIR=project/
headers:=$(PROJECT_DIR)1.1.IsUnique.h $(PROJECT_DIR)P1.2.CheckPermutation.h
sources:=$(PROJECT_DIR)1.1.IsUnique.cc $(PROJECT_DIR)P1.2.CheckPermutation.cc
objects:=1.1.IsUnique.o P1.2.CheckPermutation.o

.PHONY: clean tests all

run : main	
	./main

main : main.o $(objects)
	g++ -std=c++17 main.o $(objects) -o main

main.o : main.cc  $(sources) $(headers)
	g++ -std=c++17 -c main.cc $(sources)
clean :
	rm -f *.exe
	rm -f *.o
	rm -f *~
	rm -f $(PROJECT_DIR)/*~

