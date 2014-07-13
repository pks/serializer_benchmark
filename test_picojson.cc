#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/*
 * https://github.com/kazuho/picojson
 *
 */
#include "picojson/picojson.h"

using namespace std;


int
main(int argc, char** argv)
{
  ifstream ifs(argv[1]);
  string json_str((istreambuf_iterator<char>(ifs)),
                  (istreambuf_iterator<char>()));

  picojson::value v;
  istringstream iss(json_str);
  picojson::parse(v, iss);
  picojson::value::object& obj = v.get<picojson::object>();
  picojson::value::object& last_edge = obj["edges"].get<picojson::array>().back().get<picojson::object>();
  string s(last_edge["rule"].get<string>());
  cerr << s.substr(1, 4) << endl;

  return 0;
}

