#ifndef SORT_TESTER_H
#define SORT_TESTER_H

#include <vector>
#include <chrono>
#include <functional>

class SortTester {
public:
  // ћетод дл€ тестировани€ времени работы сортировки
  template<typename SortFunction>
  long long testSort(SortFunction sortFunc, std::vector<int> arr) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(arr, 0, arr.size() - 1);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    return std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
  }
};

#endif // SORT_TESTER_H

