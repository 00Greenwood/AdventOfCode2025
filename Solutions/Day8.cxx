#include "precompiled.hxx"

#include "Day8.hxx"

#include <Parser.hxx>

Day8::Day8() : Day(8) {
}

Day8::~Day8() {
}

void Day8::initialize() {
  parse(name(), m_input);
}

std::string Day8::solve(Part part) const {
  std::map<long double, std::pair<Position3D, Position3D>> distances;
  for (size_t i = 0; i < m_input.size(); ++i) {
    for (size_t j = i + 1; j < m_input.size(); ++j) {
      long double dist = m_input[i].distance(m_input[j]);
      distances[dist] = {m_input[i], m_input[j]};
    }
  }
  std::vector<std::set<Position3D>> connected;
  size_t count = 0;
  long double last_connection = 0;
  for (const auto& [dist, pairs] : distances) {
    const auto& [first, second] = pairs;
    std::set<Position3D>* first_found_group = nullptr;
    std::set<Position3D>* second_found_group = nullptr;
    for (auto& group : connected) {
      if (group.contains(first) || group.contains(second)) {
        if (!first_found_group) {
          first_found_group = &group;
        } else if (!second_found_group) {
          second_found_group = &group;
        } else {
          throw std::runtime_error("More than two groups found for positions");
        }
      }
    }
    if (!first_found_group && !second_found_group) {
      connected.push_back({first, second});
    } else if (first_found_group && !second_found_group) {
      first_found_group->insert(first);
      first_found_group->insert(second);
    } else if (first_found_group != second_found_group) {
      first_found_group->insert(second_found_group->begin(), second_found_group->end());
      connected.erase(std::remove(connected.begin(), connected.end(), *second_found_group), connected.end());
    }
    if (connected.size() == 1 && connected[0].size() == m_input.size()) {
      last_connection = first.x * second.x;
      break;
    }
    if (part == PART_1 && ++count >= 1000) {
      break;
    }
  }
  // Sort connected groups by size descending
  std::sort(connected.begin(), connected.end(),
            [](const std::set<Position3D>& a, const std::set<Position3D>& b) { return a.size() > b.size(); });
  size_t total = 1;
  for (size_t i = 0; i < 3; ++i) {
    total *= connected[i].size();
  }
  if (part == PART_1) {
    return std::to_string(total);
  }
  return std::to_string(last_connection);
}
