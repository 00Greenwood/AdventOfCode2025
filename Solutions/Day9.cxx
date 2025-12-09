#include "precompiled.hxx"

#include "Day9.hxx"

#include <Line.hxx>
#include <Parser.hxx>
#include <algorithm>

Day9::Day9() : Day(9) {
}

Day9::~Day9() {
}

void Day9::initialize() {
  parse(name(), m_input);
}

std::string Day9::solve(Part part) const {
  std::vector<Line> lines;
  if (part == PART_2) {
    for (size_t i = 0; i < m_input.size() - 1; ++i) {
      lines.push_back({m_input[i], m_input[(i + 1)]});
    }
    lines.push_back({m_input.back(), m_input.front()});
  }

  auto is_valid_line = [&](const Line& line) {
    for (const auto& existing_line : lines) {
      if (line.crosses(existing_line)) {
        return false;
      }
    }
    return true;
  };

  size_t largest_area = 0;
  for (size_t i = 0; i < m_input.size(); ++i) {
    for (size_t j = i + 1; j < m_input.size(); ++j) {
      if (part == PART_2) {
        Position other_corner{m_input[i].x, m_input[j].y};
        Position another_corner{m_input[j].x, m_input[i].y};
        if (!is_valid_line({m_input[i], other_corner}) ||
            !is_valid_line({other_corner, m_input[j]}) ||
            !is_valid_line({m_input[j], another_corner}) ||
            !is_valid_line({another_corner, m_input[i]})) {
          continue;
        }
      }
      size_t width = std::abs(m_input[i].x - m_input[j].x) + 1;
      size_t height = std::abs(m_input[i].y - m_input[j].y) + 1;
      size_t area = width * height;
      if (area > largest_area) {
        largest_area = area;
      }
    }
  }

  return std::to_string(largest_area);
}
