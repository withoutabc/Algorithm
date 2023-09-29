#include <iostream>

// 链表节点结构
struct Node {
    int data;      // 存储数据的整数
    Node* next;    // 指向下一个节点的指针
    
    // 构造函数，用于创建新节点
    Node(int value) : data(value), next(nullptr) {}
};

// 链表类
class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    // 在链表末尾添加节点
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;  // 如果链表为空，将新节点设置为头节点
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;  // 否则，遍历链表找到末尾，将新节点连接到末尾
        }
    }

    // 在链表指定位置插入节点
    void insert(int value, int position) {
        Node* newNode = new Node(value);
        if (position == 0) {
            newNode->next = head;  // 如果位置为0，将新节点设置为新的头节点
            head = newNode;
        } else {
            Node* current = head;
            int currentPosition = 0;
            while (current && currentPosition < position - 1) {
                current = current->next;
                currentPosition++;
            }
            if (!current) {
                std::cerr << "Position out of range." << std::endl;
                return;
            }
            newNode->next = current->next;  // 将新节点连接到当前位置的节点后面
            current->next = newNode;
        }
    }

    // 从链表中删除指定值的节点
    void remove(int value) {
        if (!head) {
            std::cerr << "List is empty." << std::endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;  // 如果头节点包含要删除的值，删除头节点并释放内存
            return;
        }

        Node* current = head;
        while (current->next) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;  // 如果下一个节点包含要删除的值，删除该节点并释放内存
                return;
            }
            current = current->next;
        }

        std::cerr << "Value not found in the list." << std::endl;
    }

    // 打印链表中的所有元素
    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    Node* head;  // 链表的头节点指针
};

int main() {
    LinkedList myList;

    myList.append(1);
    myList.append(2);
    myList.append(3);

    myList.print(); // 输出: 1 2 3

    myList.insert(4, 1); // 在位置1插入值4
    myList.print(); // 输出: 1 4 2 3

    myList.remove(2); // 删除值为2的节点
    myList.print(); // 输出: 1 4 3

    return 0;
}