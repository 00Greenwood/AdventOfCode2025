#include "precompiled.hxx"

#include "Day0.hxx"

#include <Parser.hxx>

Day0::Day0() : Day(0) {
}

Day0::~Day0() {
}

void Day0::initialize() {
  parse(name(), m_input);
}

std::string Day0::solve(Part) const {
  return m_input;
}
