# frozen_string_literal: true

require 'money/money'
require 'money/bank'

describe Money do
  describe '#sum(+)' do
    it 'soma os dois escalares se a moeda é do mesmo tipo' do
      expect(Bank.new.reduce(Money.dollar(5) + Money.dollar(5), 'USD')).to eq(Money.dollar(10))
    end

    it 'soma duas moedas de tipo diferente' do
      sum = Money.dollar(5) + Money.dollar(5)
      bank = Bank.new
      reduced = bank.reduce(sum, 'USD')
      expect(reduced).to eq(Money.dollar(10))
    end

    it 'test plus returns sum' do
      sum = Money.dollar(5) + Money.dollar(5)
      expect(sum.augend).to eq(Money.dollar(5))
      expect(sum.addend).to eq(Money.dollar(5))
    end

    it 'test reduce sum' do
      sum = Sum.new(Money.dollar(3), Money.dollar(4))
      bank = Bank.new
      result = bank.reduce(sum, 'USD')
      expect(Money.dollar(7)).to eq(result)
    end

    it 'test reduce money' do
      bank = Bank.new
      result = bank.reduce(Money.dollar(1), 'USD')
      expect(Money.dollar(1)).to eq(result)
    end
  end

  describe '#product(*)' do
    it 'mutiplica os escalares e retorna um objeto com o produto como valor' do
      expect(Money.dollar(5) * 3).to eq(Money.dollar(15))
    end
  end

  describe '#equality(==)' do
    it 'comparar valores se moeda é a mesma' do
      expect(Money.franc(5)).to eq(Money.franc(5))
      expect(Money.dollar(5)).to_not eq(Money.dollar(6))
    end

    it 'comparar valores com peso se moeda é outra' do
      expect(Money.franc(5)).to_not eq(Money.dollar(5))
    end
  end

  describe '#currency' do
    it 'comparara a igualdade do tipo de moeda' do
      expect(Money.franc(5).currency).to eq('CHF')
      expect(Money.dollar(5).currency).to eq('USD')
    end
  end
end
