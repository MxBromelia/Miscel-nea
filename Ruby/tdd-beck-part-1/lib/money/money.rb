class Money
  attr_accessor :amount

  def self.dollar(amount)
    Dollar.new(amount)
  end

  def self.franc(amount)
    Franc.new(amount)
  end

  def ==(other)
    self.class == other.class && @amount == other.amount
  end
end