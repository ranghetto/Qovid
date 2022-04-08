#include "Selector.h"

BehaviourTree::Selector::Selector(Node *parent) : Node(parent) {}

BehaviourTree::Selector::Selector(QList<Node *> children) : Node(children) {}

BehaviourTree::NodeState BehaviourTree::Selector::evaluate() {
  for (auto child : children_) {

    NodeState childState = child->evaluate();

    if (childState == NodeState::SUCCESS) {
      state_ = childState;
      return childState;
    }

    if (childState == NodeState::RUNNING) {
      state_ = childState;
      return childState;
    }
  }

  state_ = NodeState::FAILURE;
  return state_;
};
