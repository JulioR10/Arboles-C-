#include "tree.h"
#include <algorithm>

// Constructor for an empty tree
Tree::Tree() {}

// Constructor for a tree with the root node
Tree::Tree(const TipoDato& dato) {
    root = std::make_shared<ElementoArbol>(ElementoArbol{dato});
}

void Tree::add_subtree(const Tree& subtree) {
    if (subtree.root != nullptr) {
        root->children.push_back(subtree.root);
    }
}

int _height(std::shared_ptr<ElementoArbol> element) {
    if (element->children.empty()) {
        return 0;
    }else{
        int height = 0;
        for (auto child: element->children) {
            height = std::max(height, _height(child));
        }
        return 1 + height;
    }
}

int Tree::height() const {
    return _height(root);
}

int _size(std::shared_ptr<ElementoArbol> element) {
    int n_nodes = 1;
    for (auto child: element->children) {
        n_nodes += _size(child);
    }
    return n_nodes;
}

int Tree::size() const {
    return _size(root);
}

void _dfs_preorder(std::shared_ptr<ElementoArbol> root,
                   std::function<void (TipoDato&)> action) {
    action(root->dato);
    for (auto child: root->children) {
        _dfs_preorder(child, action);
    }
}

void Tree::dfs_preorder(std::function<void (TipoDato&)> action) const {
    _dfs_preorder(root, action);
}
/*
void dfs_preorder_iterativo(std::shared_ptr<ElementoArbol> root, std::function<void (TipoDato&)> action) {
    Stack stack;  // You can reuse your Stack.h
    stack.push(root);

    while(!stack.empty()) {
        auto elem = stack.top();
        stack.pop();
        action(elem->dato);
        // Iterate backwards
        for (auto it = elem->children.rbegin(); it != elem->children.rend(); it++) {
            stack.push(*it);
        }
    }
}*/

void _dfs_postorder(std::shared_ptr<ElementoArbol> root, std::function<void (TipoDato&)> action) {
    for (auto child: root->children) {
        _dfs_postorder(child, action);
    }
    action(root->dato);
}

void Tree::dfs_postorder(std::function<void (TipoDato&)> action) const {
    _dfs_postorder(root, action);
}

void _dfs_inorder(std::shared_ptr<ElementoArbol> root, std::function<void (TipoDato&)> action) {
    if (!root->children.empty()) {
        _dfs_inorder(root->children[0], action);
    }
    action(root->dato);

    for (int i=1; i<root->children.size(); i++) {
        _dfs_inorder(root->children[i], action);
    }
}

void Tree::dfs_inorder(std::function<void (TipoDato&)> action) const {
    _dfs_inorder(root, action);
}
/*
void Tree::bfs(std::function<void (TipoDato&)> action) const {
    Queue queue;  // We need a queue!
    queue.push(root);
    while (!queue.empty()) {
        QueueTipoDato elem = queue.front();
        queue.pop();
        action(elem->dato);
        for (auto child: elem->children) {
            queue.push(QueueTipoDato{child});
        }
    }
}
*/
