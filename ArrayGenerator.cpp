#ifndef ARRAY_GENERATOR_H
#define ARRAY_GENERATOR_H

#include <vector>
#include <algorithm>
#include <random>

class ArrayGenerator {
public:
  // �����������, ���������������� ������������ ������ ������� � ������������ �������� ���������
  ArrayGenerator(int maxSize, int maxValue)
    : maxSize(maxSize), maxValue(maxValue), engine(rd()), dist(0, maxValue) {
    generateBaseArray();
  }

  // ����� ��� ��������� ���������� ������� ��������� �������
  std::vector<int> getRandomArray(int size) {
    return std::vector<int>(randomArray.begin(), randomArray.begin() + size);
  }

  // ����� ��� ��������� �������, ���������������� � �������� �������
  std::vector<int> getReversedArray(int size) {
    return std::vector<int>(reversedArray.begin(), reversedArray.begin() + size);
  }

  // ����� ��� ��������� ����� ���������������� �������
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
  int maxSize;                           // ������������ ������ �������
  int maxValue;                          // ������������ �������� ���������
  std::vector<int> randomArray;          // ������� ��������� ������
  std::vector<int> reversedArray;        // ������, ��������������� � �������� �������
  std::vector<int> sortedArray;          // ��������������� ������
  std::random_device rd;                 // �������� �����������
  std::mt19937 engine;                   // ��������� ��������� �����
  std::uniform_int_distribution<int> dist; // ������������� ��� ��������� ��������� �����

  // ����� ��� ��������� ������� ��������
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
