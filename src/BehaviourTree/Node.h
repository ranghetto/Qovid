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
  // Every "action" aka node has to be unique to de entity is chained with
  // or you risk to delete all nodes, even if are used by other entities
  Node(QList<Node *> children);
  Node(const Node &node) = delete;
  Node &operator=(const Node &node) = delete;
  virtual ~Node();

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