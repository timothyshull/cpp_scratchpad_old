//
// Created by Timothy Shull on 12/5/15.
//

#ifndef CODINGINTERVIEW_TREENODE_H
#define CODINGINTERVIEW_TREENODE_H

template<typename T>
class TreeNode {
    TreeNode *left;
    TreeNode *right;
    T data;

public:
    TreeNode(const T &value) : left{nullptr}, right{nullptr}, data{value} { }

    ~TreeNode() { }

    void setLeft(TreeNode *node) { left = node; }

    TreeNode *getLeft() { return left; }

    void setRight(TreeNode *node) { right = node; }

    TreeNode *getRight() { return right; }

    void setValue(const T &value) { data = value; }

    int getValue() { return data; }

    TreeNode findNode(TreeNode root)

};


#endif //CODINGINTERVIEW_TREENODE_H
