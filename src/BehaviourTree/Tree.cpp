#include "Tree.h"

BehaviourTree::Tree::Tree(Node *root) : root_(root) {}

void BehaviourTree::Tree::update() {
  if (root_)
    root_->evaluate();
}