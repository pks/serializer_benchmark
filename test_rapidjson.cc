#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

/*
 * https://github.com/miloyip/rapidjson
 *
 */
#include "rapidjson/include/rapidjson/rapidjson.h"
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"

using namespace std;


int
main(int argc, char** argv)
{
  ifstream ifs(argv[1]);
  string json_str((istreambuf_iterator<char>(ifs)),
                   (istreambuf_iterator<char>()));

  rapidjson::Document d;
  d.Parse(json_str.c_str());
  string s(d["edges"][d["edges"].Size()-1]["rule"].GetString());
  cerr << s.substr(1, 4) << endl;

  return 0;
}

