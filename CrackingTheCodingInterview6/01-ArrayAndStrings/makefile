GTEST_CFLAGS = `pkg-config --cflags gtest_main`
GTEST_LIBS = `pkg-config --libs gtest_main`
TEST_DIR=test/
PROJECT_DIR=project/

.PHONY: clean tests all

run : main	
	./main

main : main.o 1.1.IsUnique.o
	g++ -std=c++17 main.o 1.1.IsUnique.o P1.2.CheckPermutation.o -o main

main.o : main.cc $(PROJECT_DIR)1.1.IsUnique.h $(PROJECT_DIR)1.1.IsUnique.cc $(PROJECT_DIR)P1.2.CheckPermutation.h $(PROJECT_DIR)P1.2.CheckPermutation.cc
	g++ -std=c++17 -c main.cc $(PROJECT_DIR)1.1.IsUnique.cc $(PROJECT_DIR)P1.2.CheckPermutation.cc
clean :
	rm -f *.exe
	rm -f *.o
	rm -f *~
	rm -f $(PROJECT_DIR)/*~

