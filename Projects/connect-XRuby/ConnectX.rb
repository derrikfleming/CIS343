#!/usr/bin/env ruby
require './parser'
require './board'
require 'pp'

# This file serves as main for all purposes for the ConnectX game.
# The following method contains saving/loading methods, as well as
# main game loop.
if __FILE__ == $0
  # This method saves the board (object) to the specified file
  # name. Marshal is used to serialize the object.
  def save_game(file_name, board)
    begin
      File.open("./#{file_name}.sg", 'wb') do |file|
        Marshal.dump(board, file)
      end
    rescue SystemCallError => e
      puts "Error: #{e}"
      puts 'Save failed!'
    end
  end
  # This method loads the file of specified file name, and
  # de-serializes the file. Returns the resulting object.
  def load_game(file_name)
    new_board = nil
    begin
      game = File.open("./#{file_name}.sg", 'rb') do |file|
        new_board = Marshal.load(file)
      end
    rescue SystemCallError => e
      puts "Error: #{e}"
      puts 'Load failed!'
    end
    new_board
  end
  game_over = false

  player_num = 1

  # getting parsed args from command line
  args = Parser.parse(ARGV)

  # no load filename passed
  if args.load.nil?
    width = args.width.to_i
    height = args.height.to_i
    connect = args.connect.to_i

    # player must be able to win vert && horiz && diag
    # for @board to be valid.
    if connect > height && connect > width
      width = 7
      height = 7
      connect = 4
    end
    board = Board.new(width, height, connect)
  # if the -l flag was used
  else
    board = load_game(args.load.to_s)
    width = board.width
    height = board.height
    connect = board.connect
  end

  puts '***********************************'
  puts '*           Welcome to            *'
  puts '*        Connect-X in Ruby        *'
  puts '*       By:  Derrik Fleming       *'
  puts '* =============================== *'
  puts '*              Use l              *'
  puts '*         to load a game          *'
  puts '*              Use s              *'
  puts '*         to save a game          *'
  puts "* =============================== *\n\n"

  #initial print of board
  board.print_board
  game_over = false
  #the main game loop
  while game_over == false do
    print "Player #{player_num}, please select a column (1 - #{width}): "
    column = gets.chomp
    print "\n"

    # check input for save option
    if column.to_s == "s"
      puts 'Please enter a file name: '
      file_name = gets.chomp.to_s
      save_game(file_name, board)

    # check input for load option
    elsif column.to_s == "l"
      puts 'Please enter a file name: '
      file_name = gets.chomp.to_s
      board = load_game(file_name) unless load_game(file_name).nil?

    # check if input is valid column on game board
    elsif column.to_i >= 1 && column.to_i <= width
      if !board.col_full(column.to_i)
        index = board.move(column.to_i, player_num)
        player_num == 1 ? player_num = 2 : player_num = 1
      else
        puts "Column seems to be full!\nPlease try again!\n\n"
      end

    # if input is not valid
    else
      puts "Invalid entry! Please try again. \n\n"
      next
    end

    # check if game is over,
    if board.win_check(index) == true
      board.print_board
      puts "\n"
      player_num == 1 ? player_num = 2 : player_num = 1
      puts "Congrats Player #{player_num}! You've won!"
      game_over = true
    end

    if board.board_full == true
      puts "The game has resulted in a draw.\nNice defense!"
      game_over = true
    end

    # When game over
    if game_over == true
      print "Play again? (y/n): "
      choice = gets.chomp
      if choice.to_s.casecmp('y').zero?
        game_over = false
        board = Board.new(width, height, connect)
        puts "\n\nNew game beginning.."
      else
        break
      end
    end
    board.print_board
  end
  # Exit message, on game loop exit
  puts "You did not choose to continue.\nExiting . . ."
  exit(0)
end


