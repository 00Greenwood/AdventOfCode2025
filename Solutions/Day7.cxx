#include "precompiled.hxx"

#include "Day7.hxx"

#include <Parser.hxx>

Day7::Day7() : Day(7) {
}

Day7::~Day7() {
}

void Day7::initialize() {
  parse(name(), m_input);
}

std::string Day7::solve(Part part) const {
  // Locations of beams & thier timelines.
  std::map<size_t, size_t> beams;
  size_t splits = 0;

  // Helper function to create or add to a map entry.
  auto create_or_add = [](std::map<size_t, size_t>& m, size_t key, size_t value) {
    if (m.contains(key)) {
      m[key] += value;
    } else {
      m[key] = value;
    }
  };

  for (size_t row = 0; row < m_input.size(); ++row) {
    std::map<size_t, size_t> next_beams;
    for (size_t col = 0; col < m_input[row].size(); ++col) {
      if (m_input[row][col] == 'S') {
        next_beams.emplace(col, 1);
      } else if (m_input[row][col] == '^' && beams.contains(col)) {
        create_or_add(next_beams, col + 1, beams.at(col));
        create_or_add(next_beams, col - 1, beams.at(col));
        splits++;
      } else if (beams.contains(col)) {
        create_or_add(next_beams, col, beams.at(col));
      }
    }
    beams = next_beams;
  }
  if (part == Part::PART_1) {
    return std::to_string(splits);
  }
  size_t timelines = 0;
  for (const auto& [_, timeline] : beams) {
    timelines += timeline;
  }
  return std::to_string(timelines);
}
