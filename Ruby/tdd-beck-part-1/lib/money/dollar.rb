# frozen_string_literal: true

require_relative 'money'

class Dollar < Money
  def initialize(amount)
    @amount = amount
  end

  def *(multiplier)
    Dollar.new(amount * multiplier)
  end
end
