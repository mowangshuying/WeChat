#pragma once

#include "def.h"

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

#include "ApplyFriendNextWnd.h"

class FindFriendItemWnd : public QWidget
{
    Q_OBJECT
  public:
    FindFriendItemWnd(const QString& headUrl, const QString& username, qint64 userid, QWidget* parent = nullptr);
  public slots:
    void onAddFriendBtnClick();

  protected:
    QHBoxLayout* m_hLayout;
    QLabel* m_headImgLabel;
    QLabel* m_usernameLabel;
    QPushButton* m_addFriendBtn;
  
    qint64 m_userid;
    QString m_username;
    ApplyFriendNextWnd* m_nextWnd;
};