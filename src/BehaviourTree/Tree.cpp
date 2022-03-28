#include "Tree.h"

BehaviourTree::Tree::Tree(Node *root) : root_(root) {}

void BehaviourTree::Tree::update(qint64 deltaTime) {
  if (root_)
    root_->evaluate(deltaTime);
}