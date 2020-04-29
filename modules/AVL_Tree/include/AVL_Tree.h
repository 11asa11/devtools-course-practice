// Copyright 2020 Myshkin Andrey
#ifndef MODULES_AVL_TREE_INCLUDE_AVL_TREE_H_
#define MODULES_AVL_TREE_INCLUDE_AVL_TREE_H_

#include <utility>
#include <random>

enum Status
{
    STATUS_WAR_NODE_NOT_FOUND = 1,
    STATUS_OK = 0,
    STATUS_ERR_NULL_PTR_ROOT = -1,
    // STATUS_ERR_NODE_NOT_FOUND = -2
};

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

    // For work with Node
    int BFactor(Node* top);
    void fixHeight(Node* top);

    // Balance
    Node* rotateRight(Node* top);  // ������ ������� ������ top
    Node* rotateLeft(Node* top);  // ����� ������� ������ top
    Node* Balance(Node* top);  // ������������ ���� top

    Node* Insert(Node* top, const int& key_);  // ������� ����� k � ������ � ������ top

    Node* FindMin(Node* top);  // ����� ���� � ����������� ������ � ������ top
    Node* FindMax(Node* top);  // ����� ���� � ������������ ������ � ������ top

    // Delete
    Node* RemoveMin(Node* top);  // �������� ���� � ����������� ������ �� ������ top
    Node* Remove(Node* top, const int& key_);  // �������� ����� key_ �� ������ top
public:
    AVL_Tree();

    Node* InitRoot(const int& key_); // Init RootNode

    Node* GetRootNode();  // Get functions
    int GetRootKey();
    int GetHeight(Node* top);
    Node* GetLeftSubtree(Node* top);
    Node* GetRightSubtree(Node* top);
    int GetKey(Node* top);
  
    int FindMin();
    int FindMax();

    Status Insert(const int& key_);
    Status Remove(const int& key_);
    Status FindNode(const int& key_);
};

#endif  // MODULES_AVL_TREE_INCLUDE_AVL_TREE_H_
