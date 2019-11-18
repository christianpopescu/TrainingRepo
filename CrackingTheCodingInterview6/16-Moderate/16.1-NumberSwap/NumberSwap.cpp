#include <iostream>
#include "swap.h"

int main(){
  int a, b;
  std::cin >> a >> b ;
  swap::SwapByMinus(a,b);
  std::cout << a << " " << b << std::endl;
  swap::SwapByXor(a,b);
  std::cout << a << " " << b << std::endl;

  
}
