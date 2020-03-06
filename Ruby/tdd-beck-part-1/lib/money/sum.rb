class Sum
  attr_reader :augend, :addend

  def initialize(augend, addend)
    @augend = augend
    @addend = addend
  end

  def reduce(bank, currency)
    amount = @augend.amount + @addend.amount
    Money.new(amount, currency)
  end
end
