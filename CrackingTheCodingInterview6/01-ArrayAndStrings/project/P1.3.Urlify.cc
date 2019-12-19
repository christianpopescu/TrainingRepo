#include "P1.3.Urlify.h"
#include <algorithm>
#include <iostream>

void Urlify::SetInput(char* in){
  buf = in;
}

void Urlify::UrlifyString(){
  int countSpace = 0;
  int size=0;
  char* iter = buf;
  while (*iter != 0x00) {
    if (*iter == ' ') countSpace++;
    size++;
    iter++;
  }
  if ( countSpace == 0 || size == 0) return;
  int newSize = size + countSpace*2;
  buf[newSize] = 0x00;
  int source = size - 1;
  int dest = newSize - 1;
  while (source >= 0) {
    if (buf[source] != ' ') {
      buf[dest--] = buf[source--];      
    } else {
      buf[dest] = '0';
      buf[dest-1] = '2';
      buf[dest-2] = '%';
      dest -=3;
      source--;
    }
    }
}

