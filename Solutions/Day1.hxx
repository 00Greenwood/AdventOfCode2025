#pragma once

#include "Day.hxx"

class Day1 : public Day {
public:
  explicit Day1();
  virtual ~Day1();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<std::pair<char, int>> m_input;
};
