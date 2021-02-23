// SPDX-License-Identifier: GPL-3.0-only
#include <QQmlEngine>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  // Required to find the QML plugin.
  engine.addImportPath("qml");

  engine.load(QUrl("qrc:/MainWindow.qml"));
  if (engine.rootObjects().empty()) {
    return 1;
  }

  return QGuiApplication::exec();
}
