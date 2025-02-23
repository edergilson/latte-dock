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

#ifndef WINDOWINFOWRAP_H
#define WINDOWINFOWRAP_H

// Qt
#include <QWindow>
#include <QIcon>
#include <QRect>
#include <QVariant>

namespace Latte {
namespace WindowSystem {

using WindowId = QVariant;

class WindowInfoWrap
{

public:
    WindowInfoWrap() noexcept
        : m_isValid(false)
        , m_isActive(false)
        , m_isMinimized(false)
        , m_isMaxVert(false)
        , m_isMaxHoriz(false)
        , m_isFullscreen(false)
        , m_isShaded(false)
        , m_isPlasmaDesktop(false)
        , m_isKeepAbove(false)
        , m_hasSkipTaskbar(false)
        , m_isOnAllDesktops(false)
        , m_isOnAllActivities(false) {
    }

    WindowInfoWrap(const WindowInfoWrap &o) noexcept
        : m_wid(o.m_wid)
        , m_geometry(o.m_geometry)
        , m_isValid(o.m_isValid)
        , m_isActive(o.m_isActive)
        , m_isMinimized(o.m_isMinimized)
        , m_isMaxVert(o.m_isMaxVert)
        , m_isMaxHoriz(o.m_isMaxHoriz)
        , m_isFullscreen(o.m_isFullscreen)
        , m_isShaded(o.m_isShaded)
        , m_isPlasmaDesktop(o.m_isPlasmaDesktop)
        , m_isKeepAbove(o.m_isKeepAbove)
        , m_hasSkipTaskbar(o.m_hasSkipTaskbar)
        , m_isOnAllDesktops(o.m_isOnAllDesktops)
        , m_isOnAllActivities(o.m_isOnAllActivities)
        , m_desktops(o.m_desktops)
        , m_activities(o.m_activities)
        , m_display(o.m_display) {
    }

    WindowInfoWrap(WindowInfoWrap &&o) noexcept
        : m_wid(o.m_wid)
        , m_geometry(o.m_geometry)
        , m_isValid(o.m_isValid)
        , m_isActive(o.m_isActive)
        , m_isMinimized(o.m_isMinimized)
        , m_isMaxVert(o.m_isMaxVert)
        , m_isMaxHoriz(o.m_isMaxHoriz)
        , m_isFullscreen(o.m_isFullscreen)
        , m_isShaded(o.m_isShaded)
        , m_isPlasmaDesktop(o.m_isPlasmaDesktop)
        , m_isKeepAbove(o.m_isKeepAbove)
        , m_hasSkipTaskbar(o.m_hasSkipTaskbar)
        , m_isOnAllDesktops(o.m_isOnAllDesktops)
        , m_isOnAllActivities(o.m_isOnAllActivities)
        , m_desktops(o.m_desktops)
        , m_activities(o.m_activities)
        , m_display(o.m_display) {
    }

    inline WindowInfoWrap &operator=(WindowInfoWrap &&rhs) noexcept;
    inline WindowInfoWrap &operator=(const WindowInfoWrap &rhs) noexcept;
    inline bool operator==(const WindowInfoWrap &rhs) const noexcept;
    inline bool operator<(const WindowInfoWrap &rhs) const noexcept;
    inline bool operator>(const WindowInfoWrap &rhs) const noexcept;

    inline bool isValid() const noexcept;
    inline void setIsValid(bool isValid) noexcept;

    inline bool isActive() const noexcept;
    inline void setIsActive(bool isActive) noexcept;

    inline bool isMinimized() const noexcept;
    inline void setIsMinimized(bool isMinimized) noexcept;

    inline bool isMaximized() const noexcept;

    inline bool isMaxVert() const noexcept;
    inline void setIsMaxVert(bool isMaxVert) noexcept;

    inline bool isMaxHoriz() const noexcept;
    inline void setIsMaxHoriz(bool isMaxHoriz) noexcept;

    inline bool isFullscreen() const noexcept;
    inline void setIsFullscreen(bool isFullscreen) noexcept;

    inline bool isShaded() const noexcept;
    inline void setIsShaded(bool isShaded) noexcept;

    inline bool isPlasmaDesktop() const noexcept;
    inline void setIsPlasmaDesktop(bool isPlasmaDesktop) noexcept;

    inline bool isKeepAbove() const noexcept;
    inline void setIsKeepAbove(bool isKeepAbove) noexcept;

    inline bool hasSkipTaskbar() const noexcept;
    inline void setHasSkipTaskbar(bool skipTaskbar) noexcept;

    inline bool isOnAllDesktops() const noexcept;
    inline void setIsOnAllDesktops(bool alldesktops) noexcept;

