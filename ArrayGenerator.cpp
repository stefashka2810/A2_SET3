#ifndef ARRAY_GENERATOR_H
#define ARRAY_GENERATOR_H

#include <vector>
#include <algorithm>
#include <random>

class ArrayGenerator {
public:
  //  онструктор, инициализирующий максимальный размер массива и максимальное значение элементов
  ArrayGenerator(int maxSize, int maxValue)
    : maxSize(maxSize), maxValue(maxValue), engine(rd()), dist(0, maxValue) {
    generateBaseArray();
  }

  // ћетод дл€ получени€ случайного массива заданного размера
  std::vector<int> getRandomArray(int size) {
    return std::vector<int>(randomArray.begin(), randomArray.begin() + size);
  }

  // ћетод дл€ получени€ массива, отсортированного в обратном пор€дке
  std::vector<int> getReversedArray(int size) {
    return std::vector<int>(reversedArray.begin(), reversedArray.begin() + size);
  }

  // ћетод дл€ получени€ почти отсортированного массива
  std::vector<int> getAlmostSortedArray(int size, int swaps = 10) {
    auto arr = sortedArray;
    arr.resize(size);
    for (int i = 0; i < swaps; ++i) {
      int idx1 = dist(engine) % size;
      int idx2 = dist(engine) % size;
      std::swap(arr[idx1], arr[idx2]);
    }
    return arr;
  }

private:
  int maxSize;                           // ћаксимальный размер массива
  int maxValue;                          // ћаксимальное значение элементов
  std::vector<int> randomArray;          // Ѕазовый случайный массив
  std::vector<int> reversedArray;        // ћассив, отсортированный в обратном пор€дке
  std::vector<int> sortedArray;          // ќтсортированный массив
  std::random_device rd;                 // »сточник случайности
  std::mt19937 engine;                   // √енератор случайных чисел
  std::uniform_int_distribution<int> dist; // –аспределение дл€ генерации случайных чисел

  // ћетод дл€ генерации базовых массивов
  void generateBaseArray() {
    randomArray.resize(maxSize);
    for (int& num : randomArray) {
      num = dist(engine);
    }
    sortedArray = randomArray;
    std::sort(sortedArray.begin(), sortedArray.end());
    reversedArray = sortedArray;
    std::reverse(reversedArray.begin(), reversedArray.end());
  }
};

#endif // ARRAY_GENERATOR_H
