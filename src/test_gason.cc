#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

/*
 * https://github.com/vivkin/gason
 *
 */
#include "gason/gason.h"

using namespace std;


void
print(const char *s)
{
  string u(s);
  u = u.substr(1, 4);
  if (u == "Goal") {
    cerr << u << endl;
  }
}

void
walk(JsonValue o)
{
	switch (o.getTag()) {
		case JSON_TAG_NUMBER:
			break;
		case JSON_TAG_BOOL:
			break;
		case JSON_TAG_STRING:
			print(o.toString());
			break;
		case JSON_TAG_ARRAY:
			if (!o.toNode())
				break;
			for (auto i : o)
				walk(i->value);
			break;
		case JSON_TAG_OBJECT:
			if (!o.toNode())
				break;
			for (auto i : o) {
				print(i->key);
				walk(i->value);
			}
			break;
		case JSON_TAG_NULL:
			break;
	}
}

int
main(int argc, char** argv)
{
  ifstream ifs(argv[1]);
  string json_str((istreambuf_iterator<char>(ifs)),
                   (istreambuf_iterator<char>()));

  char* s = strdup(json_str.c_str());
  char *p;
  JsonValue v;
  JsonAllocator a;
  JsonParseStatus status = jsonParse(s, &p, &v, a);
  walk(v);

  return 0;
}

