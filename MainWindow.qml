// SPDX-License-Identifier: GPL-3.0-only
import QtQuick
import QtQuick.Controls
import QtQuick.TreeView
import Qt.labs.folderlistmodel

ApplicationWindow {
    width: 400
    height: 300
    visible: true

    TreeView {
        anchors.fill: parent

        FolderListModel {
             id: folderModel
        }

        Component {
            id: fileDelegate
            Label { x: 8; text: fileName }
        }

        model: folderModel
        delegate: fileDelegate
    }
}
