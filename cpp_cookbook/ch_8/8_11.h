//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_8_11_H
#define CPP_COOKBOOK_8_11_H

#include <string>

template<typename T>
class TreeNode {
public:
    TreeNode(const T& val) : val_{val}, left_{nullptr}, right_{nullptr} { }

    virtual ~TreeNode() {
        delete left_;
        delete right_;
    }

    T getVal() const {
        return val_;
    }

    void setVal(const T& val) {
        val_ = val;
    }

    void addChild(TreeNode<T>* p) {
        const T& other = p->getVal();
        if (other > val_) if (right_)
            right_->addChild(p);
        else
            right_ = p;
        else if (left_)
            left_->addChild(p);
        else
            left_ = p;
    }

    const TreeNode<T>* getLeft() const {
        return left_;
    }

    const TreeNode<T>* getRight() const {
        return right_;
    }

private:
    T val_;
    TreeNode<T>* left_;
    TreeNode<T>* right_;
};

void testTemplate();

#endif //CPP_COOKBOOK_8_11_H
