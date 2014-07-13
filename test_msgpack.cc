#include <iostream>
#include <fstream>
#include <string>

/*
 * http://msgpack.org/
 *
 */
#include <msgpack.hpp>
#include <msgpack/fbuffer.h>
#include <msgpack/fbuffer.hpp>

using namespace std;


struct Node {
  int id;
  string cat;
  vector<int> span;

  MSGPACK_DEFINE(id, cat, span);
};

struct Vector {
  double CountEF;
  double EgivenFCoherent;
  double Glue;
  double IsSingletonF;
  double IsSingletonFE;
  double LanguageModel;
  double LanguageModel_OOV;
  double MaxLexFgivenE;
  double MaxLexEgivenF;
  double PassThrough;
  double PassThrough_1;
  double PassThrough_2;
  double PassThrough_3;
  double PassThrough_4;
  double PassThrough_5;
  double PassThrough_6;
  double SampleCountF;
  double WordPenalty;

	MSGPACK_DEFINE(CountEF, EgivenFCoherent, Glue, IsSingletonF, IsSingletonFE, LanguageModel, LanguageModel_OOV, MaxLexEgivenF, MaxLexFgivenE, PassThrough, PassThrough_1, PassThrough_2, PassThrough_3, PassThrough_4, PassThrough_5, PassThrough_6, SampleCountF, WordPenalty);
};

struct Edge {
  int head;
  string rule;
  vector<int> tails;
  Vector f;
  double weight;

	MSGPACK_DEFINE(head, rule, tails, f, weight);
};

struct Hg {
  Vector weights;
  vector<Node> nodes;
  vector<Edge> edges;
  vector<string> rules;

  MSGPACK_DEFINE(weights, nodes, edges, rules);
};

int
main(int argc, char** argv)
{
  ifstream ifs(argv[1]);
  string str((istreambuf_iterator<char>(ifs)),
                   (istreambuf_iterator<char>()));

	msgpack::zone zone;
	msgpack::object obj;
	msgpack::unpack(str.data(), str.size(), NULL, &zone, &obj);
  Hg hg;
	obj.convert(&hg);
  Edge last_edge = hg.edges.back();
	cerr << last_edge.rule.substr(1, 4) << endl;

  return 0;
}

