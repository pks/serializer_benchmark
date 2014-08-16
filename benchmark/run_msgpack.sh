#!/bin/bash


REPEAT=10
TMP_OVERALL=/tmp/.overall_msgpack


echo
echo "MSGPACK parsing benchmark"
echo "-------------------------"
echo " REAPEAT=$REPEAT"
echo

for prg in \
  test_msgpack \
  test_msgpack_streaming \
  test_msgpack_ruby
do
  echo "[$prg]"
  sudo sync
  sudo sh -c "echo 3 > /proc/sys/vm/drop_caches"
  echo > $TMP_OVERALL
  if [[ $prg == test_msgpack_streaming ]]; then
    A="_s" # special format for streaming
  else
    A=""
  fi
  for file in `ls -S ../data/*.pak$A`; do
    echo "$file:\t$(./benchmark.rb $REPEAT ../src/$prg $file 2>/dev/null | tee -a $TMP_OVERALL | avg | round 2) s"
  done
  echo "---"
  echo "overall:\t$(avg < $TMP_OVERALL | round 2)"
  echo " memory:\t$(./memusg.sh ../src/$prg ../data/1020.pak 2>/dev/null)"
  echo
done

rm $TMP_OVERALL

