#include <iostream>
#include <fstream>
#include <string>

/*
 * https://github.com/hjiang/jsonxx
 *
 */
#include "jsonxx/jsonxx.h"

using namespace std;


int
main(int argc, char** argv)
{
  ifstream ifs(argv[1]);
  string json_str((istreambuf_iterator<char>(ifs)),
                   (istreambuf_iterator<char>()));

  jsonxx::Object o;
  o.parse(json_str);
  jsonxx::Array edges = o.get<jsonxx::Array>("edges");
  jsonxx::Array::container::const_iterator it = edges.values().begin(), end = edges.values().end();
  while (it != end) {
    jsonxx::Object e = (*it)->get<jsonxx::Object>();
    string s = e.get<string>("rule").substr(1, 4);
    if (s == "Goal")
      cerr << s << endl;
    ++it;
  }

  return 0;
}

