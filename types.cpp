#include <iostream>
#include <typeinfo>
#include <vector>

template <typename T> struct Type {
  static void print() {
    std::cout << "sizeof(" << typeid(T).name() << ") = " << sizeof(T)
              << " bytes" << '\n';
  }
};

// print vector size, capacity and max_size
void print_vec_info(const std::vector<int> &vec) {
  std::cout << "size " << vec.size() << ", capacity " << vec.capacity()
            << ", max_size " << vec.max_size() << '\n';
}

int main() {
  Type<int>::print();
  Type<bool>::print();
  Type<char>::print();

  std::vector<int> v;
  print_vec_info(v);

  for (int i = 0; i < 100; ++i)
    v.push_back(i);

  print_vec_info(v);

  return 0;
}
