#ifndef CHECKPERMUTATION_H
#define CHECKPERMUTATION_H

#include <string>
#include <vector>

  class CheckPermutation {
  public:
 static const int max = 256;
    void SetInput(std::string in1,std::string in2);
    bool CheckPermutationSort();
    bool CheckPermutationCount();

   
  protected :
    std::vector<int> cnt1 = std::vector<int>(max,0);
    std::vector<int> cnt2{std::vector<int>(256,0)};
    std::string input1;
    std::string input2;
    
    

  };

#endif // CHECKPERMUTATION_H
