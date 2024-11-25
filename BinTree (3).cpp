#include "BinTree.h"

// Конструктор узла
Node::Node(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
}

// Деструктор узла
Node::~Node() {
    clear();
}

// Добавление элемента в дерево
void Node::add(int data) {
    if (data == this->data) {
        return;
    }
    if (data < this->data) {
        if (left == nullptr)
            left = new Node(data);
        else
            left->add(data);
    }
    else {
        if (right == nullptr)
            right = new Node(data);
        else
            right->add(data);
    }
}

// Печать дерева с отступами
void Node::print(int level) {
    if (left) {
        left->print(level + 1);
    }
    for (int i = 0; i < level; ++i)
        std::cout << "   "; // Отступы для отображения уровня
    std::cout << static_cast<char>(data) << std::endl; // Преобразуем ASCII в символ
    if (right) {
        right->print(level + 1);
    }
}

// Очистка узла и его поддеревьев
void Node::clear() {
    if (left) {
        delete left;
        left = nullptr;
    }
    if (right) {
        delete right;
        right = nullptr;
    }
}

// Конструктор дерева
BinTree::BinTree() {
    root = nullptr;
}

// Деструктор дерева
BinTree::~BinTree() {
    clear();
}

// Добавление элемента в дерево
void BinTree::add(int data) {
    if (!root) {
        root = new Node(data);
    }
    else {
        root->add(data);
    }
}

// Печать дерева
void BinTree::print() {
    if (!root) {
        std::cout << "Derevo empty\n";
    }
    else {
        root->print(0);
    }
}

// Очистка дерева
void BinTree::clear() {
    if (root) {
        root->clear();
        root = nullptr;
    }
}

// Построение дерева из строки
void BinTree::buildTree(const std::string& data) {
    int pos = 0;

    // Вспомогательная рекурсивная функция для построения дерева
    auto buildRecursive = [&](auto&& self, const std::string& data, int& pos) -> Node* {
        // Если достигли конца строки или встретили '*', возвращаем nullptr (пустой узел)
        if (pos >= data.size() || data[pos] == '*') {
            ++pos; // Пропускаем '*'
            return nullptr;
        }

        // Создаем новый узел с текущим символом
        Node* node = new Node(data[pos++]);

        // Рекурсивно создаем левое и правое поддеревья
        node->left = self(self, data, pos);
        node->right = self(self, data, pos);

        return node;
        };

    // Строим дерево, начиная с корня
    root = buildRecursive(buildRecursive, data, pos);
}
