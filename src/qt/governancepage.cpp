// Copyright (c) 2018 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "governancepage.h"
#include "ui_governancepage.h"

#include "activemasternode.h"
#include "clientmodel.h"
#include "masternode-sync.h"
#include "masternodeconfig.h"
#include "masternodeman.h"
#include "utilmoneystr.h"
#include "walletmodel.h"
#include "askpassphrasedialog.h"


#include "ui_interface.h"

#include <QMessageBox>
#include <QString>
#include <QTimer>
#include <QToolButton>
#include <QDesktopServices>

#include <QPoint>
#include <QSettings>
#include <QSignalMapper>
#include <QUrl>


GovernancePage::GovernancePage(QWidget* parent) : QWidget(parent),
                                                  ui(new Ui::GovernancePage),
                                                  clientModel(0),
                                                  walletModel(0)
{

    //QWidget.setCursor (self, QCursor)
    //.setCursor(QCursor(QtCore.Qt.PointingHandCursor))
    //QPushButton->setCursor
    //setCursor(Qt::PointingHandCursor);

    ui->setupUi(this);


    //LEFT

    pushButtonWebsite = new QPushButton("Project website", this);
    pushButtonWebsite->setMinimumSize(200, 8);
    pushButtonWebsite->setToolTip(tr("https://happyleaf.money"));
    ui->verticalLayoutPromo->addWidget(pushButtonWebsite);

    
    pushSupport = new QPushButton("Support", this);
    pushSupport->setMinimumSize(200, 8);
    ui->verticalLayoutPromo->addWidget(pushSupport);


    pushButtonExplorer = new QPushButton("Official block explorer", this);
    pushButtonExplorer->setMinimumSize(200, 8);
    pushButtonExplorer->setToolTip(tr("https://explorer.happyleaf.money"));
    ui->verticalLayoutPromo->addWidget(pushButtonExplorer);


    pushButtonGit = new QPushButton("Source code on GitHub", this);
    pushButtonGit->setMinimumSize(200, 8);
    pushButtonGit->setToolTip(tr("https://github.com/happyleaf-money"));
    ui->verticalLayoutPromo->addWidget(pushButtonGit);


    pushForum = new QPushButton("Official forum", this);
    pushForum->setMinimumSize(200, 8);
    pushForum->setToolTip(tr("https://forum.happyleaf.money"));
    ui->verticalLayoutPromo->addWidget(pushForum);


    connect(pushButtonWebsite, SIGNAL(clicked()), this, SLOT(openWebsiteUrl()));
    connect(pushButtonGit, SIGNAL(clicked()), this, SLOT(openGitUrl()));
    connect(pushButtonExplorer, SIGNAL(clicked()), this, SLOT(openExplorer()));
    connect(pushForum, SIGNAL(clicked()), this, SLOT(openForum()));    
    connect(pushSupport, SIGNAL(clicked()), this, SLOT(openSupport()));

    Discord = new QPushButton("Discord", this);
    Discord->setMinimumSize(200, 8);
    ui->verticalLayoutPromo->addWidget(Discord);

    Telegram = new QPushButton("Telegram", this);
    Telegram->setMinimumSize(200, 8);
    ui->verticalLayoutPromo->addWidget(Telegram);


    //RIGHT

    Twitter = new QPushButton("Twitter", this);
    Twitter->setMinimumSize(200, 8);
    ui->verticalLayoutPromoRight->addWidget(Twitter);


    Quora = new QPushButton("Quora", this);
    Quora->setMinimumSize(200, 8);
    ui->verticalLayoutPromoRight->addWidget(Quora);

    Facebook = new QPushButton("Facebook", this);
    Facebook->setMinimumSize(200, 8);
    ui->verticalLayoutPromoRight->addWidget(Facebook);

    YouTube = new QPushButton("YouTube", this);
    YouTube->setMinimumSize(200, 8);
    ui->verticalLayoutPromoRight->addWidget(YouTube);

    Reddit = new QPushButton("Reddit", this);
    Reddit->setMinimumSize(200, 8);
    ui->verticalLayoutPromoRight->addWidget(Reddit);

    NewsBlog = new QPushButton("News Blog", this);
    NewsBlog->setMinimumSize(200, 8);
    ui->verticalLayoutPromoRight->addWidget(NewsBlog);

    LinkedIn = new QPushButton("LinkedIn", this);
    LinkedIn->setMinimumSize(200, 8);
    ui->verticalLayoutPromoRight->addWidget(LinkedIn);


    connect(Discord, SIGNAL(clicked()), this, SLOT(openDiscord()));
    connect(Telegram, SIGNAL(clicked()), this, SLOT(openTelegram()));
    connect(Twitter, SIGNAL(clicked()), this, SLOT(openTwitter()));
    connect(Quora, SIGNAL(clicked()), this, SLOT(openQuora()));
    connect(Facebook, SIGNAL(clicked()), this, SLOT(openFacebook()));
    connect(YouTube, SIGNAL(clicked()), this, SLOT(openYouTube()));
    connect(Reddit, SIGNAL(clicked()), this, SLOT(openReddit()));
    connect(NewsBlog, SIGNAL(clicked()), this, SLOT(openNewsBlog()));
    connect(LinkedIn, SIGNAL(clicked()), this, SLOT(openLinkedIn()));



    pushBuyCoin = new QPushButton("Where to buy the coin?", this);
    pushBuyCoin->setMinimumSize(200, 8);
    ui->horizontalLayout_Header->addWidget(pushBuyCoin);
    connect(pushBuyCoin, SIGNAL(clicked()), this, SLOT(buyCoin()));


//verticalLayoutPromoRight

    /*
    Twitter +
	Facebook +
	LinkedIn
	YouTube +
	Telegram +
	Discord +
	Bitcoin Talk +
	Github +
	Reddit +
	Forum +
	News Blog +
	*/

}