    inline bool isOnAllActivities() const noexcept;
    inline void setIsOnAllActivities(bool allactivities) noexcept;

    inline QRect geometry() const noexcept;
    inline void setGeometry(const QRect &geometry) noexcept;

    inline QString appName() const noexcept;
    inline void setAppName(const QString &appName) noexcept;

    inline QString display() const noexcept;
    inline void setDisplay(const QString &display) noexcept;

    inline QIcon icon() const noexcept;
    inline void setIcon(const QIcon &icon) noexcept;

    inline WindowId wid() const noexcept;
    inline void setWid(const WindowId &wid) noexcept;

    inline QStringList desktops() const noexcept;
    inline void setDesktops(const QStringList &desktops) noexcept;

    inline QStringList activities() const noexcept;
    inline void setActivities(const QStringList &activities) noexcept;

    inline bool isOnDesktop(const QString &desktop) const noexcept;
    inline bool isOnActivity(const QString &activity) const noexcept;

private:
    WindowId m_wid{0};
    QRect m_geometry;

    bool m_isValid : 1;
    bool m_isActive : 1;
    bool m_isMinimized : 1;
    bool m_isMaxVert : 1;
    bool m_isMaxHoriz : 1;
    bool m_isFullscreen : 1;
    bool m_isShaded : 1;
    bool m_isPlasmaDesktop : 1;
    bool m_isKeepAbove: 1;
    bool m_hasSkipTaskbar: 1;
    bool m_isOnAllDesktops: 1;
    bool m_isOnAllActivities: 1;

    QString m_appName;
    QString m_display;

    QIcon m_icon;

