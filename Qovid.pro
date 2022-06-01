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
  src/AI/CheckAlive.cpp \
  src/AI/CheckInfected.cpp \
  src/AI/InfectActorsInRange.cpp \
  src/AI/Patrol.cpp \
  src/AI/RecoverDeath.cpp \
  src/BehaviourTree/Node.cpp \
  src/BehaviourTree/Sequence.cpp \
  src/BehaviourTree/Tree.cpp \
  src/Controllers/GraphHandler.cpp \
  src/Controllers/Timer.cpp \
  src/Controllers/Simulation.cpp \
  src/Controllers/World.cpp \
  src/Entities/Actor.cpp \
  src/Loggers/ActorsLogger.cpp \
  src/Views/Charts/AreaChart.cpp \
  src/Views/Charts/BarChart.cpp \
  src/Views/Charts/LineChart.cpp \
  src/Views/Charts/PieChart.cpp \
  src/Views/Charts/ScatterChart.cpp \
  src/Views/ChartsWidget.cpp \
  src/Views/ClockWidget.cpp \
  src/Views/ContainerWidget.cpp \
  src/Views/InputWidget.cpp \
  src/Views/MainWindow.cpp \
  src/Views/OldSimulation.cpp \
  src/Views/SimulationWidget.cpp \

HEADERS += \
  src/AI/CheckAlive.h \
  src/AI/CheckInfected.h \
  src/AI/InfectActorsInRange.h \
  src/AI/Patrol.h \
  src/AI/RecoverDeath.h \
  src/BehaviourTree/Node.h \
  src/BehaviourTree/Sequence.h \
  src/BehaviourTree/Tree.h \
  src/Controllers/GraphHandler.h \
  src/Controllers/Timer.h \
  src/Controllers/Simulation.h \
  src/Controllers/World.h \
  src/Entities/Actor.h \
  src/Entities/Entity.h \
  src/Loggers/ActorsLogger.h \
  src/Views/Charts/AreaChart.h \
  src/Views/Charts/BarChart.h \
  src/Views/Charts/LineChart.h \
  src/Views/Charts/LoggerChart.h \
  src/Views/Charts/PieChart.h \
  src/Views/Charts/ScatterChart.h \
  src/Views/ChartsWidget.h \
  src/Views/ClockWidget.h \
  src/Views/ContainerWidget.h \
  src/Views/InputWidget.h \
  src/Views/MainWindow.h \
  src/Views/OldSimulation.h \
  src/Views/SimulationWidget.h \
