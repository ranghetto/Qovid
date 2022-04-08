TEMPLATE = app
TARGET = Qovid
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Qt modules used by this application
QT += core gui widgets charts

# Input
SOURCES += src/main.cpp \
  src/AI/InfectActorsInRange.cpp \
  src/AI/Patrol.cpp \
  src/BehaviourTree/Node.cpp \
  src/BehaviourTree/Selector.cpp \
  src/BehaviourTree/Sequence.cpp \
  src/BehaviourTree/Tree.cpp \
  src/Controllers/Simulation.cpp \
  src/Controllers/World.cpp \
  src/Entities/Actor.cpp \
  src/Views/ContainerWidget.cpp \
  src/Views/InputWidget.cpp \
  src/Views/MainWindow.cpp \
  src/Views/SimulationView.cpp \

HEADERS += \
  src/AI/InfectActorsInRange.h \
  src/AI/Patrol.h \
  src/BehaviourTree/Node.h \
  src/BehaviourTree/Selector.h \
  src/BehaviourTree/Sequence.h \
  src/BehaviourTree/Tree.h \
  src/Controllers/Simulation.h \
  src/Controllers/World.h \
  src/Entities/Actor.h \
  src/Entities/Entity.h \
  src/Views/ContainerWidget.h \
  src/Views/InputWidget.h \
  src/Views/MainWindow.h \
  src/Views/SimulationView.h \
