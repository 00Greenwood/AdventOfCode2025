#include "Day2.hxx"
#include "precompiled.hxx"

#include <Parser.hxx>

namespace {
  bool hasRepeatingChunks(const std::string& str, size_t chunk_size) {
    size_t len = str.size();
    if (len % chunk_size != 0) {
      return false;
    }
    
    // Check if all chunks are identical to the first chunk
    for (size_t pos = chunk_size; pos < len; pos += chunk_size) {
      for (size_t i = 0; i < chunk_size; i++) {
        if (str[i] != str[pos + i]) {
          return false;
        }
      }
    }
    return true;
  }
}

Day2::Day2() : Day(2) {
}

Day2::~Day2() {
}

void Day2::initialize() {
  parse(name(), m_input);
}

std::string Day2::solve(Part part) const {
  int64_t result = 0;
  for (const auto& [min, max] : m_input) {
    for (int64_t number = min; number <= max; number++) {
      std::string as_string = std::to_string(number);
      size_t len = as_string.size();
      
      // Skip if string is too short to split
      if (len < 2) {
        continue;
      }
      
      // Part 1: Only check chunk_size = len/2 (exactly 2 repeating halves)
      // Part 2: Check all possible chunk sizes from len/2 down to 1
      size_t min_chunk_size = (part == PART_1) ? len / 2 : 1;
      
      for (size_t chunk_size = len / 2; chunk_size >= min_chunk_size; chunk_size--) {
        if (hasRepeatingChunks(as_string, chunk_size)) {
          result += number;
          break;
        }
      }
    }
  }
  return std::to_string(result);
}
