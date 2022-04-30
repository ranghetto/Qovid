#include "Tree.h"

BehaviourTree::Tree::Tree(Node *root) : root_(root) {}

void BehaviourTree::Tree::update(const Simulation &s) const {
  if (root_)
    root_->evaluate(s);
}

BehaviourTree::Tree::~Tree() { delete root_; }