COMPILER := g++
CXXFLAGS := -O3 -march=native -mtune=native


all: test_gason test_json-cpp test_jsoncpp test_libjson test_picojson test_rapidjson test_sajson test_JsonBox test_jsonxx test_MicroJSON test_nosjob test_cdec_json_parser

test_gason: test_gason.cc
	$(COMPILER) $(CXXFLAGS) -std=c++11 test_gason.cc -o test_gason gason/gason.o

test_json-cpp: test_json-cpp.cc
	$(COMPILER) $(CXXFLAGS) -std=c++11 test_json-cpp.cc -o test_json-cpp

test_jsoncpp: test_jsoncpp.cc
	$(COMPILER) $(CXXFLAGS) test_jsoncpp.cc jsoncpp/lib/libjsoncpp.a -o test_jsoncpp

test_libjson: test_libjson.cc
	$(COMPILER) $(CXXFLAGS) test_libjson.cc libjson/libjson.a -o test_libjson

test_picojson: test_picojson.cc
	$(COMPILER) $(CXXFLAGS) test_picojson.cc -o test_picojson

test_rapidjson: test_rapidjson.cc
	$(COMPILER) $(CXXFLAGS) test_rapidjson.cc -o test_rapidjson

test_sajson: test_sajson.cc
	$(COMPILER) $(CXXFLAGS) test_sajson.cc -o test_sajson

test_JsonBox: test_JsonBox.cc
	$(COMPILER) $(CXXFLAGS) test_JsonBox.cc -I./JsonBox/include/ JsonBox/libJsonBox.a -o test_JsonBox

test_jsonxx: test_jsonxx.cc
	$(COMPILER) $(CXXFLAGS) test_jsonxx.cc jsonxx/jsonxx.o -o test_jsonxx

test_MicroJSON: test_MicroJSON.cc
	#$(COMPILER) $(CXXFLAGS) test_MicroJSON.cc MicroJSON-0.3.2/libMicroJSON-0.so -lUTF8Strings-1 -o test_MicroJSON

test_nosjob: test_nosjob.cc
	$(COMPILER) $(CXXFLAGS) test_nosjob.cc nosjob-e1d67401fcda6e05/libnosjob.a -o test_nosjob

test_cdec_json_parser: test_cdec_json_parser.cc
	$(COMPILER) $(CXXFLAGS) test_cdec_json_parser.cc cdec_json_parser/json_parse.o cdec_json_parser/JSON_parser.o -o test_cdec_json_parser

test_msgpack: test_msgpack.cc
	 $(COMPILER) $(CXXFLAGS) test_msgpack.cc -I./msgpack-c/include/ ./msgpack-c/lib/libmsgpack.a -o test_msgpack

test_msgpack_streaming: test_msgpack_streaming.cc
	 $(COMPILER) $(CXXFLAGS) test_msgpack_streaming.cc -I./msgpack-c/include/ ./msgpack-c/lib/libmsgpack.a -o test_msgpack_streaming

clean:
	rm -f test_gason test_json-cpp test_jsoncpp test_libjson
	rm -f test_picojson test_rapidjson test_sajson test_JsonBox
	rm -f test_jsonxx test_MicroJSON test_nosjob test_cdec_json_parser
	rm -f test_msgpack

