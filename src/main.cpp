#include "include/BigInclude.hxx"
#include "include/Init.hxx"

using namespace std;
using namespace filedec;

string filename123 = "";

string translateToJava(string line) {
  if (line.find("int") != string::npos && line.find("main()") != string::npos) {
    return line.substr(0, line.find(" "));
  }
  return "";
}

/**
 * @param line the line to be written to the file
 * @brief This function does not check for any errors and should be used only when there are checks ahead of this function call
 */
void writeToFile(string line) {
  ofstream file;
  file.open(file_dir_holder, ios::app);
  file << line << "\n";
  file_contents_holder += line + "\n";
}

bool check_if_proper(string s) {
  FileDeclarator fd(s);
  return fd.camelCase();
}

bool code_execute(string s) {
  return true;
}

signed main() {
  cout << "Enter the file path: ";
  string no_comp;
  cin >> no_comp;
  freopen(no_comp.c_str(), "r", stdin);
  string content = "";
  while (getline(cin, content)) {
    // get the class name after "class: "
    if (content.find("class: ") != string::npos) {
      string class_name = content.substr(content.find("class: ") + 7);
      init_file(class_name, 1);
    }
    else if (content.find("enum: ") != string::npos) {
      string class_name = content.substr(content.find("enum: ") + 6);
      init_file(class_name, 2);
    }
    else if (content.find("inter: ") != string::npos) {
      string class_name = content.substr(content.find("inter: ") + 7);
      init_file(class_name, 3);
    }
    else if (content.find("abst_class") != string::npos) {
      string class_name = content.substr(content.find("abst_class") + 11);
      init_file(class_name, 4);
    }
    else {

    }
    cin >> content;
    writeToFile(translateToJava(content));
  }
  cout << "Created Class file: " << class_name_holder << endl;
  cout << "Success" << endl;
}