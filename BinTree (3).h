#pragma once
#include <string>
#include <stack>
#include <iostream>

// Узел дерева
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data);    // Конструктор
    ~Node();           // Деструктор

    void add(int data);       // Добавление элемента
    void print(int level);    // Печать дерева
    void clear();             // Очистка дерева
};

// Дерево
struct BinTree {
    Node* root;

    BinTree();    // Конструктор дерева
    ~BinTree();   // Деструктор дерева

    void add(int data);          // Добавление элемента
    void print();                // Печать дерева
    void clear();                // Очистка дерева
    void buildTree(const std::string& data); // Построение дерева из строки
};


