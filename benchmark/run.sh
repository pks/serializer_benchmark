#!/bin/zsh


REPEAT=10
TMP_OVERALL=/tmp/.overall


echo
echo "JSON parsing benchmark"
echo "----------------------"
echo " REAPEAT=$REPEAT"
echo

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
  sudo sync
  sudo sh -c "echo 3 > /proc/sys/vm/drop_caches"
  echo > $TMP_OVERALL
  for file in `ls -S ../data/*.json`; do
    echo "$file:\t$(./benchmark.rb $REPEAT ../src/$prg $file 2>/dev/null | tee -a $TMP_OVERALL | avg | round 2) s"
  done
  echo "---"
  echo "overall:\t$(avg < $TMP_OVERALL | round 2)"
  echo " memory:\t$(./memusg.sh ../src/$prg data/1020.json 2>/dev/null)"
  echo
done

rm $TMP_OVERALL

