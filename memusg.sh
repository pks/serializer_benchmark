#!/bin/bash


"$@" &
pid=$! peak=0
while true; do
  sleep 1
  sample="$(ps -o rss= $pid 2> /dev/null)" || break
  let peak='sample > peak ? sample : peak'
done
#echo "Peak: $peak" 1>&2
echo "$(( ${peak%% *} / 1024)) m"

