defmodule TTT do
  @indexes [
    [0, 1, 2], [3, 4, 5], [6, 7, 8],
    [0, 3, 6], [1, 4, 7], [2, 5, 8],
    [0, 4, 8], [2, 4, 6]
  ]
  @players %{
    -1 => :X,
    1 => :O
  }
  def game(turn) do
    board = for _ <- 1..9, do: 0
    play(board, turn)
  end

  defp play(board, turn, status \\ :unfinished)

  defp play(_, _, status) when status != :unfinished do
    case status do
      :tie -> IO.puts "It's a Tie"
      1 -> IO.puts "O Wins"
      -1 -> IO.puts "X Wins"
    end
  end

  defp play(board, turn, _) do
    print_board board
    {status, new_board} = make_turn(board, turn)
    case status do
      :ok -> play(new_board, -turn, game_status(new_board))
      :error -> play(new_board, turn, :unfinished)
    end
  end

  defp make_turn(board, turn) do
    input = IO.gets "#{@players[turn]}, Choose a cell:"
    case Integer.parse(input) do
      :error -> make_turn(board, turn)
      {index, _} -> update_board(board, index, turn)
    end
  end

  # Update Board
  defp update_board(board, index, turn)

  defp update_board(board, _, _) when board == [] do
    {:error, []}
  end

  defp update_board(board, index, turn) when index == 0 do
    [pos | tail] = board
    case pos do
      0 -> {:ok, [turn | tail]}
      _ -> {:error, board}
    end
  end

  defp update_board(board, index, turn) do
    [head | tail] = board
    {status, new_tail} = update_board(tail, index - 1, turn)
    {status, [head | new_tail]}
  end
  # Update Board[END]

  def game_status(board) do

    Enum.map(@indexes, fn el -> index_sublist(board, el) end)
      |> Enum.map(&winner/1)
      |> Enum.filter(fn el -> el != :unfinished end)
      |> (fn list -> result_or_unfinished(list, can_be_tie(board)) end).()
  end

  defp can_be_tie(board) do
    Enum.count(board, fn el -> el == 0 end) == 0
  end

  defp result_or_unfinished(list, can_be_tie) do
    case list do
      [winner] -> winner
      [] -> can_be_tie && :tie || :unfinished
    end
  end

  defp winner(list) do
    case list do
      [x, x, x] when x != 0 -> x
      _ -> :unfinished
    end
  end

  def index_sublist(list, indexes) do
    Enum.with_index(list)
      |> Enum.filter(fn {_, ix} -> Enum.member?(indexes, ix) end )
      |> Enum.map(fn {el, _} -> el end)
  end

  defp print_board(board) do
    IO.write format_board(board)
  end

  # Format Board
  defp format_board(board, index \\ 0)

  defp format_board(board, _) when board == [] do
    ""
  end

  defp format_board(board, index) do
    symbols = %{ 0 => " ", 1 => "O", -1 => "X" }
    [head | tail] = board
    char(symbols[head], index) <> format_board(tail, index + 1)
  end
  # Format Board[END]

  defp char(symbol, index) do
    symbol <> if rem(index+1, 3) == 0, do: "\n", else: "|"
  end
end

TTT.game(1)
