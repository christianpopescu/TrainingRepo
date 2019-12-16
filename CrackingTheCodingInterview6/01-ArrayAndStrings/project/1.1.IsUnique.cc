#include "1.1.IsUnique.h"

//IsUnique::max = 256;

IsUnique::IsUnique(){
  for (int i = 0; i < max; ++i) {
    set[i] = false;
  }
}

void IsUnique::SetInput(std::string in){
  input = in;
}

bool IsUnique::HasUniqueChar(){
  if (input.size()>max) return false;
  for (auto c : input){
    int ind = (int)c;
    if (set[ind] == true)
      return false;
    else
      set[ind] = true;
  }
  return true;
}

bool IsUnique::HasUniqueCharWithoutStructure(){
  int n = input.size();
  if (n > max) return false;

  for (int i=0; i < n-1; ++i)
    for (int j=i+1; j < n; ++j) {
      if (input[(int)i] == input[(int)j])
	return false;
    }

  return true;
}
