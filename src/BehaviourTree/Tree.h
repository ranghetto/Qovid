#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <QDebug>
#include <QtGlobal>

namespace BehaviourTree {
class Tree {
public:
  Tree(Node *root = nullptr);
  ~Tree();
  void update() const;

private:
  Node *root_;
};
} // namespace BehaviourTree

#endif // TREE_H