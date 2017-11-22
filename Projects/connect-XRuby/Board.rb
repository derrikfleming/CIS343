#!/usr/bin/env ruby

class Board
  # getters for class vars
  attr_reader :board
  attr_writer :board

  attr_reader :width

  attr_reader :height

  attr_reader :connect

  # initializer for new Board
  def initialize(width, height, connect)
    @width = width
    @height = height
    @connect = connect
    build_board(@width, @height)
  end

  # This method builds the actual board. Which is a 2D array, with
  # all values initialized to 0.
  def build_board(width, height)
    @board = Array.new(height) { Array.new(width) { 0 } }
  end

  # This method is called every iteration of the game loop, after each
  # user enters their column choice. It returns an array including the
  # coordinate index of the "square" the user played.
  def move(column, player_num)
    index = nil
    played_col = column - 1
    (@height - 1).downto(0) do |i|
      if (@board[i][played_col]).zero?
        @board[i][played_col] = player_num
        index = [i, played_col, player_num]
        break
      end
    end
    index
  end

  # consolidate calling win checks
  def win_check(index)
    game_over = false
    if check_horizontal(index) >= @connect ||
       check_vertical(index) >= @connect ||
       check_diag_1(index) >= @connect ||
       check_diag_2(index) >= @connect
      game_over = true
    end
    game_over
  end

  # This method checks the row included in index for the largest
  # series connected to index. The loops are exited when an invalid
  # index is checked.
  def check_horizontal(index)
    row = index[0]
    i = index[1]
    player = index[2]
    count = 0

    # check  the columns to the right
    (i..@width - 1).each do |col|
      if @board[row][col] == player
        count += 1
        next
      else
        break
      end
    end

    # check the columns to the left
    (i - 1).downto(0) do |col|
      if @board[row][col] == player
        count += 1
        next
      else
        break
      end
    end
    count
  end

  # This method checks the column included in index for the largest
  # series connected to index. The loop is exited when an invalid
  # index is checked. In this "check"-ing method it is only
  # required to look down, since the "last-played index" is passed in
  # there will never be a situation where there is a piece above it.
  def check_vertical(index)
    i = index[0]
    col = index[1]
    player = index[2]
    count = 0

    # moving "down" column,
    #   ("down" direction as printed)
    (i..@height - 1).each do |row|
      if @board[row][col] == player
        count += 1
        next
      else
        break
      end
    end
    count
  end

  # This method checks the diagonal line from upper right to lower left
  # coinciding with the included index for the largest series
  # connected to index. The loop is exited when an invalid
  # index is checked.
  def check_diag_1(index)
    row = index[0]
    col = index[1]
    player = index[2]
    count = 0

    # "down" and "right" (as printed)
    i_row = row
    j_col = col
    i_row.upto(@height - 1).zip(j_col.upto(@width - 1)) do |i, j|
      break if i.nil? || j.nil? || i > @height - 1 || j > @width - 1
      @board[i][j] == player ? count += 1 : break
    end

    # "up" and "left" (as printed)
    i_row = row - 1
    j_col = col - 1
    if i_row >= 0 && i_row <= @height - 1 && j_col >= 0 && j_col <= @width - 1
      i_row.downto(0).zip(j_col.downto(0)) do |i, j|
        break if i.nil? || j.nil? || i < 0 || j < 0
        @board[i][j] == player ? count += 1 : break
      end
    end
    count
  end

  # This method checks the diagonal line from upper left to lower right
  # coinciding with the included index for the largest series
  # connected to index. The loop is exited when an invalid
  # index is checked.
  def check_diag_2(index)
    row = index[0]
    col = index[1]
    player = index[2]
    count = 0

    # "up" and "right" (as printed)
    i_row = row
    j_col = col
    j_col.upto(@width - 1).zip(i_row.downto(0)) do |j, i|
      puts "row: #{i}, col: #{j}"
      break if i.nil? || j.nil? || i < 0 || j > @width - 1
      @board[i][j] == player ? count += 1 : break
    end
    # "down" and "left" (as printed)
    i_row = row + 1
    j_col = col - 1
    if i_row >= 0 && i_row <= @height - 1 && j_col >= 0 && j_col <= @width - 1
      i_row.upto(@height - 1).zip(j_col.downto(0)) do |i, j|
        break if i.nil? || j.nil? || i >= @height || j < 0
        @board[i][j] == player ? count += 1 : break
      end
    end
    count
  end

  # This method checks if the column of col is "full".
  def col_full(col)
    col_full = false
    # passed col, is direct from usr
    # adjust from 0-indexed array
    col -= 1
    col_full = true unless @board[0][col].zero?
    col_full
  end

  # This method checks if all of the columns are full.
  def board_full
    board_full = true
    (0..@width - 1).each do |col|
      board_full = false if @board[0][col].zero?
    end
    board_full
  end

  # This method prints the board to the console.
  def print_board ()
    @board.each do |i|
      puts i.each { |j| j }.join(' | ')
    end
  end
end