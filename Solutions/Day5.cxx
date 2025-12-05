#include "Day5.hxx"
#include "precompiled.hxx"

#include <Parser.hxx>

Day5::Day5() : Day(5) {
}

Day5::~Day5() {
}

void Day5::initialize() {
  parse(name(), m_input);
}

std::string Day5::solve(Part part) const {
  int64_t count = 0;
  if (part == PART_1) {
    for (const auto& item : m_input.second) {
      for (const auto& [a, b] : m_input.first) {
        if (item >= a && item <= b) {
          ++count;
          break;
        }
      }
    }
  } else {
    std::vector<std::pair<int64_t, int64_t>> inputs = m_input.first;
    while (true) {
      std::set<std::pair<int64_t, int64_t>> covered;
      std::vector<std::pair<int64_t, int64_t>> merged;
      for (size_t i = 0; i < inputs.size(); ++i) {
        if (covered.contains(inputs[i])) {
          // Already merged!
          continue;
        }
        auto [a, b] = inputs[i];
        covered.insert({a, b});
        std::set<int64_t> left_intersections = {a};
        std::set<int64_t> right_intersections = {b};
        for (size_t j = i + 1; j < inputs.size(); ++j) {
          if (covered.contains(inputs[j])) {
            // Already merged!
            continue;
          }
          auto [x, y] = inputs[j];
          if ((x >= a && y <= b) || (a >= x && b <= y) || (b >= x && b <= y) || (a >= x && a <= y)) {
            covered.insert({x, y});
            left_intersections.insert(x);
            right_intersections.insert(y);
          }
        }
        merged.push_back({*left_intersections.begin(), *right_intersections.rbegin()});
      }
      if (merged.size() == inputs.size()) {
        // No more merges
        break;
      }
      inputs = merged;
    }
    for (const auto& item : inputs) {
      count += item.second - item.first + 1;
    }
  }
  return std::to_string(count);
}
