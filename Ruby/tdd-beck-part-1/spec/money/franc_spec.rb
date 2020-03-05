# frozen_string_literal: true

require 'money/franc'

describe Franc do
  it 'multiplica valor com numero' do
    five = Money.franc(5)
    expect(five * 2).to eq(Money.franc(10))
    expect(five * 3).to eq(Money.franc(15))
  end

  it 'compara dois valores' do
    expect(Money.franc(5)).to eq(Money.franc(5))
    expect(Money.franc(5)).to_not eq(Money.franc(6))
  end
end
