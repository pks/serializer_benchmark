#!/bin/zsh


export PATH=$PATH:/home/pks/src/scripts/
export GEM_PATH=$GEM_PATH:/home/pks/lib/ruby
REPEAT=10

rm -f .overall

echo
echo "JSON parsing benchmark"
echo "----------------------"
echo " REAPEAT=$REPEAT"
echo

# fails: test_MicroJSON.sh \
for prg in \
  test_cdec_json_parser \
  test_gason \
  test_JsonBox \
  test_jsoncpp \
  test_json-cpp \
  test_jsonxx \
  test_libjson \
  test_nosjob \
  test_picojson \
  test_rapidjson \
  test_sajson
do
  echo "[$prg]"
  sync; echo 3 > /proc/sys/vm/drop_caches
  echo > .overall
  for file in `ls -S data/*.json`; do
    echo "$file:\t$(./benchmark.rb $REPEAT ./$prg $file 2>/dev/null | tee -a .overall | avg | round 2) s"
  done
  echo "---"
  echo "overall:\t$(avg < .overall | round 2)"
  echo " memory:\t$(./memusg.sh ./$prg data/1020.json 2>/dev/null)"
  echo
done

rm .overall

