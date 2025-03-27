#pragma once

#include "def.h"

#include <QWidget>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QCheckBox>
#include "TopWnd.h"

class FindFriendOrGroupWnd : public QWidget
{
    Q_OBJECT
  public:
    FindFriendOrGroupWnd(QWidget* p = nullptr);

    void addFriendItem(const char* headUrl, const char* name, int64 userid);
  public slots:
    void onSearchBtnClicked();

  public:
    QWidget* m_centerWnd;
    QVBoxLayout* m_vLayout;
    QHBoxLayout* m_hLayout;

    // top wnd;
    TopWnd* m_topWnd;

    QLineEdit* m_searchEdit;
    QCheckBox* m_findPersonCheckBox;
    QCheckBox* m_findGroupCheckBox;
    QPushButton* m_searchBtn;

    // list;
    QListWidget* m_listWidget;
};