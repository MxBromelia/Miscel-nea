# frozen_string_literal: true

class Dollar
  attr_accessor :amount

  def initialize(amount)
    @amount = amount
  end

  def *(multiplier)
    Dollar.new(amount * multiplier)
  end

  def ==(other)
    @amount == other.amount
  end
end
