#include "Node.h"

BehaviourTree::Node::Node(Node *parent) : parent_(parent) {}

BehaviourTree::Node::Node(QList<Node *> children) : parent_(nullptr) {
  for (auto child : children) {
    addNode(child);
  }
}

BehaviourTree::Node::~Node() { deleteChildrens(); }

void BehaviourTree::Node::setParent(Node *parent) { parent_ = parent; }

void BehaviourTree::Node::addNode(Node *node) {
  node->parent_ = this;
  children_.append(node);
}

void BehaviourTree::Node::deleteChildrens() {
  for (auto child : children_) {
    delete child;
  }
  children_.clear();
}
