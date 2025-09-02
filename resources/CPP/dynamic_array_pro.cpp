#include <iostream>

using namespace std;

template <typename T>
class DynamicArray {
    private:
        T* data; // 储存T类型数据的数组
        size_t size; // 当前元素的数量
        size_t capacity; // 当前分配的容量

        // 扩容（私有方法）
        void resize(size_t new_capacity) {
            T* new_data = new T[new_capacity]
            for (size_t i = 0; i < size; i++) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        
};
