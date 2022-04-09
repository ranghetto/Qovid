#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <QtGlobal>

namespace BehaviourTree {
class Tree {
public:
  Tree(Node *root = nullptr);
  ~Tree() = default;
  void update() const;

private:
  Node *root_;
};
} // namespace BehaviourTree

#endif // TREE_H