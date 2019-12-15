#ifndef ISUNIQUE_H
#define ISUNIQUE_H

#include <string>

  class IsUnique {
  public:
    IsUnique()=default;
    void SetInput(std::string in);

  protected :
    bool set[256];
    std::string input;
    

  };

#endif //  ISUNIQUE_H
