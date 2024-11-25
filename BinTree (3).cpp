#include "BinTree.h"

// ����������� ����
Node::Node(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
}

// ���������� ����
Node::~Node() {
    clear();
}

// ���������� �������� � ������
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

// ������ ������ � ���������
void Node::print(int level) {
    if (left) {
        left->print(level + 1);
    }
    for (int i = 0; i < level; ++i)
        std::cout << "   "; // ������� ��� ����������� ������
    std::cout << static_cast<char>(data) << std::endl; // ����������� ASCII � ������
    if (right) {
        right->print(level + 1);
    }
}

// ������� ���� � ��� �����������
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

// ����������� ������
BinTree::BinTree() {
    root = nullptr;
}

// ���������� ������
BinTree::~BinTree() {
    clear();
}

// ���������� �������� � ������
void BinTree::add(int data) {
    if (!root) {
        root = new Node(data);
    }
    else {
        root->add(data);
    }
}

// ������ ������
void BinTree::print() {
    if (!root) {
        std::cout << "Derevo empty\n";
    }
    else {
        root->print(0);
    }
}

// ������� ������
void BinTree::clear() {
    if (root) {
        root->clear();
        root = nullptr;
    }
}

// ���������� ������ �� ������
void BinTree::buildTree(const std::string& data) {
    int pos = 0;

    // ��������������� ����������� ������� ��� ���������� ������
    auto buildRecursive = [&](auto&& self, const std::string& data, int& pos) -> Node* {
        // ���� �������� ����� ������ ��� ��������� '*', ���������� nullptr (������ ����)
        if (pos >= data.size() || data[pos] == '*') {
            ++pos; // ���������� '*'
            return nullptr;
        }

        // ������� ����� ���� � ������� ��������
        Node* node = new Node(data[pos++]);

        // ���������� ������� ����� � ������ ����������
        node->left = self(self, data, pos);
        node->right = self(self, data, pos);

        return node;
        };

    // ������ ������, ������� � �����
    root = buildRecursive(buildRecursive, data, pos);
}
