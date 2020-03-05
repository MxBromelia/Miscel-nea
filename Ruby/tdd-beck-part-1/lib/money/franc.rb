# frozen_string_literal: true

require_relative 'money'

class Franc < Money
  def initialize(amount)
    @amount = amount
  end

  def *(multiplier)
    Franc.new(amount * multiplier)
  end
end
