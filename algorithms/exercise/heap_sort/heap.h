#include <vector>

template <typename T>
class Heap {
public:
  static void sort(std::vector<T>& data, bool ascending = true) {
    makeHeap(data, ascending);

    for (int i = data.size() - 1; i >= 1; --i) {
      std::swap(data[0], data[i]);
      heapify(data.data(), i, 0, ascending);
    }
  }

private:
  static void makeHeap(std::vector<T>& data, bool is_max_heap) {
    for (int i = data.size() / 2 - 1; i >= 0; --i) {
      // heapify the list from button to up.
      heapify(data.data(), data.size(), i, is_max_heap);
    }
  }

  static void heapify(T* data, size_t length, size_t i, bool is_max_heap) {
    if (!length) return;

    int left = (i << 1) + 1;
    int right = (i << 1) + 2;
    int cur_node = i;

    if (is_max_heap) {
      if (left < length && data[left] > data[cur_node]) cur_node = left;
      if (right < length && data[right] > data[cur_node]) cur_node = right;
    } else {
      if (left < length && data[left] < data[cur_node]) cur_node = left;
      if (right < length && data[right] < data[cur_node]) cur_node = right;
    }

    if (cur_node != i) {
      std::swap(*(data + i), *(data + cur_node));
      heapify(data, length, cur_node, is_max_heap);
    }
  }
};
