#include "precompiled.hxx"

#include "Day3.hxx"

#include <Parser.hxx>

Day3::Day3() : Day(3) {
}

Day3::~Day3() {
}

void Day3::initialize() {
  parse(name(), m_input);
}

std::string Day3::solve(Part part) const {
  int64_t joltage = 0;
  for (const auto& row : m_input) {
    std::string max_values;
    int number_of_values = part == PART_1 ? 2 : 12;
    size_t starting_index = 0;
    for (int i = number_of_values; i > 0; i--) {
      char max_value = '0';
      size_t max_index = 0;
      for (size_t col = starting_index; col <= row.size() - i; col++) {
        if (row[col] > max_value) {
          max_value = row[col];
          max_index = col;
        }
      }
      max_values += max_value;
      starting_index = max_index + 1;
    }
    joltage += stoll(max_values);
  }
  return std::to_string(joltage);
}
