Serializer Benchmark
====================

Comparing parsing speed/memory usage of all C++ JSON libs I could find. Also including two msgpack implementations (C++/Ruby).
Goal is to output object.edges.last.rule.substr(1, 4).
Data are fairly large and complex objects (hypergraph representations) with a lot of different types, e.g. strings (ASCII), ints, floats, arrays
and sub-objects.
Note that the comparison is unfair for some parsers, as they just do SAX-style parsing and do not actually fill "real" objects
with data (e.g. the cdec json parser).

* cdec-json-parser: ripped out of [1].
* gason: git clone https://github.com/vivkin/gason.git
* JsonBox: git clone https://github.com/anhero/JsonBox.git
* jsoncpp: git clone https://github.com/open-source-parsers/jsoncpp.git
* json-cpp: wget "https://raw.githubusercontent.com/ascheglov/json-cpp/master/single_include/json-cpp.hpp"
* jsonxx: git clone https://github.com/hjiang/jsonxx.git
* libjson: wget "http://downloads.sourceforge.net/project/libjson/libjson_7.6.1.zip?r=&ts=1405248411&use_mirror=heanet"
* MicroJSON: wget http://grigory.info/distfiles/MicroJSON-0.3.2.tar.bz2
* msgpack-c: git clone https://github.com/msgpack/msgpack-c.git
* msgpack-ruby: gem install msgpack
* nosjob: go to [2] and figure out how to download a tarball
* picojson: git clone https://github.com/kazuho/picojson.git
* rapidjson: git clone https://github.com/miloyip/rapidjson.git
* sajson: git clone https://github.com/chadaustin/sajson.git

To run the benchmark You'll need root privileges to clear the disk caches.
The run scripts assume that these scripts [3] are in the PATH.

Versions:
---------
* cdec-json-parser: SHA-1 d124d4aaa78b52b46f7ac8d7306be342d3405124
* gason: SHA-1 ede29fc5f0de8e47fd82c09f2f98123d2c867f28
* JsonBox: SHA-1 fcb82ebae41dffb90d32a49ac236d1608d9a67ee
* jsoncpp: SHA-1 655a9db0cc62394e81d3074a98c7191fbfc00259
* json-cpp: SHA-1 170121e2dc099895064305e38bfb25d90a807ce3
* libjson: version 7.6.1
* MicroJSON: version 0.3.2
* msgpack-c: SHA-1 197ed8c983a70d5892bf73dcd1a352bf8e2588df
* msgpack-ruby: version 0.5.8
* nosjob: SHA-1 e1d67401fcda6e05a536272532bdb9770bec27e8
* picojson: SHA-1 5e71db9bec7f22a041cd251c6d6d67e954396d5d
* rapidjson: SHA-1 63d054349ab56d278060cd3373e76a6933cf194a
* sajson: SHA-1 003988269f1774dfb184e1864f2f4e654965581e

* [1] https://github.com/redpony/cdec/tree/master/decoder
* [2] http://fossil.wanderinghorse.net/repos/nosjob/index.cgi/index
* [3] https://github.com/pks/scripts


Results
=======

*Spoiler:* sajson and rapidjson are the fastest JSON parsers -- but msgpack is even faster.

Benchmarks were run on my trusty laptop (IBM/Lenovo X61s): 
<pre>
Linux x 3.12.23 #1 SMP PREEMPT Fri Jul 4 15:09:43 CEST 2014 x86_64 Intel(R) Core(TM)2 Duo CPU L7500 @ 1.60GHz GenuineIntel GNU/Linux
</pre>
Disk is an Intel X25-E SSD.


JSON parsing benchmark
----------------------
 REAPEAT=10

<pre>
[test_cdec_json_parser]
data/1020.json: 8.81 s
data/1570.json: 3.07 s
data/1391.json: 1.99 s
data/429.json:  0.6 s
data/2002.json: 0.32 s
data/1889.json: 0.07 s
data/1495.json: 0.01 s
data/748.json:  0.0 s
---
overall: 1.84 s
 memory: 1 m

[test_gason]
data/1020.json: 4.34 s
data/1570.json: 1.52 s
data/1391.json: 1.05 s
data/429.json:  0.29 s
data/2002.json: 0.16 s
data/1889.json: 0.03 s
data/1495.json: 0.01 s
data/748.json:  0.01 s
---
overall: 0.91 s
 memory: 389 m

