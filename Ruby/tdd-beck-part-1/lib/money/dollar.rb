# frozen_string_literal: true

require_relative 'money'

class Dollar < Money
  def *(multiplier)
    Money.dollar(amount * multiplier)
  end
end
