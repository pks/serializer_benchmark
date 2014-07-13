#!/bin/zsh


# wmt/14/newstest2008 data
for i in 1020 1391 1495 1570 1889 2002 429 748; do
  ~/src/weaver/util/cdec2json.py -c cdec.ini -w weights.init -g grammar.$i.gz < $i.in | ./to_ascii.rb > $i.json 
done

