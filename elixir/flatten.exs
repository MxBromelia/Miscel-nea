defmodule Flatten do
  defp reverse(list, result) do
    case list do
      [] -> result
      [head | tail] -> reverse(tail, [head | result])
    end
  end

  def tflatten(list, result \\ [])

  def tflatten(list, result) do
    case list do
      [] -> reverse(result)
      [head | tail] -> tflatten(tail, [tflatten(head) | result])
      x -> [x | result]
    end
  end
end
