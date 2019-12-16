#ifndef ISUNIQUE_H
#define ISUNIQUE_H

#include <string>

  class IsUnique {
  public:
 static const int max = 256;
    IsUnique();
    void SetInput(std::string in);
    bool HasUniqueChar();

   
  protected :
    bool set[max];
    std::string input;
    

  };

#endif //  ISUNIQUE_H
