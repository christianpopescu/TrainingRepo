#include <iostream>
#include <vector>

#define N 8

// Class that keeps the "covered" areas by Queens
class OccupiedCells{
public:
  OccupiedCells() : columns(N,false)  {
  }
private :
  std::vector<bool> columns;

};


int main(){
  
  std::cout << "End" << std::endl;
  
}