[test_JsonBox]
data/1020.json: 36.15 s
data/1570.json: 11.91 s
data/1391.json: 8.25 s
data/429.json:  2.3 s
data/2002.json: 1.21 s
data/1889.json: 0.24 s
data/1495.json: 0.02 s
data/748.json:  0.0 s
---
overall: 7.42 s
 memory: 901 m

[test_jsoncpp]
data/1020.json: 9.59 s
data/1570.json: 3.32 s
data/1391.json: 2.19 s
data/429.json:  0.64 s
data/2002.json: 0.34 s
data/1889.json: 0.07 s
data/1495.json: 0.01 s
data/748.json:  0.01 s
---
overall: 2.0 s
 memory: 804 m

[test_json-cpp]
data/1020.json: 4.32 s
data/1570.json: 1.44 s
data/1391.json: 0.99 s
data/429.json:  0.28 s
data/2002.json: 0.15 s
data/1889.json: 0.03 s
data/1495.json: 0.01 s
data/748.json:  0.0 s
---
overall: 0.89 s
 memory: 263 m

[test_jsonxx]
data/1020.json: 36.85 s
data/1570.json: 12.86 s
data/1391.json: 8.36 s
data/429.json:  2.4 s
data/2002.json: 1.29 s
data/1889.json: 0.26 s
data/1495.json: 0.01 s
data/748.json:  0.0 s
---
overall: 7.66 s
 memory: 1440 m

[test_libjson]
data/1020.json: 13.09 s
data/1570.json: 4.51 s
data/1391.json: 3.0 s
data/429.json:  0.86 s
data/2002.json: 0.46 s
data/1889.json: 0.09 s
data/1495.json: 0.01 s
data/748.json:  0.0 s
---
overall: 2.72 s
 memory: 1649 m

[test_nosjob]
data/1020.json: 17.64 s
data/1570.json: 6.18 s
data/1391.json: 4.09 s
data/429.json:  1.16 s
data/2002.json: 0.62 s
data/1889.json: 0.13 s
data/1495.json: 0.01 s
data/748.json:  0.0 s
---
overall: 3.68 s
 memory: 931 m

[test_picojson]
data/1020.json: 17.35 s
data/1570.json: 5.51 s
data/1391.json: 3.97 s
data/429.json:  1.07 s
data/2002.json: 0.55 s
data/1889.json: 0.11 s
data/1495.json: 0.01 s
data/748.json:  0.01 s
---
overall: 3.53 s
 memory: 1049 m

[test_rapidjson]
data/1020.json: 3.27 s
data/1570.json: 1.08 s
data/1391.json: 0.75 s
data/429.json:  0.21 s
data/2002.json: 0.11 s
data/1889.json: 0.03 s
data/1495.json: 0.01 s
data/748.json:  0.0 s
---
overall: 0.67 s
 memory: 415 m

[test_sajson]
data/1020.json: 2.94 s
data/1570.json: 0.97 s
data/1391.json: 0.66 s
data/429.json:  0.19 s
data/2002.json: 0.1 s
data/1889.json: 0.02 s
data/1495.json: 0.0 s
data/748.json:  0.0 s
---
overall: 0.6 s
 memory: 293 m
</pre>


MSGPACK parsing benchmark
-------------------------
 REAPEAT=10

<pre>
[test_msgpack]
data/1020.pak: 2.2 s
data/1570.pak: 0.8 s
data/1391.pak: 0.5 s
data/429.pak:  0.15 s
data/2002.pak: 0.09 s
data/1889.pak: 0.02 s
data/1495.pak: 0.0 s
data/748.pak:  0.0 s
---
overall: 0.47 s
 memory: 451 m

[test_msgpack_ruby]
data/1020.pak: 1.91 s
data/1570.pak: 0.76 s
data/1391.pak: 0.52 s
data/429.pak:  0.23 s
data/2002.pak: 0.19 s
data/1889.pak: 0.14 s
data/1495.pak: 0.13 s
data/748.pak:  0.13 s
---
overall: 0.5 s
 memory: 216 m
</pre>

