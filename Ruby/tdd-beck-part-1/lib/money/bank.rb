require 'pp'

class Bank
  def initialize
    @rates = {}
  end

  def reduce(exp, currency)
    exp.reduce(self, currency)
  end

  def add_rate(from, to, rate)
    @rates[Pair.new(from, to)] = rate
  end

  def rate(from, to)
    @rates[Pair.new(from, to)]
  end

  class Pair
    attr_reader :from, :to

    def initialize(from, to)
      @from = from
      @to = to
    end

    def ==(other)
      @from == other.from && @to == other.to
    end

    alias eql? ==

    def hash
      0
    end
  end
end
