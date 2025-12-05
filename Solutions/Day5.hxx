#pragma once

#include "Day.hxx"

class Day5 : public Day {
public:
  explicit Day5();
  virtual ~Day5();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::pair<std::vector<std::pair<int64_t, int64_t>>, std::vector<int64_t>> m_input;
};
