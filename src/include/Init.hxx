#include<string.h>
#include "include/Macros.hxx"
#include "include/GlobalHolders.hxx"

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
  file_dir_holder = OUTPUT_DIR + filename + ".java";
  class_name_holder = filename;
  if (type == 1) {
    file << "public class " << class_name_holder << " {\n}";
    file_contents_holder += "public class " + class_name_holder + " {\n}";
  }
  else if (type == 2) {
    file << "public enum " << class_name_holder << " {\n}";
    file_contents_holder += "public enum " + class_name_holder + " {\n}";
  }
  else if (type == 3) {
    file << "public interface " << class_name_holder << " {\n}";
    file_contents_holder += "public interface " + class_name_holder + " {\n}";
  }
  else if (type == 4) {
    file << "public abstract class " << class_name_holder << " {\n}";
    file_contents_holder += "public abstract class " + class_name_holder + " {\n}";
  }
}