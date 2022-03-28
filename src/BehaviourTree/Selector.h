#ifndef SELECTOR_H
#define SELECTOR_H

#include "Node.h"

namespace BehaviourTree {
// only if all child nodes succeed, it succeeds
class Selector : Node {
public:
  Selector(Node *parent = nullptr);
  Selector(QList<Node *> children);
  NodeState evaluate(qint64 deltaTime) override;
};
} // namespace BehaviourTree

#endif // SELECTOR_H