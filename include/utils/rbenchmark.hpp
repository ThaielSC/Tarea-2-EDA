#include <iostream>
#include <string>
#include <vector>

class RBenchmark {
  std::string name;
  std::vector<int> result;

 public:
  RBenchmark(std::string name) : name(name) {};
  void add(double);
  void show(std::ostream& os = std::cout) const;
};
