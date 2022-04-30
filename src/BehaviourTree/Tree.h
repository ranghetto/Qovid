#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <QtGlobal>

// Incomplete type
class Simulation;

namespace BehaviourTree {
class Tree {
public:
  Tree(Node *root = nullptr);
  ~Tree();
  void update(const Simulation &s) const;

private:
  Node *root_;
};
} // namespace BehaviourTree

#endif // TREE_H