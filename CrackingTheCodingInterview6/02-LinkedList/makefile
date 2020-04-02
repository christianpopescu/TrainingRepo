GTEST_CFLAGS = `pkg-config --cflags gtest_main`
GTEST_LIBS = `pkg-config --libs gtest_main`
TEST_DIR=test/
PROJECT_DIR=project/
PROBLEM=p02.01.RemoveDuplicates
PROBLEM_CC:=$(PROBLEM).cc
PROBLEM_O:=$(PROBLEM).O
PROBLEM_EXE:=$(PROBLEM).exe

.PHONY: clean 

run : $(PROBLEM)	
	./$(PROBLEM_EXE)

$(PROBLEM) : $(PROBLEM_O) 
	g++ -std=c++17 $(PROBLEM_O) -o $(PROBLEM_EXE)

$(PROBLEM_O) : $(PROBLEM_CC)
	g++ -std=c++17 -c $(PROBLEM_CC)


clean :
	-rm *.exe
	-rm *.o

