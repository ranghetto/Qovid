#include "Tree.h"

BehaviourTree::Tree::Tree(Node *root) : root_(root) {}

void BehaviourTree::Tree::update() const {
  if (root_)
    root_->evaluate();
}

BehaviourTree::Tree::~Tree() { delete root_; }