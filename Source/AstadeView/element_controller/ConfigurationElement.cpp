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

#include "Globals.h"
#include "AstadeDataModel.h"
#include "ModelPropertyKeys.h"

ConfigurationElement::ConfigurationElement( QObject* parent ):
Element( parent ), m_pProcess( NULL /* new QProcess( this ) */ )
{
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
    
    QAction* regenerate_action = new QAction( tr( "&Build" ), NULL );
    ret_list.append( regenerate_action );
    connect( regenerate_action, SIGNAL( triggered() ), this, SLOT( slotBuild() ) );

    QAction* rebuild_action = new QAction( tr( "&Rebuild" ), NULL );
    rebuild_action->setEnabled( false );
    ret_list.append( rebuild_action );

    QAction* install_action = new QAction( tr( "&Install" ), NULL );
    install_action->setEnabled( false );
    ret_list.append( install_action );

    QAction* run_action     = new QAction( tr( "R&un" ), NULL );
    run_action->setEnabled( false );
    ret_list.append( run_action );
    
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

void ConfigurationElement::slotBuild()
{
    if ( !m_pProcess )
    { 
        m_pProcess = new QProcess( this ); 
        connect( m_pProcess, SIGNAL( readyReadStandardOutput() ), this, SLOT( slotReadyReadStandardOutput() ) );
        connect( m_pProcess, SIGNAL( readyReadStandardError() ), this, SLOT( slotReadyReadStandardError() ) );
    }
    
    QString path_to_config_dir  = Globals::self().currentModel() + filePath();
    
    qDebug() << "Build in Dir: " << path_to_config_dir;
    
    m_pProcess->setWorkingDirectory( path_to_config_dir );
    
    QStringList arguments;
    
    m_pProcess->start( "make", arguments );
    m_pProcess->waitForFinished();
    
}

void ConfigurationElement::slotReadyReadStandardOutput()
{
    qDebug() << "build stdout:" << m_pProcess->readAllStandardOutput();
}

void ConfigurationElement::slotReadyReadStandardError()
{
    qDebug() << "build stderr:" << m_pProcess->readAllStandardError();
}


