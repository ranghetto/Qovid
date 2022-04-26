#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "Node.h"

// Incomplete type
class Simulation;

namespace BehaviourTree {
// only if all child nodes succeed, it succeeds
// if a node fails, rest of the sequence is not executed
class Sequence : public Node {
public:
  Sequence(Node *parent = nullptr);
  Sequence(QList<Node *> children);
  NodeState evaluate(const Simulation &s) override;
};
} // namespace BehaviourTree

#endif // SEQUENCE_H
