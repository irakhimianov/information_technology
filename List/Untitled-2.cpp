#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class Node {
    public:
        Node* pNext;
        T data;
        Node(T data = T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
};


template<typename T>
class SimpleList {
private:
    int list_size;
    Node<T>* list_head;

public:
	// Конструктор 
	SimpleList() {
		list_size = 0;
		list_head = nullptr;
	} 
	// Деструктор
	~SimpleList() {
		clear();
	} 
	// Операция квадратные скобочки
    T & operator[](const int index) {
		int counter = 0;
		Node<T>* current = this->list_head;
		while (current != nullptr) {
			if (counter == index) {
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}
	// Вставка элемента в конец
    void push_back(T data) {
		if (list_head == nullptr) {
			list_head = new Node<T>(data);
		}
		else {
			Node<T>* current = this->list_head;
			while (current->pNext != nullptr) {
				current = current->pNext;
			}
			current->pNext = new Node<T>(data);
		}
		list_size++;
	}
	// Вставка в начало
    void push_front(T data) {
		list_head = new Node<T>(data, list_head);
		list_size++;
	}
	// Удаление элемента
    void pop_front() {
		Node<T>* temp = list_head;
		list_head = list_head->pNext;
		delete temp;
		list_size--;
	}
	// Удаление элемента с конца
    void pop_back() {
		removeAt(list_size - 1);
	}
	// Вставка элемента в i позицию
    void insert(T data, int index) {
		if (index == 0) {
			push_front(data);
		}
		else {
			Node<T>* previous = this->list_head;
			for (int i = 0; i < index - 1; i++) {
				previous = previous->pNext;
			}
			Node<T>* newNode = new Node<T>(data, previous->pNext);
			previous->pNext = newNode;
			list_size++;
		}
	}
	// Удаление i позиции
    void removeAt(int index) {
		if (index == 0) {
			pop_front();
		}
		else {
			Node<T>* previous = this->list_head;
			for (int i = 0; i < index - 1; i++) {
				previous = previous->pNext;
			}
			Node<T>* toDelete = previous->pNext;
			previous->pNext = toDelete->pNext;
			delete toDelete;
			list_size--;
		}
	}
	// Очистка списка
    void clear() {
		while (list_size) {
			pop_front();
		}
	}
	// Размер списка
	int Getlist_size() { 
		return list_size; 
	} 


};

void Test1() {
	SimpleList<int> list;
	list.push_back(2);
	list.push_front(4);

	assert(list[0] == 4);
	assert(list[1] == 2);

	list.insert(123, 1);
	assert(list[1] == 123);

	assert(list.Getlist_size() == 3);

    for (int i = 0; i < list.Getlist_size(); i++){
        cout << list[i] << " ";
    }

    cout << endl;
    list.clear();
	assert(list.Getlist_size() == 0);
	cout << "Test1 OK" << endl;
}

void Test2() {
	SimpleList<int> list;
	for (int i = 0; i < 3; i++) {
		list.push_back(7 * (i + 1));
	}

	for (int i = 0; i < 3; i++) {
		assert(list[i] == 7 * (i + 1));
	}
	
	list.pop_back();
	list.pop_front();

	assert(list[0] == 14);

	list.push_back(28);

	list.removeAt(0);
	assert(list[0] == 28);

	assert(list.Getlist_size() == 1);

	// for (int i = 0; i < list.Getlist_size(); i++){
	// 	cout << list[i] << " ";
	// }

	list.clear();
	assert(list.Getlist_size() == 0);

	cout << "Test2 OK" << endl;
}


int main()
{
	Test1();
	Test2();
}
