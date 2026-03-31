#pragma once
#include <algorithm> // Để dùng std::copy và std::swap
#include <cstddef>

class FloatVector {
public:
  // --- Khởi tạo và Hủy (Thành viên 1 & 4) ---
  FloatVector() : _data(nullptr), _size(0), _capacity(4) {
    _data = new float[_capacity];
  }

  // Copy Constructor (Cần thiết để copy an toàn)
  FloatVector(const FloatVector &other)
      : _size(other._size), _capacity(other._capacity) {
    _data = new float[_capacity];
    std::copy(other._data, other._data + _size, _data);
  }

  ~FloatVector() { delete[] _data; }

  // --- Quản lý phần tử (Thành viên 1) ---
  void push(float n) {
    if (_size >= _capacity) {
      _realloc(_capacity * 2);
    }
    _data[_size++] = n;
  }

  float pop() {
    if (_size > 0) {
      return _data[--_size];
    }
    return 0.0f; // Hoặc xử lý lỗi tùy quy ước
  }

  // --- Truy cập và Gán (Thành viên 2) ---
  float &operator[](size_t idx) { return _data[idx]; }

  float operator[](size_t idx) const { return _data[idx]; }

  // Deep copy sử dụng Copy-and-Swap idiom để an toàn nhất
  FloatVector &operator=(FloatVector other) {
    std::swap(_size, other._size);
    std::swap(_capacity, other._capacity);
    std::swap(_data, other._data);
    return *this;
  }

  // --- Toán tử logic và tính toán (Thành viên 3) ---
  bool operator==(const FloatVector &other) const {
    if (_size != other._size)
      return false;
    for (size_t i = 0; i < _size; ++i) {
      if (_data[i] != other._data[i])
        return false;
    }
    return true;
  }

  FloatVector operator*(float n) const {
    FloatVector res = *this;
    for (size_t i = 0; i < res._size; ++i)
      res[i] *= n;
    return res;
  }

  FloatVector operator+(float n) const {
    FloatVector res = *this;
    for (size_t i = 0; i < res._size; ++i)
      res[i] += n;
    return res;
  }

  // --- Tiện ích bổ sung ---
  size_t get_size() const { return _size; }
  size_t get_capacity() const { return _capacity; }
  bool operator!=(const FloatVector &n) const { return !(*this == n); }
  FloatVector operator-(float n) const { return *this + (-n); }
  FloatVector operator/(float n) const { return *this * (1.0f / n); }

private:
  // --- Quản lý bộ nhớ (Thành viên 1) ---
  void _realloc(size_t new_cap) {
    if (new_cap <= _capacity)
      return;

    float *new_data = new float[new_cap];
    for (size_t i = 0; i < _size; ++i) {
      new_data[i] = _data[i];
    }

    delete[] _data;
    _data = new_data;
    _capacity = new_cap;
  }

  float *_data;
  size_t _size, _capacity;
};
