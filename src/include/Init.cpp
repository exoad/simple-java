#include "include/Init.h"
#include "include/Macros.hxx"
#include "temp/GlobalHolders.h"

#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>

using namespace std;

/**
 * @brief This function starts the heading of the class
 * @param filename The Class Name
 * @param type The type of file to be created, interface, class, etc.
 */
void init_file(string filename, int type) {
  cout << filename << endl;
  ofstream file;
  file.open(OUTPUT_DIR + filename + ".java");
  file_dir = OUTPUT_DIR + filename + ".java";
  class_name = filename;
  if (type == 1) {
    file << "public class " << class_name << " {\n}";
    file_contents += "public class " + class_name + " {\n}";
  }
  else if (type == 2) {
    file << "public enum " << class_name << " {\n}";
    file_contents += "public enum " + class_name + " {\n}";
  }
  else if (type == 3) {
    file << "public interface " << class_name << " {\n}";
    file_contents += "public interface " + class_name + " {\n}";
  }
  else if (type == 4) {
    file << "public abstract class " << class_name << " {\n}";
    file_contents += "public abstract class " + class_name + " {\n}";
  }
}