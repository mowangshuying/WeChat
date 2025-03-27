#pragma once

#include "def.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "json/CJsonObject.hpp"

class TopWnd : public QWidget
{
    // 添加消息映射支持
    Q_OBJECT
  public:
    // 会话窗口
    TopWnd(QWidget* p = nullptr);

    QPushButton* getMoreBtn()
    {
        return m_moreBtn;
    }

    QPushButton* getMinBtn()
    {
        return m_minBtn;
    }

    QPushButton* getMaxBtn()
    {
        return m_maxBtn;
    }

    QPushButton* getCloseBtn()
    {
        return m_closeBtn;
    }

    void setTitle(const QString& title)
    {
        m_titleLabel->setText(title);
    }

  protected:
    QVBoxLayout* m_vLayout;
    QHBoxLayout* m_hLayout1;
    QHBoxLayout* m_hLayout2;

    QPushButton* m_minBtn;
    QPushButton* m_maxBtn;
    QPushButton* m_closeBtn;

    QLabel* m_titleLabel;
    QPushButton* m_moreBtn;
};