#include <iostream>
#include <string>
#include "project/1.1.IsUnique.h"

int main () {
  std::string sep{" : "};
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
  return 0;
}
