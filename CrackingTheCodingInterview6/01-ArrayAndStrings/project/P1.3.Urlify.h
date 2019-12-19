#ifndef URLIFY_H
#define URLIFY_H

#include <string>
#include <vector>

  class Urlify {
  public:
    void SetInput(char* in);   // pass 0 terminated string
    bool Urlify();

   
  protected :
    char buf*; 
    

  };

#endif // URLIFY_H
