#include "precompiled.hxx"
#include "Solutions/Day0.hxx"
#include "Solutions/Day1.hxx"
#include "Solutions/Day2.hxx"

int main(int, char**) {
  auto mutex = std::make_shared<std::mutex>();

  std::vector<std::unique_ptr<Day>> days;
  days.push_back(std::make_unique<Day0>());
  days.push_back(std::make_unique<Day1>());
  days.push_back(std::make_unique<Day2>());

  for (const auto& day : days) {
    day->solve(mutex);
  }

  for (const auto& day : days) {
    day->wait();
  }

  return 0;
}
