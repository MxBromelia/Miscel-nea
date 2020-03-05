# frozen_string_literal: true

require_relative 'money'

class Franc < Money
  def *(multiplier)
    Money.franc(amount * multiplier)
  end
end
