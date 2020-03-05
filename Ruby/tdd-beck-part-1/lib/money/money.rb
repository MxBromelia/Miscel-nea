class Money
  attr_accessor :amount
  attr_reader :currency
  

  def self.dollar(amount)
    Dollar.new(amount, 'USD')
  end

  def self.franc(amount)
    Franc.new(amount, 'CHF')
  end

  def initialize(amount, currency)
    @amount = amount
    @currency = currency
  end

  def ==(other)
    self.class == other.class && @amount == other.amount
  end
end