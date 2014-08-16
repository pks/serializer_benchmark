#include <iostream>
#include <fstream>
#include <string>

/*
 * https://github.com/ascheglov/json-cpp
 *
 */
#include "json-cpp/single_include/json-cpp.hpp"

using namespace std;


struct Node {
  int id;
  string cat;
  vector<int> span;
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
};

struct Edge {
  int head;
  string rule;
  vector<int> tails;
  Vector f;
  double weight;
};

struct Hg {
  Vector weights;
  vector<Node> nodes;
  vector<Edge> edges;
  vector<string> rules;
};

template<typename X> inline void
serialize(jsoncpp::Stream<X>& stream, Hg& o)
{
  fields(o, stream, "weights", o.weights, "nodes", o.nodes, "edges", o.edges, "rules", o.rules);
}

template<typename X> inline void
serialize(jsoncpp::Stream<X>& stream, Edge& o)
{
  fields(o, stream, "head", o.head, "rule", o.rule, "tails", o.tails, "f", o.f, "weight", o.weight);
}

template<typename X> inline void
serialize(jsoncpp::Stream<X>& stream, Vector& o)
{
  fields(o, stream, "EgivenFCoherent", o.EgivenFCoherent, "SampleCountF", o.SampleCountF, "CountEF", o.CountEF, "MaxLexFgivenE", o.MaxLexFgivenE, "MaxLexEgivenF", o.MaxLexEgivenF, "IsSingletonF", o.IsSingletonF, "IsSingletonFE", o.IsSingletonFE, "LanguageModel", o.LanguageModel, "LanguageModel_OOV", o.LanguageModel_OOV, "PassThrough", o.PassThrough, "PassThrough_1", o.PassThrough_1, "PassThrough_2", o.PassThrough_2, "PassThrough_3", o.PassThrough_3, "PassThrough_4", o.PassThrough_4, "PassThrough_5", o.PassThrough_5, "PassThrough_6", o.PassThrough_6, "WordPenalty", o.WordPenalty, "Glue", o.Glue);
}

template<typename X> inline void
serialize(jsoncpp::Stream<X>& stream, Node& o)
{
  fields(o, stream, "id", o.id, "cat", o.cat, "span", o.span);
}

int
main(int argc, char** argv)
{
  ifstream ifs(argv[1]);
  string json_str((istreambuf_iterator<char>(ifs) ),
                   (istreambuf_iterator<char>()));

  Hg hg;
  Vector w;
  hg.weights = w;
  vector<Node> nodes;
  hg.nodes = nodes;
  vector<Edge> edges;
  hg.edges = edges;
  jsoncpp::parse(hg, json_str);
  Edge& last_edge = hg.edges.back();
  cerr << last_edge.rule.substr(1, 4) << endl;

  return 0;
}

