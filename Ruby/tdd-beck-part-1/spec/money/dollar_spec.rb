# frozen_string_literal: true

require 'money/dollar'

describe Dollar do
  it 'multiplica valor com numero' do
    five = Money.dollar(5)
    expect(five * 2).to eq(Money.dollar(10))
    expect(five * 3).to eq(Money.dollar(15))
  end

  it 'compara dois valores' do
    expect(Money.dollar(5)).to eq(Money.dollar(5))
    expect(Money.dollar(5)).to_not eq(Money.dollar(6))
  end

  it 'compara a moeda' do
    expect(Money.dollar(1).currency).to eq('USD')
  end
end
