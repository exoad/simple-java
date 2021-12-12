#include "include/Checker.hxx"
#include <string>

using namespace Checker;
using namespace std;

bool validClassName(string className) {
  if (className.length() == 0) {
    return false;
  }
  if (className.length() > 30) {
    return false;
  }
  if (className.at(0) >= '0' && className.at(0) <= '9') {
    return false;
  }
  if (className.at(0) == '_') {
    return false;
  }
  for (int i = 0; i < className.length(); i++) {
    if (className.at(i) >= '0' && className.at(i) <= '9') {
      return false;
    }
    if (className.at(i) == '_') {
      return false;
    }
    if (className.at(i) >= 'a' && className.at(i) <= 'z') {
      continue;
    }
    if (className.at(i) >= 'A' && className.at(i) <= 'Z') {
      continue;
    }
    if (className.at(i) == '$') {
      continue;
    }
    if (className.at(i) == '.') {
      continue;
    }
    return false;
  }
  return true;
}

