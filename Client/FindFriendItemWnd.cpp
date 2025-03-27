#include "FindFriendItemWnd.h"
#include "StyleSheetMgr.h"

FindFriendItemWnd::FindFriendItemWnd(const QString& headUrl, const QString& username, qint64 userid, QWidget* parent /* = nullptr*/) 
    : QWidget(parent), m_username(username), m_userid(userid)
{
    LogFunc;
    setObjectName("FindFriendItemWnd");
    QStyleSheetObject object;
    object.m_qssFileName = "./stylesheet/" + objectName() + ".qss";
    object.m_widget = this;
    StyleSheetMgr::getMgr()->reg(object.m_qssFileName, object);

    m_hLayout = new QHBoxLayout;
    m_hLayout->setContentsMargins(0, 0, 0, 0);
    m_hLayout->setSpacing(0);
    setLayout(m_hLayout);

    m_headImgLabel = new QLabel;
    m_headImgLabel->setPixmap(QPixmap(headUrl));
    m_headImgLabel->setFixedSize(40, 40);
    
    m_usernameLabel = new QLabel;
    m_usernameLabel->setText(username);

    //m_hLayout->addSpacing(50);
    m_hLayout->addWidget(m_headImgLabel);
    m_hLayout->addWidget(m_usernameLabel);

    m_hLayout->addStretch();
    m_addFriendBtn = new QPushButton;
    m_addFriendBtn->setText("添加");
    m_addFriendBtn->setFixedSize(60, 30);
    
    m_hLayout->addWidget(m_addFriendBtn);

    setFixedHeight(60);
    connect(m_addFriendBtn, SIGNAL(clicked()), this, SLOT(onAddFriendBtnClick()));
}

void FindFriendItemWnd::onAddFriendBtnClick()
{
    m_nextWnd = new ApplyFriendNextWnd(nullptr, m_userid, m_username);
    m_nextWnd->show();
}
