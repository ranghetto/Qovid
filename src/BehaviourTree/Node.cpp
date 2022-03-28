#include "Node.h"

BehaviourTree::Node::Node(Node *parent) : parent_(parent) {}

BehaviourTree::Node::Node(QList<Node *> children) {
  for (auto child : children) {
    addNode(child);
  }
}

BehaviourTree::Node::~Node() {
  for (auto child : children_) {
    delete child;
  }
}

void BehaviourTree::Node::addNode(Node *node) {
  node->parent_ = this;
  children_.append(node);
}