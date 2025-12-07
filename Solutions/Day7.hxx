#pragma once

#include "Day.hxx"

class Day7 : public Day {
public:
  explicit Day7();
  virtual ~Day7();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<std::vector<char>> m_input;
};
