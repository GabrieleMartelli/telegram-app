/*
    Copyright (C) 2014 Aseman
    http://aseman.co

    This project is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This project is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ASEMANDRAGOBJECT_H
#define ASEMANDRAGOBJECT_H

#include <QObject>
#include <QQuickItem>
#include <QImage>

class AsemanMimeData;
class AsemanDragObjectPrivate;
class AsemanDragObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(AsemanMimeData* mimeData READ mimeData WRITE setMimeData NOTIFY mimeDataChanged)
    Q_PROPERTY(int dropAction READ dropAction WRITE setDropAction NOTIFY dropActionChanged)
    Q_PROPERTY(QQuickItem* source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(QUrl image READ image WRITE setImage NOTIFY imageChanged)
    Q_PROPERTY(QPoint hotSpot READ hotSpot WRITE setHotSpot NOTIFY hotSpotChanged)
    Q_PROPERTY(QImage imageData READ imageData WRITE setImageData NOTIFY imageDataChanged)

    Q_PROPERTY(bool dragging READ dragging NOTIFY draggingChanged)

public:
    AsemanDragObject(QObject *parent = 0);
    ~AsemanDragObject();

    void setMimeData(AsemanMimeData *mime);
    AsemanMimeData *mimeData() const;

    void setDropAction(int act);
    int dropAction() const;

    void setSource(QQuickItem *item);
    QQuickItem *source() const;

    void setImage(const QUrl & url);
    QUrl image() const;

    void setImageData(const QImage &img);
    QImage imageData() const;

    bool dragging() const;

    void setHotSpot(const QPoint &point);
    QPoint hotSpot() const;

public slots:
    int start();

signals:
    void mimeDataChanged();
    void dropActionChanged();
    void sourceChanged();
    void imageChanged();
    void hotSpotChanged();
    void draggingChanged();
    void imageDataChanged();

private:
    AsemanDragObjectPrivate *p;
};

#endif // ASEMANDRAGOBJECT_H
