#include <iostream>
#include <fstream>
#include <string>

/*
 * http://fossil.wanderinghorse.net/repos/nosjob/index.cgi/index
 *
 */
#include "nosjob-e1d67401fcda6e05/include/wh/nosjob/nosjob.hpp"

using namespace std;


int
main(int argc, char** argv)
{
  ifstream ifs(argv[1]);
  string json_str((istreambuf_iterator<char>(ifs)),
                   (istreambuf_iterator<char>()));

  nosjob::Atom root = nosjob::JsonParser().parse(json_str);
  nosjob::Object o = nosjob::Object::cast(root);
  nosjob::Atom edges = o.get(nosjob::Utf8String("edges"));
  nosjob::Array a = nosjob::Array::cast(edges);
  nosjob::Object last_edge = nosjob::Object::cast(a.get(a.size()-1));
  nosjob::Utf8String s = nosjob::Utf8String::cast(last_edge.get(nosjob::Utf8String("rule")));
  string t((char*)s.c_str());
  cerr << t.substr(1, 4) << endl;

  return 0;
}

