class Money
  attr_accessor :amount
  attr_reader :currency
  

  def self.dollar(amount)
    Money.new(amount, 'USD')
  end

  def self.franc(amount)
    Money.new(amount, 'CHF')
  end

  def initialize(amount, currency)
    @amount = amount
    @currency = currency
  end

  def *(other)
    Money.new(@amount * other, @currency)
  end

  def ==(other)
    @currency == other.currency && @amount == other.amount
  end

  def to_s
    "#{amount} #{currency}"
  end
end