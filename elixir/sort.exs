defmodule Sort do

  def insertion_sort(list, sorted \\ []) do
    case list do
      [] -> sorted
      [head | tail] -> insertion_sort(tail, insert_sorted(head, sorted))
    end
  end

  def insert_sorted(element, sorted)

  def insert_sorted(element, []) do
    [element]
  end

  def insert_sorted(element, [head | tail]) do
    if element < head do
      [element, head | tail]
    else
      [head | insert_sorted(element, tail)]
    end
  end
end
