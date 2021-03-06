#include "house.h"

#include <QDebug>

House::House()
{
    addRoom("test");
}

void House::addRoom(const QString &roomName)
{
    QStringList out;
    out= rooms();
    bool isOkay= out.contains(roomName);
    bool isempty = roomName.isEmpty();
    if (isOkay == false && isempty== false)
        {
        m_rooms.push_back(new Room{roomName, this});

            m_modelRooms.push_back(m_rooms.at(m_rooms.size() -1));

            emit roomsChanged();
        }
    else{

    }
   
}

QStringList House::rooms() const
{
    QStringList out;
    for(int i = 0; i < m_rooms.size(); ++i){
        out << m_rooms.at(i)->name();
    }
    return out;
}

QList<QObject *> House::modelRooms() const
{
    return m_modelRooms;
}


        
