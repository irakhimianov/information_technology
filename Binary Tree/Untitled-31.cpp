#include <iostream>
 
class Node {
public:
    int m_data;
    Node* m_left;
    Node* m_right;
    Node(int val) {
        m_left = NULL;
        m_right = NULL;
        m_data = val;
    }
};
 
class BinaryTree {
public:
	// конструктор
	BinaryTree(int key) {
	    m_root = new Node(key);
	    m_size = 1;
	}

	// деструктор
	~BinaryTree() {
	    delete_tree(m_root);
	}

	// вывод
	void print() {
	    print_tree(m_root, 0);
	    std::cout <<'\n';
	}

	// поиск
	bool find(int key) {
	    Node* curr = m_root;
	    while (curr && curr->m_data != key) {
	        if (curr->m_data > key) curr = curr->m_left;
	        else curr = curr->m_right;
	    }
	    return curr != NULL;
	}

	// добавление
	void insert(int key) {
	    Node* curr = m_root; 
	    while (curr && curr->m_data != key){
	        if (curr->m_data > key && curr->m_left == NULL) {
	            curr->m_left = new Node(key);
	            ++m_size;
	            return;
	        }
	        if (curr->m_data < key && curr->m_right == NULL) {
	            curr->m_right = new Node(key);
	            ++m_size;
	            return;
	        }
	        if (curr->m_data > key) curr = curr->m_left;
	        else curr = curr->m_right;
	    }
	}

	// удаление
	void erase(int key) {
	    Node* curr = m_root;
	    Node* parent = NULL;
	    while (curr && curr->m_data != key){
	        parent = curr;
	        if (curr->m_data > key){
	            curr = curr->m_left;
	        }
	        else {
	            curr = curr->m_right;
	        }
	    }
	    if (!curr) return;
	    if (curr->m_left == NULL){
	        if (parent && parent->m_left == curr) parent->m_left = curr->m_right;
	        if (parent && parent->m_right == curr) parent->m_right = curr->m_right;
	        --m_size;
	        delete curr;
	        return;
	    }
	    if (curr->m_right == NULL) {
	        if (parent && parent->m_left == curr) parent->m_left = curr->m_left;
	        if (parent && parent->m_right == curr) parent->m_right = curr->m_left;
	        --m_size;
	        delete curr;
	        return;
	    }
	    Node* replace = curr->m_right;
	    while (replace->m_left) replace = replace->m_left;
	    int replace_value = replace->m_data;
	    erase(replace_value);
	    curr->m_data = replace_value;
	}

	
    int size() { 
		return m_size; 
	}
	
private:
    Node* m_root;
    int m_size;
	
	void print_tree(Node* p, int lvl) {
	    if (p) {
	        print_tree(p->m_left, lvl + 1);
	        for (int i = 0; i < lvl; i++) std::cout << " ";
	        std::cout << p->m_data;
	        print_tree(p->m_right, lvl + 1);
	    }
	}
	
	void delete_tree(Node* curr) {
	    if (curr) {
	        delete_tree(curr->m_left);
	        delete_tree(curr->m_right);
	        delete curr;
	    }
	}
};
 
 
int main() {
    setlocale(LC_ALL, "ru");
    int val;
    std::cout << "Vvedite kornevoe znachenie uzla dereva:\n>";
    std::cin >> val;
    BinaryTree tr(val);
    int choice;
    
 
    while (true) {
        std::cout << "Vvedite:\n1 - dlya dobavleniya uzlov v derevo\n2 - dlya udaleniya uzla iz dereva\n3 - dlya poiska uzla iz dereva\n4 - dlya vivoda dereva\n0 - vihod iz programmi\n>";
        
        std::cin >> choice;
        if (choice == 1) {
            if (tr.size() == 0) {
                std::cout << "Vvedite kornevoe znachenie uzla dereva:\n>";
                std::cin >> val;
                BinaryTree tr(val);
            }
            std::cout << "Znachenie uzlov cherez probel, -1 dlya konca vvoda:\n>";
            int temp;
            while (true) {
                std::cin >> temp;
                if (temp != -1)  tr.insert(temp);
                else break;
            }
            std::cout << "\n";
        }
        else if (choice == 2) {
            int temp;
            std::cout << "Vvedite uzel dlya udaleniya:\n>";
            std::cin >> temp;
            if (tr.find(temp)) tr.erase(temp);
            else std::cout << "Takoi uzel na naiden\n";
            std::cout << "\n";
        }
        else if (choice == 3) {
            int temp;
            std::cout << "Vvedite uzel dlya poiska:\n>";
            std::cin >> temp;
            if (tr.find(temp)) std::cout << "uzel " << temp << " naiden\n";
            else std::cout << "uzel " << temp << " ne naiden\n";
            std::cout << "\n";
        }
        else if (choice == 4) {
            if (tr.size() == 0) std::cout << "V dereve net entov\n";
            else tr.print();
            std::cout << "\n";
        }
        else if (choice == 0) {
            return 0;
        }
        else std::cout << "Nekorrektniy vvod\n\n";
    }
}
