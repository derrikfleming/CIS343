#!/usr/bin/env ruby
# The following manner of parsing was developed using example code
# included in Ruby's optparse documentation, the specific examples were
# found at the following url:
# http://ruby-doc.org/stdlib-2.4.0/libdoc/optparse/rdoc/OptionParser.html

require 'optparse'
require 'ostruct'

class Parser
  def self.parse(args)
    # a struct to hold the parsed options
    options = OpenStruct.new

    #set struct to default game values
    options.width = 7
    options.height = 7
    options.connect = 4
    options.load = nil

    # use OptionParser to parse arguments with the following flags
    opt_parser = OptionParser.new do |opts|
      opts.banner = "Usage: connect_x.rb [options]"

      opts.on("-w ", "--width=WIDTH", "The width of the game board") do |width|
        options.width = width.to_i
      end

      opts.on("-h ", "--height=HEIGHT", "The height of the game board") do |height|
        options.height = height.to_i
      end

      opts.on("-s ", "--square=SQUARE", "A square game board") do |square|
        options.height = square.to_i
        options.width = square.to_i
      end

      opts.on("-c ", "--connect=CONNECT", "The required series length to win") do |connect|
        options.connect = connect.to_i
      end

      opts.on("-l ", "--load=LOAD", "The name of the previously saved game to load") do |load|
        options.load = load
      end

      opts.on("-?", "--help", "Prints argument definitions") do
        puts opts
        exit
      end
    end
    opt_parser.parse!(args)

    # return the options that were parsed
    options
  end
end