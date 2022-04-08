#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "Node.h"

namespace BehaviourTree {
// only if all child nodes succeed, it succeeds
class Sequence : public Node {
public:
  Sequence(Node *parent = nullptr);
  Sequence(QList<Node *> children);
  NodeState evaluate(qint64 deltaTime) override;
};
} // namespace BehaviourTree

#endif // SEQUENCE_H
