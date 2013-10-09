import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0

ApplicationWindow {
    title: qsTr("Manga Reading Assistant")

    statusBar: StatusBar {
    RowLayout {
        Label {
            id: status
            }
        }
    }

    width: 369
    height: 166
}
