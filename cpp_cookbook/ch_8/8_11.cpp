//
// Created by Timothy Shull on 12/25/15.
//

#include "8_11.h"

void testTemplate() {
    TreeNode<std::string> node1{"frank"};
    TreeNode<std::string> node2{"larry"};
    TreeNode<std::string> node3{"bill"};

    node1.addChild(&node2);
    node1.addChild(&node3);
}
