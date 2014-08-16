#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

/*
 * https://github.com/chadaustin/sajson
 *
 */
#include "sajson/include/sajson.h"

using namespace std;


int
main(int argc, char** argv)
{
  ifstream ifs(argv[1]);
  string json_str((istreambuf_iterator<char>(ifs)),
                   (istreambuf_iterator<char>()));

  const sajson::document& document = sajson::parse(sajson::literal(json_str.c_str()));
  size_t index_a = document.get_root().find_object_key(sajson::literal("edges"));
  const sajson::value& edges = document.get_root().get_object_value(index_a);
  const sajson::value& last_edge = edges.get_array_element(edges.get_length()-1);
  size_t index_r  = last_edge.find_object_key(sajson::literal("rule"));
  const sajson::value& r = last_edge.get_object_value(index_r);
  cerr << r.as_string().substr(1, 4) << endl;

  return 0;
}

