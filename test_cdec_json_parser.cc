#include <iostream>
#include <fstream>
#include <string>

/*
 * https://github.com/redpony/cdec/tree/master/decoder
 *
 */
#include "cdec_json_parser/json_parse.h"

using namespace std;


int
main(int argc, char** argv)
{
  ifstream ifs(argv[1]);

  istream& s = ifs;
  JSONParser p;
  p.Parse(&s);

  return 0;
}

