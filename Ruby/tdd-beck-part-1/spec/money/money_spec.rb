# frozen_string_literal: true

describe Money do
  it 'compara duas moedas de valores diferentes' do
    expect(Franc.new(5)).to_not eq(Dollar.new(5))
  end
end
