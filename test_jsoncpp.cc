#include <iostream>
#include <fstream>
#include <string>

/*
 * https://github.com/open-source-parsers/jsoncpp
 *
 */
#include "jsoncpp/include/json/json.h"

using namespace std;


int
main(int argc, char** argv)
{
  ifstream ifs(argv[1]);
  string json_str((istreambuf_iterator<char>(ifs)),
                   (istreambuf_iterator<char>()));

  Json::Value v;
  Json::Reader reader;
  reader.parse(json_str, v);
  Json::Value last_edge = v["edges"][v["edges"].size()-1];
  cerr << last_edge["rule"].asString().substr(1, 4) << endl;

  return 0;
}

