#!/bin/zsh


export PATH=$PATH:/home/pks/src/scripts/
export GEM_PATH=$GEM_PATH:/home/pks/lib/ruby
REPEAT=10

rm -f .overall_msgpack

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
  sync; echo 3 > /proc/sys/vm/drop_caches
  echo > .overall_msgpack
  if [[ $prg == test_msgpack_streaming ]]; then
    A="2" 
  else
    A=""
  fi
  for file in `ls -S data/*.pak$A`; do
    echo "$file:\t$(./benchmark.rb $REPEAT ./$prg $file 2>/dev/null | tee -a .overall_msgpack | avg | round 2) s"
  done
  echo "---"
  echo "overall:\t$(avg < .overall_msgpack | round 2)"
  echo " memory:\t$(./memusg.sh ./$prg data/1020.pak 2>/dev/null)"
  echo
done

rm .overall_msgpack

