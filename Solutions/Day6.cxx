#include "precompiled.hxx"

#include "Day6.hxx"

#include <Parser.hxx>

Day6::Day6() : Day(6) {
}

Day6::~Day6() {
}

void Day6::initialize() {
  parse(name(), m_input);
}

std::string Day6::solve(Part part) const {
  std::vector<std::pair<std::vector<int64_t>, char>> input;

  std::map<size_t, std::string> numbers;
  char operation;
  int digit_index = -1;
  for (size_t i = 0; i < m_input[0].size(); ++i) {
    digit_index++;
    size_t spaces = 0;
    for (size_t line_index = 0; line_index < m_input.size(); ++line_index) {
      char ch = m_input[line_index][i];
      if (std::isdigit(ch)) {
        if (part == PART_1) {
          // Human numbers
          if (numbers.contains(line_index)) {
            numbers[line_index] += ch;
          } else {
            numbers[line_index] = std::string(1, ch);
          }
        } else {
          // Cephalopod numbers - sideways
          if (numbers.contains(digit_index)) {
            numbers[digit_index] += ch;
          } else {
            numbers[digit_index] = std::string(1, ch);
          }
        }
      } else if (ch == '+' || ch == '*') {
        operation = ch;
      } else if (ch == ' ') {
        spaces++;
      }
      if (spaces == m_input.size()) {
        std::pair<std::vector<int64_t>, char> entry;
        for (const auto& [_, num_str] : numbers) {
          entry.first.push_back(std::stoll(num_str));
        }
        entry.second = operation;
        input.push_back(entry);
        numbers.clear();
        operation = '\0';
        digit_index = -1;
        break;
      }
    }
  }

  // Handle last entry
  std::pair<std::vector<int64_t>, char> entry;
  for (const auto& [_, num_str] : numbers) {
    entry.first.push_back(std::stoll(num_str));
  }
  entry.second = operation;
  input.push_back(entry);

  int64_t result = 0;
  for (const auto& [numbers, operation] : input) {
    int64_t sub_result = (operation == '+') ? 0 : 1;
    for (const auto& number : numbers) {
      if (operation == '+') {
        sub_result += number;
      } else if (operation == '*') {
        sub_result *= number;
      }
    }
    result += sub_result;
  }
  return std::to_string(result);
}
