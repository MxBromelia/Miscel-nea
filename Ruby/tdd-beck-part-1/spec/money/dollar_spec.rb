# frozen_string_literal: true

require 'money/dollar'

describe Dollar do
  it 'multiplica valor com numero' do
    five = Dollar.new(5)
    expect(five * 2).to eq(Dollar.new(10))
    expect(five * 3).to eq(Dollar.new(15))
  end

  it 'compara dois valores' do
    expect(Dollar.new(5)).to eq(Dollar.new(5))
    expect(Dollar.new(5)).to_not eq(Dollar.new(6))
  end
end
