#pragma once
#include <cstdint>
#include <cstddef>

class FloatVector {
public:
        // Thanh vien 1
        void push(float n);
        float pop();

        // Thanh vien 2
        float &operator[](size_t idx);
        float operator[](size_t idx) const;

        // Thanh vien 3
        bool operator==(const FloatVector&) const;
        FloatVector operator*(float n) const;
        FloatVector operator+(float n) const;

        // Thanh vien 4 (neu co)
        ~FloatVector();
        size_t get_size() const;
        size_t get_capacity() const;

        FloatVector operator-(float n) const;
        FloatVector operator/(float n) const;
private:
        // Thanh vien 1
        void _realloc(size_t new_size);

        float *_data;
        size_t _size, _capacity;
};

