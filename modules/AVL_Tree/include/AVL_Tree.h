// Copyright 2020 Myshkin Andrey

#ifndef MODULES_AVL_TREE_INCLUDE_AVL_TREE_H_
#define MODULES_AVL_TREE_INCLUDE_AVL_TREE_H_

#include <utility>
#include <random>

struct Node {
    int key;
    int height;
    Node* leftNode;
    Node* rightNode;
    Node(int key_) { key = key_; height = 1; leftNode = rightNode = nullptr; }
};


class AVL_Tree{
private:
    Node* RootNode;

    int BFactor(Node* top);
    void fixHeight(Node* top);
public:
    AVL_Tree();
    // AVL_Tree(int key_);

    Node* GetRootNode();  // Get functions
    int GetRootKey();
    int GetHeight(Node* top);
    Node* GetLeftSubtree(Node* top);
    Node* GetRightSubtree(Node* top);
    int GetKey(Node* top);

    // Balance
    Node* rotateRight(Node* top);  // ������ ������� ������ top
    Node* rotateLeft(Node* top);  // ����� ������� ������ top
    Node* Balance(Node* top);  // ������������ ���� top

    Node* Insert(Node* top, int& key_);  // ������� ����� k � ������ � ������ p

    // Delete
    Node* FindMin(Node* top);  // ����� ���� � ����������� ������ � ������ p
    Node* AVL_Tree::FindMax(Node* top);  // ����� ���� � ������������ ������ � ������ p
    Node* RemoveMin(Node* top);  // �������� ���� � ����������� ������ �� ������ p
    Node* Remove(Node* top, int& key_);  // �������� ����� k �� ������ p

    // Dop func
    int FindMin();
    int FindMax();

};


#endif  // MODULES_AVL_TREE_INCLUDE_AVL_TREE_H_
