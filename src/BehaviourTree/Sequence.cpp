#include "Sequence.h"

BehaviourTree::Sequence::Sequence(Node *parent) : Node(parent) {}

BehaviourTree::Sequence::Sequence(QList<Node *> children) : Node(children) {}

BehaviourTree::NodeState BehaviourTree::Sequence::evaluate() {
  bool childrenRunning = false;

  for (auto child : children_) {
    NodeState childState = child->evaluate();
    if (childState == NodeState::FAILURE) {
      state_ = childState;
      return childState;
    }

    if (childState == NodeState::RUNNING)
      childrenRunning = true;
  }

  state_ = childrenRunning ? NodeState::RUNNING : NodeState::SUCCESS;
  return state_;
};
