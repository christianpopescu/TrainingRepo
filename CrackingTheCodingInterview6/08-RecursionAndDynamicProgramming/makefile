GTEST_CFLAGS = `pkg-config --cflags gtest_main`
GTEST_LIBS = `pkg-config --libs gtest_main`
TEST_DIR=test/
PROJECT_DIR=project/

.PHONY: clean tests all

p8.01 : P8.01.TripleStep	
	./P8.01.TripleStep

P8.01.TripleStep : P8.01.TripleStep.o 
	g++ -std=c++17 P8.01.TripleStep.o -o P8.01.TripleStep

P8.01.TripleStep.o : P8.01.TripleStep.cc 
	g++ -std=c++17 -c P8.01.TripleStep.cc


clean :
	rm *.exe
	rm *.o

