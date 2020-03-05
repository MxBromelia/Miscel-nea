# frozen_string_literal: true

require 'money/franc'

describe Franc do
  it 'multiplica valor com numero' do
    five = Franc.new(5)
    expect(five * 2).to eq(Franc.new(10))
    expect(five * 3).to eq(Franc.new(15))
  end

  it 'compara dois valores' do
    expect(Franc.new(5)).to eq(Franc.new(5))
    expect(Franc.new(5)).to_not eq(Franc.new(6))
  end
end
