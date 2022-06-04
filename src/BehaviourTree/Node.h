#ifndef NODE_H
#define NODE_H

#include <QList>
#include <QtGlobal>

// Incomplete type
class Simulation;

namespace BehaviourTree {
enum NodeState { RUNNING, SUCCESS, FAILURE };
class Node {
public:
  Node(Node *parent = nullptr);
  Node(QList<Node *> children);
  virtual ~Node() = 0;

  virtual NodeState evaluate(const Simulation &s) = 0;

  void setParent(Node *parent);

protected:
  NodeState state_;
  Node *parent_;
  QList<Node *> children_;

private:
  void addNode(Node *node);
  void deleteChildrens();
};
} // namespace BehaviourTree

#endif // NODE_H