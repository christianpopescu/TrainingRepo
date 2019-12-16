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
