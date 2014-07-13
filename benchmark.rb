#!/usr/bin/env ruby


ARGV[0].to_i.times {
  start = Time.now
  `#{ARGV[1]} #{ARGV[2]}`
  puts Time.now-start
}

