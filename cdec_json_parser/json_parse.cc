#include "json_parse.h"

#include <string>
#include <iostream>

using namespace std;


bool JSONParser::HandleJSONEvent(int type, const JSON_value* value) {
  switch(type) {
    case JSON_T_OBJECT_BEGIN:
    case JSON_T_OBJECT_END:
    case JSON_T_ARRAY_BEGIN:
    case JSON_T_ARRAY_END:
    case JSON_T_NULL:
    case JSON_T_TRUE:
    case JSON_T_FALSE:
    case JSON_T_KEY:
    case JSON_T_INTEGER:
    case JSON_T_FLOAT:
      break;
    case JSON_T_STRING:
      string s = value->vu.str.value;
      string t = s.substr(1, 4);
      if (t == "Goal")
        cerr << t << endl;
      break;
  }
  return true;
}

