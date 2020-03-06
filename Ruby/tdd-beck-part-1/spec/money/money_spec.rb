# frozen_string_literal: true

describe Money do
  describe '#times(*)' do
    it 'mutiplica os escalares e retorna um objeto com o produto como valor' do
      expect(Money.dollar(5) * 3).to eq(Money.dollar(15))
    end
  end

  describe '#equal(==)' do
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
