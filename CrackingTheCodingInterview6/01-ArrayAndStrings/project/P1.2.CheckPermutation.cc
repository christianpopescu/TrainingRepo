#include "P1.2.CheckPermutation.h"
#include <algorithm>

void CheckPermutation::SetInput(std::string in1,std::string in2){
  input1 = in1;
  input2 = in2;
}

bool CheckPermutation::CheckPermutationSort(){
  if (input1.size() != input2.size()) return false;
  sort(input1.begin(), input1.end());
  sort(input2.begin(), input2.end());
  if(input1 == input2)
    return true;
  else
    return false;
}

bool CheckPermutation::CheckPermutationCount(){
  if (input1.size() != input2.size()) return false;
  for (int i=0; i < input1.size(); ++i) {
    cnt1[(int)(input1[i])]++;
    cnt2[(int)(input2[i])]++;
  }
  for (int i=0; i < max; ++i) if (cnt1[i] != cnt2[i]) return false;
return true;
}
