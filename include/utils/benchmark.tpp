#ifndef BENCHMARK_TPP
#define BENCHMARK_TPP

template <typename Func, typename... Args>
void Benchmark::run(Func func, int repeat, Args&&... args) {
  results.clear();
  results.reserve(repeat);

  for (int i = 0; i < repeat; ++i) {
    auto start = std::chrono::high_resolution_clock::now();
    func(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    results.push_back(duration.count());
  }
}

#endif  // BENCHMARK_TPP
