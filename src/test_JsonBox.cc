#include <iostream>
#include <string>

/*
 * https://github.com/anhero/JsonBox
 *
 */
#include "JsonBox/include/JsonBox.h"

using namespace std;


int
main(int argc, char** argv)
{
  JsonBox::Value v;
  v.loadFromFile(argv[1]);
  JsonBox::Value w = v["edges"].getArray().back();
  string s = w["rule"].getString();
  cerr << s.substr(1,4) << endl;

  return 0;
}

