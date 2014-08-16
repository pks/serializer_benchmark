#include <msgpack.hpp>
#include <msgpack/fbuffer.hpp>
#include <iostream>
#include <string>
#include <fstream>

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

  MSGPACK_DEFINE(weights, nodes, edges);
};

int
main(int argc, char** argv) {
  ifstream ifs(argv[1]);

  size_t count = 0, n_, e_;
  msgpack::unpacker pac;
  while(true) {
      pac.reserve_buffer(32*1024);
      size_t bytes = ifs.readsome(pac.buffer(), pac.buffer_capacity());
      pac.buffer_consumed(bytes);
      msgpack::unpacked result;
      while(pac.next(&result)) {
          msgpack::object obj = result.get();
          if (count ==  0) {
            obj.convert(&n_);
            n_ += 2;
          } else  if (count == 1) {
            obj.convert(&e_);
            e_ += 2;
          } else if (count == 2) {
            Vector v; 
            obj.convert(&v);
          } else if (count > 2 && count <= n_) { 
            Node n;
            obj.convert(&n);
          } else if (count > n_ && count <= n_+e_+1) {
            Edge e;
            obj.convert(&e);
            string s = e.rule.substr(1, 4);
            if (s == "Goal")
              cout << s << endl;
          }
          count++;
      }
      if (!bytes) break;
  }

  return 0;
}

