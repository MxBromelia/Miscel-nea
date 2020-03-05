# frozen_string_literal: true

describe Money do
  it 'compara duas moedas de valores diferentes' do
    expect(Money.franc(5)).to_not eq(Money.dollar(5))
  end
end
