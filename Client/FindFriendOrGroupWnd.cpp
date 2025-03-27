#include "SelfSplit.h"
#include "FindFriendItemWnd.h"
#include "FindFriendOrGroupWnd.h"
#include "NetClientUtils.h"
#include "./json/CJsonObject.hpp"
#include "StyleSheetMgr.h"

#include <QMessageBox>
#include <QMouseEvent>
#include <QListWidgetItem>
#include <QScrollBar>
#include <QHBoxLayout>

FindFriendOrGroupWnd::FindFriendOrGroupWnd(QWidget* p /*= nullptr*/) : QWidget(p)
{
    LogFunc;
    auto hLayout = new QHBoxLayout;
    hLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(hLayout);

    m_centerWnd = new QWidget(this);
    hLayout->addWidget(m_centerWnd);

    m_centerWnd->setObjectName("FindFriendOrGroupWnd");
    QStyleSheetObject object;
    object.m_qssFileName = "./stylesheet/" + m_centerWnd->objectName() + ".qss";
    object.m_widget = m_centerWnd;
    StyleSheetMgr::getMgr()->reg(object.m_qssFileName, object);

    m_vLayout = new QVBoxLayout(m_centerWnd);
    m_vLayout->setContentsMargins(0, 0, 0, 0);
    m_vLayout->setSpacing(0);
    m_centerWnd->setLayout(m_vLayout);


    m_topWnd = new TopWnd(this);
    m_topWnd->getMoreBtn()->hide();
    m_topWnd->setTitle("查找好友或者群");
    m_vLayout->addWidget(m_topWnd);

    {
        // split;
        SelfSplit* sp = new SelfSplit(this);
        m_vLayout->addWidget(sp);
    }

    m_vLayout->addSpacing(20);

    // hlayout;
    m_hLayout = new QHBoxLayout;
    m_hLayout->setContentsMargins(35, 35, 35, 35);
    m_hLayout->setSpacing(15);

    m_searchEdit = new QLineEdit;
    m_searchEdit->setFixedSize(280, 35);
    m_findPersonCheckBox = new QCheckBox();
    m_findPersonCheckBox->setText("找人");
    m_findGroupCheckBox = new QCheckBox();
    m_findGroupCheckBox->setText("找群");
    m_searchBtn = new QPushButton();
    m_searchBtn->setText("查找");
    m_searchBtn->setFixedSize(100, 30);

    m_hLayout->addWidget(m_searchEdit);
    m_hLayout->addWidget(m_findPersonCheckBox);
    m_hLayout->addWidget(m_findGroupCheckBox);
    //m_hLayout->addSpacing(15);
    m_hLayout->addWidget(m_searchBtn);
    m_hLayout->addStretch();

    m_vLayout->addLayout(m_hLayout);

    // list widgets;
    auto m_hLayout2 = new QHBoxLayout;
    m_hLayout2->setContentsMargins(35, 0, 35, 0);

    m_listWidget = new QListWidget;
    m_listWidget->setStyleSheet("border:0px;");
    m_hLayout2->addWidget(m_listWidget);
    m_vLayout->addLayout(m_hLayout2);

    connect(m_searchBtn, SIGNAL(clicked()), this, SLOT(onSearchBtnClicked()));
}

void FindFriendOrGroupWnd::addFriendItem(const char* headUrl, const char* name, int64 userid)
{
    FindFriendItemWnd* pMsgItem = new FindFriendItemWnd(headUrl, name, userid, m_listWidget);
    QListWidgetItem* pListItem = new QListWidgetItem(m_listWidget);
    pListItem->setSizeHint(QSize(0, 60));
    m_listWidget->setItemWidget(pListItem, pMsgItem);
}

void FindFriendOrGroupWnd::onSearchBtnClicked()
{
    if (m_findPersonCheckBox->isChecked())
    {
        std::string findstr = m_searchEdit->text().toStdString();
        neb::CJsonObject json;
        json.Add("findstr", findstr);
        while (m_listWidget->count() > 0)
        {
            QListWidgetItem* pitem = m_listWidget->takeItem(0);
            delete pitem;
        }

        NetClientUtils::request("findUser", json, [this](neb::CJsonObject& msg) {
            ////解析注册消息数组；
            auto data = msg["data"];
            if (!data.IsArray())
            {
                return;
            }

            for (int i = 0; i < data.GetArraySize(); i++)
            {
                neb::CJsonObject jsonelem;
                data.Get(i, jsonelem);

                int64_t userid;
                if (!jsonelem.Get("userid", userid))
                {
                    return;
                }

                std::string username;
                if (!jsonelem.Get("username", username))
                {
                    return;
                }

                addFriendItem("./img/head2.png", username.c_str(), userid);
            }
        });
    }
}
