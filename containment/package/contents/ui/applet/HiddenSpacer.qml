/*
*  Copyright 2016  Smith AR <audoban@openmailbox.org>
*                  Michail Vourlakos <mvourlakos@gmail.com>
*
*  This file is part of Latte-Dock
*
*  Latte-Dock is free software; you can redistribute it and/or
*  modify it under the terms of the GNU General Public License as
*  published by the Free Software Foundation; either version 2 of
*  the License, or (at your option) any later version.
*
*  Latte-Dock is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

import QtQuick 2.1

Item{
    id: hiddenSpacer

    //we add one missing pixel from calculations
    width: root.isHorizontal ? nHiddenSize : wrapper.width
    height: root.isHorizontal ? wrapper.height : nHiddenSize

    ///check also if this is the first/last plasmoid in anylayout
    visible: (rightSpacer ? appletItem.endEdge : appletItem.startEdge) || separatorSpace>0

    property bool neighbourSeparator: false;

    property int separatorSpace: neighbourSeparator && !appletItem.isSeparator && !appletItem.latteApplet && root.zoomFactor>1 ? (2+root.lengthMargin) : 0

    property real nHiddenSize: {
        if (isSeparator || !communicator.lengthMarginsEnabled) {
            return 0;
        }

        return (nScale > 0) ? (appletItem.spacersMaxSize * nScale) + separatorSpace : separatorSpace
    }

    property bool rightSpacer: false

    property real nScale: 0

    Behavior on nHiddenSize {
        id: animatedBehavior
        enabled: !root.globalDirectRender || restoreAnimation.running
        NumberAnimation { duration: 3 * appletItem.animationTime }
    }

    Behavior on nHiddenSize {
        id: directBehavior
        enabled: !animatedBehavior.running
        NumberAnimation { duration: root.directRenderAnimationTime }
    }

    Connections{
        target: root
        onSeparatorsUpdated: updateNeighbour();
    }

    function updateNeighbour() {
        hiddenSpacer.neighbourSeparator = hiddenSpacer.rightSpacer ?
                    parabolicManager.isSeparator(index+1) : parabolicManager.isSeparator(index-1)
    }

    Loader{
        active: root.debugModeSpacers

        sourceComponent: Rectangle{
            width: !root.isVertical ? hiddenSpacer.width : 1
            height: !root.isVertical ? 1 : hiddenSpacer.height
            x: root.isVertical ? hiddenSpacer.width/2 : 0
            y: !root.isVertical ? hiddenSpacer.height/2 : 0

            border.width: 1
            border.color: "red"
            color: "transparent"
        }
    }
}
