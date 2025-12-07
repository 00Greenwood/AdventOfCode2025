#include "precompiled.hxx"

#include "Day1.hxx"

#include <Parser.hxx>

Day1::Day1() : Day(1) {
}

Day1::~Day1() {
}

void Day1::initialize() {
  parse(name(), m_input);
}

std::string Day1::solve(Part part) const {
  int dial = 50;
  int count = 0;
  for (const auto& [direction, distance] : m_input) {
    if (direction == 'L') {
      for (int i = 0; i < distance; i++) {
        dial--;
        if (part == PART_2 && dial % 100 == 0) {
          // For part 2, count how many times we pass 0.
          count++;
        }
      }
    } else if (direction == 'R') {
      for (int i = 0; i < distance; i++) {
        dial++;
        if (part == PART_2 && dial % 100 == 0) {
          // For part 2, count how many times we pass 0.
          count++;
        }
      }
    }
    if (part == PART_1 && dial % 100 == 0) {
      // For part 1, count how many times we land on 0.
      count++;
    }
    dial %= 100;
  }
  return std::to_string(count);
}
