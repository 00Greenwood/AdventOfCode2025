#include "precompiled.hxx"

#include "Day4.hxx"

#include <Direction.hxx>
#include <Parser.hxx>

Day4::Day4() : Day(4) {
}

Day4::~Day4() {
}

void Day4::initialize() {
  parse(name(), m_input);
}

std::string Day4::solve(Part part) const {
  size_t free_rolls = 0;
  std::vector<std::vector<char>> grid = m_input;
  while (true) {
    std::vector<std::pair<int, int>> to_be_removed;
    for (const auto& [y, row] : std::views::enumerate(grid)) {
      for (const auto& [x, cell] : std::views::enumerate(row)) {
        if (cell != '@') {
          // Not a roll, skip!
          continue;
        }
        int surrounding_count = 0;
        for (const auto& direction : Direction::SURROUNDING) {
          int next_x = x + direction.x;
          int next_y = y + direction.y;
          if (next_y >= 0 && next_y < grid.size() && next_x >= 0 && next_x < grid[next_y].size() &&
              grid.at(next_y).at(next_x) == '@') {
            ++surrounding_count;
          }
        }
        if (surrounding_count < 4) {
          to_be_removed.push_back({x, y});
        }
      }
    }
    free_rolls += to_be_removed.size();
    if (part == PART_1) {
      // For part 1, we only do one iteration.
      break;
    }
    if (to_be_removed.empty()) {
      // No more can be removed.
      break;
    }
    for (const auto& [x, y] : to_be_removed) {
      grid[y][x] = '.';
    }
  }
  return std::to_string(free_rolls);
}
