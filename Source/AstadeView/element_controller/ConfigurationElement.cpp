/*
 * AstadeView
 * Copyright (C) 2008 Stefan Eilers
 *
 * Astade is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License V2
 * as published by the Free Software Foundation.
 *
 * Astade  is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St., Fifth Floor, Boston, MA 02110-1301, USA
 */
#include "ConfigurationElement.h"

#include <QUuid>
#include <QDebug>
#include <QProcess>
#include <QPixmap>

#include "Globals.h"
#include "AstadeDataModel.h"
#include "ModelPropertyKeys.h"

ConfigurationElement::ConfigurationElement( QObject* parent ):
Element( parent ), m_pProcess( NULL )
{
}

ConfigurationElement::~ConfigurationElement()
{
    delete m_pProcess;
}

bool ConfigurationElement::isEditable() const
{
    return true;
}

bool ConfigurationElement::isReferenceToExternalElement() const
{
    return false;
}

QList<QAction* > ConfigurationElement::supportedActions() const
{
    QList<QAction* > ret_list( Element::supportedActions() );

    bool is_process_running = m_pProcess ? (m_pProcess->state() == QProcess::Running) : false ;

    QAction* regenerate_action = new QAction( tr( "&Build" ), NULL );
    regenerate_action->setEnabled( !is_process_running );
    ret_list.append( regenerate_action );
    connect( regenerate_action, SIGNAL( triggered() ), this, SLOT( slotBuild() ) );

    QAction* Rebuild_action = new QAction( tr( "&Rebuild" ), NULL );
    Rebuild_action->setEnabled( !is_process_running );
    ret_list.append( Rebuild_action );
    connect( Rebuild_action, SIGNAL( triggered() ), this, SLOT( slotRebuild() ) );

    QAction* clean_action = new QAction( tr( "&Clean" ), NULL );
    clean_action->setEnabled( !is_process_running );
    ret_list.append( clean_action );
    connect( clean_action, SIGNAL( triggered() ), this, SLOT( slotClean() ) );

    QAction* separator = new QAction( "", NULL );
    separator->setSeparator( true );
    ret_list << separator;

    QAction* install_action = new QAction( tr( "&Install" ), NULL );
    install_action->setEnabled( !is_process_running );
    ret_list.append( install_action );
    connect( install_action, SIGNAL( triggered() ), this, SLOT( slotInstall() ) );

    QAction* run_action     = new QAction( tr( "R&un" ), NULL );
    run_action->setEnabled( !is_process_running );
    ret_list.append( run_action );
    connect( run_action, SIGNAL( triggered() ), this, SLOT( slotRun() ) );

    QAction* separator_2 = new QAction( "", NULL );
    separator_2->setSeparator( true );
    ret_list << separator_2;

    QAction* stop_action     = new QAction( tr( "&Stop" ), NULL );
    stop_action->setEnabled( is_process_running );
    ret_list.append( stop_action );
    connect( stop_action, SIGNAL( triggered() ), this, SLOT( slotStopProcess() ) );

    return ret_list;
}


void ConfigurationElement::initElementProperties()
{
    Element::initElementProperties();

    setIsContainer( true );

    setFilePath( qobject_cast<Element*>( parent() )->filePath() + "/Config_" + QString::number( QUuid::createUuid().data1 ) );
    setProperty( g_contextInfoElementNameKey, "New Configuration" );
    setProperty( g_contextInfoElementTypeKey, Elements::ET_FOLDER | Elements::ET_CONFIGURATION );

    // Save data.
    model()->slotCommit( model()->indexForElement( this ) );
}


QString ConfigurationElement::toString( StringOutputRole stringRole) const
{
    Q_UNUSED( stringRole );
    return property( g_contextInfoElementNameKey ).toString();
}

QPixmap ConfigurationElement::decorationPixmap() const
{
    QPixmap pixmap;
    bool is_process_running = m_pProcess ? (m_pProcess->state() == QProcess::Running) : false ;

    if ( is_process_running )
    { pixmap.load( ":Elements/busy.png" ); }

    return pixmap;
}

void ConfigurationElement::build( const QString& command, const QStringList& arguments )
{
    if ( !m_pProcess )
    {
        m_pProcess = new QProcess( this );
        connect( m_pProcess, SIGNAL( readyReadStandardOutput() ), this, SLOT( slotReadyReadStandardOutput() ) );
        connect( m_pProcess, SIGNAL( readyReadStandardError() ), this, SLOT( slotReadyReadStandardError() ) );
        connect( m_pProcess, SIGNAL( started() ), this, SLOT( slotProcessStarted() ) );
        connect( m_pProcess, SIGNAL( finished( int ) ), this, SLOT( slotProcessFinished() ) );
    }

    QString path_to_config_dir  = Globals::self().currentModel() + filePath();

    m_pProcess->setWorkingDirectory( path_to_config_dir );
    m_pProcess->start( command, arguments );
}

void ConfigurationElement::slotBuild()
{
    build( "make" );
}

void ConfigurationElement::slotRebuild()
{
    slotClean();
    build( "make" );
}

void ConfigurationElement::slotClean()
{
    build( "make", QStringList() << "clean" );
}

void ConfigurationElement::slotInstall()
{
    build( "make", QStringList() << "clean" );
}

void ConfigurationElement::slotRun()
{
    qDebug() << "ConfigurationElement::slotRun() not implemented!";
}

void ConfigurationElement::slotStopProcess()
{
    m_pProcess->kill();
}

void ConfigurationElement::slotReadyReadStandardOutput()
{
    qDebug() << "build stdout:" << m_pProcess->readAllStandardOutput();
}

void ConfigurationElement::slotReadyReadStandardError()
{
    qDebug() << "build stderr:" << m_pProcess->readAllStandardError();
}

void ConfigurationElement::slotProcessStarted()
{
    model()->elementUpdated( this );
}

void ConfigurationElement::slotProcessFinished()
{
    model()->elementUpdated( this );
}



