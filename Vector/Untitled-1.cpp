#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <cmath>
using namespace std;

template <typename T>
    class SimpleVector {
        private:
            int vector_size;
            int vector_capacity;
            T* vector_data;
        public:
        SimpleVector() {
            vector_size = 0;
            vector_capacity = 0;
            vector_data = NULL;
        }
        
    SimpleVector(const SimpleVector<T>& a) {
        vector_size = a.vector_size;
        vector_capacity = vector_size;
        vector_data = NULL;
        if (vector_size != 0)
            vector_data = new T[vector_size];
        else
            vector_data = 0;
        for (int i = 0; i < vector_size; ++i)
            vector_data[i] = a.vector_data[i];
    }

    SimpleVector(int size) {
        vector_size = size;
        vector_capacity = size;
        if (size != 0)
            vector_data = new T[size];
        else
            vector_data = 0;
    }

    ~SimpleVector() {
        if (vector_data)
        delete[] vector_data;
    }

    void Resize(int size) {
        if (size > vector_capacity) {
            int new_capacity = max(size, vector_size * 2);
            T* new_data = new T[new_capacity];
            for (int i = 0; i < vector_size; ++i)
            new_data[i] = vector_data[i];
            delete[] vector_data;
            vector_data = new_data;
            vector_capacity = new_capacity;
        }
        vector_size = size;
    }

    void PushBack(T val) {
        // Resize(vector_size + 1);
        if (vector_size > vector_capacity) {
            int new_capacity = max(vector_size + 1, vector_size * 2);
            T* new_data = new T[new_capacity];
            for (int i = 0; i < vector_size; ++i)
                new_data[i] = vector_data[i];
            delete[] vector_data;
            vector_data = new_data;
            vector_capacity = new_capacity;
        }
        vector_data[vector_size - 1] = val;
    }

    int Size() const { return vector_size; }
    int Capacity() const { return vector_capacity; }
    T* begin() const { return vector_data; }
    T* end() const { return vector_data + vector_size; }
    T& operator[] (int i) { return vector_data[i]; }
};


void Test_size() {
    vector<int> vector1 = {0, 0, 0, 0};
    for (int i = 0; i < vector1.size(); i++) {
        cout << vector1[i] << "; ";
    }
    cout << endl;
    cout << endl;
    cout << "Size = " << vector1.size() << endl;
    assert(vector1.size() == 4);
    cout << "Test_size successfull" << endl;
    cout << endl;
}


void Test_capacity() {
    SimpleVector<int> vector1(4);
    cout << "Capacity = " << vector1.Capacity() << endl;
    assert(vector1.Capacity() == 4);
    cout << "Test_capacity successfull" << endl;
    cout << endl;
}


void Test_copy() {
    SimpleVector<int> vector1(4);
    SimpleVector<int> vector2(vector1);
    cout << "Size1 = " << vector1.Size() << endl;
    cout << "Size2 = " << vector2.Size() << endl;
    cout << "Capacity1 = " << vector1.Capacity() << endl;
    cout << "Capacity2 = " << vector2.Capacity() << endl;
    assert(vector1.Size() == vector2.Size());
    assert(vector1.Capacity() == vector2.Capacity());
    cout << "Test_copy successfull" << endl;
    cout << endl;
}


void Test_pushback() {
    vector<int> vector1 = {0, 0, 0, 0};
    cout << "Size_izn = " << vector1.size() << endl;
    cout << "Capacity_izn = " << vector1.capacity() << endl;
    vector1.push_back(15);
    for (int i = 0; i < vector1.size(); i++) {
        cout << vector1[i] << "; ";
    }
    cout << endl;
    cout << "Size = " << vector1.size() << endl;
    cout << "Capacity = " << vector1.capacity() << endl;
    assert(vector1[4] == 15);
    assert(vector1.size() == 5);
    assert(vector1.capacity() == 8);
    cout << "Test_pushback successfull" << endl;
    cout << endl;
}


void Test_beginend() {
    vector<int> vector1(5);
    vector<int> vector2 = {2, 4, 8, 16, 32};
    int j = 1;
    for (auto i = vector1.begin(); i != vector1.end(); i++) {
        *i = pow(2, j);
        j++;
    }
    cout << endl;
    cout << "vector1: " << endl;
    for (int i = 0; i < vector1.size(); i++) {
        cout << vector1[i] << "; ";
    }
    cout << endl;
    cout << "vector2: " << endl;
    for (int i = 0; i < vector2.size(); i++) {
        cout << vector2[i] << "; ";
    }
    assert(vector1 == vector2);
    cout << endl;
    cout << "Test_beginend successfull" << endl;
    cout << endl;
}


int main() {
    setlocale(LC_ALL, "ru");
    Test_size();
    Test_capacity();
    Test_copy();
    Test_pushback();
    Test_beginend();
    return 0;
}