#include <iostream>
#include <fstream>
#include <string>

/*
 * http://grigory.info/MicroJSON.About.html
 *
 */
#include "MicroJSON-0.3.2/Node.h"

using namespace std;


int
main(int argc, char** argv)
{
  ifstream ifs(argv[1]);
  string json_str((istreambuf_iterator<char>(ifs)),
                   (istreambuf_iterator<char>()));

  MicroJSON::Node Root;
  Root.Parse(json_str);
  MicroJSON::Node* edges = Root.GetSubNode("edges");
  cerr << edges->GetChildren().back()->GetSubNode("rule") << endl;

  return 0;
}

