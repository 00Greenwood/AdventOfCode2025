#pragma once

#include "Day.hxx"

class Day2 : public Day {
public:
  explicit Day2();
  virtual ~Day2();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<std::pair<int64_t, int64_t>> m_input;
};
