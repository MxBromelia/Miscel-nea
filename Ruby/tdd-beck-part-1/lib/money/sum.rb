class Sum
  attr_reader :augend, :addend

  def initialize(augend, addend)
    @augend = augend
    @addend = addend
  end

  def reduce(bank, currency)
    amount = @augend.reduce(bank, currency).amount + @addend.reduce(bank, currency).amount
    Money.new(amount, currency)
  end

  def +(other)
    Sum.new(self, other)
  end

  def *(other)
    Sum.new(@augend * other, @addend * other)
  end
end
