#include "QCustomListWidgetItem.h"

QCustomListWidgetItem::QCustomListWidgetItem(QListWidget* view /*= nullptr*/, int type /*= Type*/) : QListWidgetItem(view, type)
{
    LogFunc;
    m_sesId = 0;
}

int QCustomListWidgetItem::sesId() const
{
    return m_sesId;
}

void QCustomListWidgetItem::setSesId(int sesid)
{
    m_sesId = sesid;
}
