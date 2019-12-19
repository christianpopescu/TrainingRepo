#include <iostream>
#include <string>
#include <cstring>
#include "project/1.1.IsUnique.h"
#include "project/P1.2.CheckPermutation.h"
#include "project/P1.3.Urlify.h"

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

void p1_3(){
  char * in = new char[2000];
  std::strcpy(in, "ab cd  efg h");
   std::cout << in << std::endl;
  Urlify u;
  u.SetInput(in);
  u.UrlifyString();
  std::cout << in << std::endl;
  
}
  

int main () {
  //p1_1();
  //  p1_2();
  p1_3();
  return 0;
}
