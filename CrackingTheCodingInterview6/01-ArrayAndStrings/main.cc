#include <iostream>
#include <string>
#include "project/1.1.IsUnique.h"
#include "project/P1.2.CheckPermutation.h"

std::string sep{" : "};

void p1_1(){
    
  IsUnique iu;
  iu.SetInput("");
  std::cout << "" << sep << iu.HasUniqueChar() << std::endl;
  std::cout << "" << sep << iu.HasUniqueCharWithoutStructure() << std::endl;
  iu.SetInput("abcdef");
  std::cout << "abcdef" << sep << iu.HasUniqueChar() << std::endl;
  std::cout << "abcdef" << sep << iu.HasUniqueCharWithoutStructure() << std::endl;
  iu.SetInput("abcdefa");
  std::cout << "abcdefa" << sep << iu.HasUniqueChar() << std::endl;
  std::cout << "abcdefa" << sep << iu.HasUniqueCharWithoutStructure() << std::endl;
}

void p1_2(){
  CheckPermutation cp;
  cp.SetInput("","");
  std::cout << "" << sep << "" << sep << cp.CheckPermutationSort() << sep <<
    cp.CheckPermutationCount() << std::endl;
  cp.SetInput("123456789","987654321");
  std::cout << "123456789" << sep << "987654321" << sep << cp.CheckPermutationSort() << sep <<
    cp.CheckPermutationCount() << std::endl;
  cp.SetInput("123456799","987654321");
  std::cout << "123456799" << sep << "987654321" << sep << cp.CheckPermutationSort() << sep <<
    cp.CheckPermutationCount() << std::endl;

  
}
  

int main () {
  //p1_1();
  p1_2();
  return 0;
}
