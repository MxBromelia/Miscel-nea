# frozen_string_literal: true

class Franc
  attr_accessor :amount

  def initialize(amount)
    @amount = amount
  end

  def *(multiplier)
    Franc.new(amount * multiplier)
  end

  def ==(other)
    @amount == other.amount
  end
end
