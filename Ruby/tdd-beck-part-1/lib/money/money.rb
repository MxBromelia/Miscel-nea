class Money
  attr_accessor :amount

  def ==(other)
    self.class == other.class && @amount == other.amount
  end
end