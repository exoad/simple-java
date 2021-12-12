#pragma GCC diagnostic ignored "-Wsign-compare"

#include<string>
#include<vector>

using namespace std;

namespace filedec {

  class FileDeclarator
  {
  public:
    string content;
    bool isCamelCase = false;

    FileDeclarator(string content) {
      this -> content = content;
    }

  public:
    bool camelCase() {

      for (int i = 0; i < content.length(); i++) {
        if (isupper(content[i])) {
          isCamelCase = true;
          return true;
        }
      }
      return false;
    }
  public:

    bool isOk() {
      return isCamelCase;
    }
  };

}