    QStringList m_desktops;
    QStringList m_activities;
};

// BEGIN: definitions
inline WindowInfoWrap &WindowInfoWrap::operator=(WindowInfoWrap &&rhs) noexcept
{
    m_wid = rhs.m_wid;
    m_geometry = rhs.m_geometry;
    m_isValid = rhs.m_isValid;
    m_isActive = rhs.m_isActive;
    m_isMinimized = rhs.m_isMinimized;
    m_isMaxVert = rhs.m_isMaxVert;
    m_isMaxHoriz = rhs.m_isMaxHoriz;
    m_isFullscreen = rhs.m_isFullscreen;
    m_isShaded = rhs.m_isShaded;
    m_isPlasmaDesktop = rhs.m_isPlasmaDesktop;
    m_isKeepAbove = rhs.m_isKeepAbove;
    m_hasSkipTaskbar = rhs.m_hasSkipTaskbar;
    m_isOnAllDesktops = rhs.m_isOnAllDesktops;
    m_isOnAllActivities = rhs.m_isOnAllActivities;
    m_display = rhs.m_display;
    m_desktops = rhs.m_desktops;
    m_activities = rhs.m_activities;
    return *this;
}

inline WindowInfoWrap &WindowInfoWrap::operator=(const WindowInfoWrap &rhs) noexcept
{
    m_wid = rhs.m_wid;
    m_geometry = std::move(rhs.m_geometry);
    m_isValid = rhs.m_isValid;
    m_isActive = rhs.m_isActive;
    m_isMinimized = rhs.m_isMinimized;
    m_isMaxVert = rhs.m_isMaxVert;
    m_isMaxHoriz = rhs.m_isMaxHoriz;
    m_isFullscreen = rhs.m_isFullscreen;
    m_isShaded = rhs.m_isShaded;
    m_isPlasmaDesktop = rhs.m_isPlasmaDesktop;
    m_isKeepAbove = rhs.m_isKeepAbove;
    m_hasSkipTaskbar = rhs.m_hasSkipTaskbar;
    m_isOnAllDesktops = rhs.m_isOnAllDesktops;
    m_isOnAllActivities = rhs.m_isOnAllActivities;
    m_display = rhs.m_display;
    m_desktops = rhs.m_desktops;
    m_activities = rhs.m_activities;
    return *this;
}

inline bool WindowInfoWrap::operator==(const WindowInfoWrap &rhs) const noexcept
{
    return m_wid == rhs.m_wid;
}

inline bool WindowInfoWrap::operator<(const WindowInfoWrap &rhs) const noexcept
{
    return m_wid < rhs.m_wid;
}

inline bool WindowInfoWrap::operator>(const WindowInfoWrap &rhs) const noexcept
{
    return m_wid > rhs.m_wid;
}

inline bool WindowInfoWrap::isValid() const noexcept
{
    return m_isValid;
}

inline void WindowInfoWrap::setIsValid(bool isValid) noexcept
{
    m_isValid = isValid;
}

inline bool WindowInfoWrap::isActive() const noexcept
{
    return m_isActive;
}

inline void WindowInfoWrap::setIsActive(bool isActive) noexcept
{
    m_isActive = isActive;
}

inline bool WindowInfoWrap::isMinimized() const noexcept
{
    return m_isMinimized;
}

inline void WindowInfoWrap::setIsMinimized(bool isMinimized) noexcept
{
    m_isMinimized = isMinimized;
}

inline bool WindowInfoWrap::isMaximized() const noexcept
{
    return m_isMaxVert || m_isMaxHoriz;
}

inline bool WindowInfoWrap::isMaxVert() const noexcept
{
    return m_isMaxVert;
}

inline void WindowInfoWrap::setIsMaxVert(bool isMaxVert) noexcept
{
    m_isMaxVert = isMaxVert;
}

inline bool WindowInfoWrap::isMaxHoriz() const noexcept
{
    return m_isMaxHoriz;
}

inline void WindowInfoWrap::setIsMaxHoriz(bool isMaxHoriz) noexcept
{
    m_isMaxHoriz = isMaxHoriz;
}

inline bool WindowInfoWrap::isFullscreen() const noexcept
{
    return m_isFullscreen;
}

inline void WindowInfoWrap::setIsFullscreen(bool isFullscreen) noexcept
{
    m_isFullscreen = isFullscreen;
}

inline bool WindowInfoWrap::isShaded() const noexcept
{
    return m_isShaded;
}

inline void WindowInfoWrap::setIsShaded(bool isShaded) noexcept
{
    m_isShaded = isShaded;
}

inline bool WindowInfoWrap::isPlasmaDesktop() const noexcept
{
    return m_isPlasmaDesktop;
}

inline void WindowInfoWrap::setIsPlasmaDesktop(bool isPlasmaDesktop) noexcept
{
    m_isPlasmaDesktop = isPlasmaDesktop;
}

inline bool WindowInfoWrap::isKeepAbove() const noexcept
{
    return m_isKeepAbove;
}

inline void WindowInfoWrap::setIsKeepAbove(bool isKeepAbove) noexcept
{
    m_isKeepAbove = isKeepAbove;
}

inline bool WindowInfoWrap::hasSkipTaskbar() const noexcept
{
    return m_hasSkipTaskbar;
}

inline void WindowInfoWrap::setHasSkipTaskbar(bool skipTaskbar) noexcept
{
    m_hasSkipTaskbar = skipTaskbar;
}

inline bool WindowInfoWrap::isOnAllDesktops() const noexcept
{
    return m_isOnAllDesktops;
}

inline void WindowInfoWrap::setIsOnAllDesktops(bool alldesktops) noexcept
{
    m_isOnAllDesktops = alldesktops;
}

inline bool WindowInfoWrap::isOnAllActivities() const noexcept
{
    return m_isOnAllActivities;
}

inline void WindowInfoWrap::setIsOnAllActivities(bool allactivities) noexcept
{
    m_isOnAllActivities = allactivities;
}

inline QString WindowInfoWrap::appName() const noexcept
{
    return m_appName;
}

inline void WindowInfoWrap::setAppName(const QString &appName) noexcept
{
    m_appName = appName;
}

inline QString WindowInfoWrap::display() const noexcept
{
    return m_display;
}

inline void WindowInfoWrap::setDisplay(const QString &display) noexcept
{
    m_display = display;
}

inline QIcon WindowInfoWrap::icon() const noexcept
{
    return m_icon;
}

inline void WindowInfoWrap::setIcon(const QIcon &icon) noexcept
{
    m_icon = icon;
}

inline QRect WindowInfoWrap::geometry() const noexcept
{
    return m_geometry;
}

inline void WindowInfoWrap::setGeometry(const QRect &geometry) noexcept
{
    m_geometry = geometry;
}

inline WindowId WindowInfoWrap::wid() const noexcept
{
    return m_wid;
}

inline void WindowInfoWrap::setWid(const WindowId &wid) noexcept
{
    m_wid = wid;
}

inline QStringList WindowInfoWrap::desktops() const noexcept
{
    return m_desktops;
}

inline void WindowInfoWrap::setDesktops(const QStringList &desktops) noexcept
{
    m_desktops = desktops;
}

inline QStringList WindowInfoWrap::activities() const noexcept
{
    return m_activities;
}

inline void WindowInfoWrap::setActivities(const QStringList &activities) noexcept
{
    m_activities = activities;
}
// END: definitions

inline bool WindowInfoWrap::isOnDesktop(const QString &desktop) const noexcept
{
    return m_isOnAllDesktops || m_desktops.contains(desktop);
}

inline bool WindowInfoWrap::isOnActivity(const QString &activity) const noexcept
{
    return m_isOnAllActivities || m_activities.contains(activity);
}


}
}

#endif // WINDOWINFOWRAP_H
