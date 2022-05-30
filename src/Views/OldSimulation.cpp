#include "OldSimulation.h"
#include "../Controllers/GraphHandler.h"

OldSimulation::OldSimulation(QWidget *parent) : QWidget(parent) {
  QVBoxLayout *layout = new QVBoxLayout(this);
  refresh_ = new QPushButton(this);
  list_ = new QListWidget(this);
  refresh_->setText("Aggiorna Lista");
  layout->addWidget(refresh_);
  layout->addWidget(list_);
  setLayout(layout);
}

void OldSimulation::getHandler(GraphHandler *controller) {
  controller_ = controller;
  connect(list_, SIGNAL(itemDoubleClicked(QListWidgetItem *)), controller_,
          SLOT(showGraph(QListWidgetItem *)));
  connect(refresh_, SIGNAL(clicked()), this, SLOT(Refresh()));
}

void OldSimulation::Refresh() {
  list_->clear();
  controller_->PopulateOldSimulation(controller_->getCurrentDirectory());
}

void OldSimulation::NewWidgetItemAdder(const QString name) {
  QListWidgetItem *item = new QListWidgetItem(list_);
  item->setSizeHint(QSize(item->sizeHint().width(), 20));
  item->setText(name);
}