void GovernancePage::openGitUrl()
{
    QDesktopServices::openUrl (QUrl("https://github.com/happyleaf-money"));
}

void GovernancePage::openWebsiteUrl()
{
    QDesktopServices::openUrl (QUrl("https://happyleaf.money"));
}

void GovernancePage::openExplorer()
{
    QDesktopServices::openUrl (QUrl("https://explorer.happyleaf.money"));
}

void GovernancePage::openForum()
{
    QDesktopServices::openUrl (QUrl("https://forum.happyleaf.money"));
}

void GovernancePage::openDiscord()
{
    QDesktopServices::openUrl (QUrl("https://discord.happyleaf.money"));
}

void GovernancePage::openTelegram()
{
    QDesktopServices::openUrl (QUrl("https://telegram.happyleaf.money"));
}

void GovernancePage::openTwitter()
{
    QDesktopServices::openUrl (QUrl("https://twitter.happyleaf.money"));
}

void GovernancePage::openQuora()
{
    QDesktopServices::openUrl (QUrl("https://quora.happyleaf.money"));
}

void GovernancePage::openFacebook()
{
    QDesktopServices::openUrl (QUrl("https://facebook.happyleaf.money"));
}

void GovernancePage::openYouTube()
{
    QDesktopServices::openUrl (QUrl("https://youtube.happyleaf.money"));
}

void GovernancePage::openReddit()
{
    QDesktopServices::openUrl (QUrl("https://reddit.happyleaf.money"));
}

void GovernancePage::openNewsBlog()
{
    QDesktopServices::openUrl (QUrl("https://blog.happyleaf.money"));
}

void GovernancePage::openLinkedIn()
{
    QDesktopServices::openUrl (QUrl("https://linkedin.happyleaf.money"));
}

void GovernancePage::openSupport()
{
    QDesktopServices::openUrl (QUrl("https://support.happyleaf.money"));
}

void GovernancePage::buyCoin()
{
    QDesktopServices::openUrl (QUrl("https://happyleaf.money/marketplaces"));
}

GovernancePage::~GovernancePage()
{
    delete ui;
}

void GovernancePage::setClientModel(ClientModel* model)
{
    this->clientModel = model;
}

void GovernancePage::setWalletModel(WalletModel* model)
{
    this->walletModel = model;
}

void GovernancePage::lockUpdating(bool lock)
{
    fLockUpdating = lock;
}
