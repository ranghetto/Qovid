#include "Selector.h"

BehaviourTree::Selector::Selector(Node *parent) : Node(parent) {}

BehaviourTree::Selector::Selector(QList<Node *> children) : Node(children) {}

BehaviourTree::NodeState BehaviourTree::Selector::evaluate(qint64 deltaTime) {
  for (auto child : children_) {

    NodeState childState = child->evaluate(deltaTime);

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
