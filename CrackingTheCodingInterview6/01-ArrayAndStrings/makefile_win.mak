TEST_DIR=test/
PROJECT_DIR=project/
headers=$(PROJECT_DIR)1.1.IsUnique.h $(PROJECT_DIR)P1.2.CheckPermutation.h $(PROJECT_DIR)P1.3.Urlify.h
sources=$(PROJECT_DIR)1.1.IsUnique.cc $(PROJECT_DIR)P1.2.CheckPermutation.cc $(PROJECT_DIR)P1.3.Urlify.cc
objects=1.1.IsUnique.obj P1.2.CheckPermutation.obj P1.3.Urlify.obj
mainexe=main
mainobj=main.obj
mainsrc=main.cc

.PHONY: clean 

run : main	
	$(mainexe)

main : $(mainobj) $(objects)
	Link /std:c++17 $(mainobj) $(objects) -o $(mainexe)

$(mainobj) : main.cc  $(sources) $(headers)
	Cl /std:c++17 -c $(mainsrc) $(sources)
clean :
	-del *.exe
	-del *.obj

