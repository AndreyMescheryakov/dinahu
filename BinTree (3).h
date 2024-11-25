#pragma once
#include <string>
#include <stack>
#include <iostream>

// ���� ������
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data);    // �����������
    ~Node();           // ����������

    void add(int data);       // ���������� ��������
    void print(int level);    // ������ ������
    void clear();             // ������� ������
};

// ������
struct BinTree {
    Node* root;

    BinTree();    // ����������� ������
    ~BinTree();   // ���������� ������

    void add(int data);          // ���������� ��������
    void print();                // ������ ������
    void clear();                // ������� ������
    void buildTree(const std::string& data); // ���������� ������ �� ������
};


