#include <iostream>
#include <fstream>
#include <string>

/*
 * http://sourceforge.net/projects/libjson/
 *
 */
#include "libjson-7.6.1/libjson.h"

using namespace std;


void
walk(const JSONNode & n)
{
  JSONNode::const_iterator it = n.begin();
  while (it != n.end()){
    if (it->type() == JSON_ARRAY || it->type() == JSON_NODE){
      walk(*it);
    }
    string s = it->as_string();
    if (s.size() >= 5) {
      string t = s.substr(1, 4);
      if (t == "Goal")
        cerr << t << endl;
    }
    ++it;
  }
}

int
main(int argc, char** argv)
{
  ifstream ifs(argv[1]);
  string json_str((istreambuf_iterator<char>(ifs)),
                   (istreambuf_iterator<char>()));

  JSONNode n = libjson::parse(json_str);
  walk(n);

  return 0;
}

