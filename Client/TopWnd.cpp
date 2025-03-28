#include "TopWnd.h"

TopWnd::TopWnd(QWidget* p /*= nullptr*/) : QWidget(p)
{
    LogFunc;
    m_vLayout = new QVBoxLayout(this);
    m_vLayout->setContentsMargins(0, 0, 0, 0);
    m_vLayout->setSpacing(0);

    m_hLayout1 = new QHBoxLayout();

    m_hLayout1->setContentsMargins(0, 0, 0, 0);
    m_hLayout1->setSpacing(5);

    m_minBtn = new QPushButton(this);
    m_minBtn->setIcon(QPixmap("./img/minBtn_.png"));
    m_minBtn->setIconSize(QSize(20, 20));
    m_maxBtn = new QPushButton(this);
    m_maxBtn->setIcon(QPixmap("./img/normalBtn_.png"));
    m_maxBtn->setIconSize(QSize(20, 20));
    m_closeBtn = new QPushButton(this);
    m_closeBtn->setIcon(QPixmap("./img/closeBtn_.png"));
    m_closeBtn->setIconSize(QSize(20, 20));

    m_minBtn->setFixedSize(20, 20);
    m_maxBtn->setFixedSize(20, 20);
    m_closeBtn->setFixedSize(20, 20);

    // m_minBtn->setStyleSheet("");

    m_hLayout1->addStretch();
    m_hLayout1->addWidget(m_minBtn);
    m_hLayout1->addWidget(m_maxBtn);
    m_hLayout1->addWidget(m_closeBtn);

    m_hLayout1->setContentsMargins(0, 5, 0, 0);
    m_hLayout1->addSpacing(15);
    m_vLayout->addLayout(m_hLayout1);

    m_hLayout2 = new QHBoxLayout();
    m_hLayout2->setContentsMargins(0, 0, 0, 0);
    m_hLayout2->setSpacing(0);

    m_titleLabel = new QLabel(this);
    m_titleLabel->setFixedHeight(40);
    m_titleLabel->setFixedWidth(300);
    m_titleLabel->setText("苏果超市便民服务(234)");
    m_titleLabel->setAlignment(Qt::AlignLeft);

    QFont font;
    font.setPointSize(12);
    m_titleLabel->setFont(font);

    m_moreBtn = new QPushButton(this);
    m_moreBtn->setFixedSize(30, 30);
    m_moreBtn->setIcon(QPixmap("./img/more.png"));
    m_moreBtn->setIconSize(QSize(30, 30));

    m_hLayout2->addSpacing(30);
    m_hLayout2->addWidget(m_titleLabel);
    m_hLayout2->addStretch();
    m_hLayout2->addWidget(m_moreBtn);

    m_hLayout2->setContentsMargins(0, 0, 0, 0);
    m_hLayout2->addSpacing(15);
    m_vLayout->addLayout(m_hLayout2);

    setFixedHeight(65);
    setAttribute(Qt::WA_StyledBackground);
    setMouseTracking(true);
}
