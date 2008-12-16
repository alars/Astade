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
#include "ComponentElement.h"

#include <QUuid>
#include <QDebug>
#include <QDir>
#include <QProcess>
#include <QSettings>

#include "Globals.h"
#include "ModelPropertyKeys.h"
#include "ElementFactory.h"
#include "AstadeDataModel.h"
#include "AstadeDataModelPrivate.h" // FIXME: Remove this as soon as possible
#include "FilesElement.h"
#include "ProcessView.h"

namespace
{
    const char* g_autoDirName   = "auto";
    const char* g_manualDirName = "manual";
    const char* g_classGroup    = "classes/";

}

ComponentElement::ComponentElement( QObject* parent ):
Element( parent ), m_pProcess( NULL )
{

}

bool ComponentElement::isEditable() const
{
    return true;
}

bool ComponentElement::isReferenceToExternalElement() const
{
    return false;
}

QList<QAction* > ComponentElement::supportedActions() const
{
    QList<QAction* > ret_list( Element::supportedActions() );
    bool is_process_running = m_pProcess ? (m_pProcess->state() == QProcess::Running) : false ;

    QAction* regenerate_action = new QAction( tr( "Regenerate All" ), NULL );
    regenerate_action->setEnabled( !is_process_running );
    ret_list.append( regenerate_action );
    connect( regenerate_action, SIGNAL( triggered() ), this, SLOT( slotRegenerate() ) );

    QAction* separator = new QAction( "", NULL );
    separator->setSeparator( true );
    ret_list << separator;

    QAction* stop_action     = new QAction( tr( "&Stop" ), NULL );
    stop_action->setEnabled( is_process_running );
    ret_list.append( stop_action );
    connect( stop_action, SIGNAL( triggered() ), this, SLOT( slotStopProcess() ) );

    return ret_list;
}

QString ComponentElement::toString( StringOutputRole stringRole) const
{
    Q_UNUSED( stringRole );
    return property( g_contextInfoElementNameKey ).toString();
}

QPixmap ComponentElement::decorationPixmap() const
{
    QPixmap pixmap;
    bool is_process_running = m_pProcess ? (m_pProcess->state() == QProcess::Running) : false ;

    if ( is_process_running )
    { pixmap.load( ":Elements/busy.png" ); }

    return pixmap;
}


void ComponentElement::initElementProperties()
{
    Element::initElementProperties();

    // This element contains other elements. Thus, it is constructed as container.
    setIsContainer( true );
    setFilePath( qobject_cast<Element*>( parent() )->filePath() + "/components_" + QString::number( QUuid::createUuid().data1 ) );
    setProperty( g_contextInfoElementNameKey, "New Component" );
    setProperty( g_contextInfoElementTypeKey, Elements::ET_FOLDER | Elements::ET_COMPONENT );

    // Create sub-elements
    FilesElement* auto_element   = qobject_cast<FilesElement*>( ElementFactory::self().newObject( Elements::ET_FILES, model() ) );
    FilesElement* manual_element = qobject_cast<FilesElement*>( ElementFactory::self().newObject( Elements::ET_FILES, model() ) );

    model()->addChildToElement( auto_element, model()->indexForElement( this ) );
    auto_element->initElementProperties();
    auto_element->setElementName( g_autoDirName );
    model()->addChildToElement( manual_element, model()->indexForElement( this ) );
    manual_element->initElementProperties();
    manual_element->setElementName( g_manualDirName );

    // Now save the current structure to disk
    model()->slotCommit( model()->indexForElement( this ) );
}

// Protected functions
QStringList ComponentElement::belongingClasses() const
{
    QList<QByteArray> properties = dynamicPropertyNames();
    qDebug() << "List of dynamic properties:" << properties;

    // Obtain all classes
    QList<QString> all_classes;

    foreach( QString class_name, properties )
    {
        if ( !class_name.toLower().startsWith( g_classGroup ) )
            continue;
        // Remove starting group name and strange garbage "|" chars.
        all_classes.append( class_name.mid( QString( g_classGroup ).count() ).remove( "|" ) );
    }
    qDebug() << "All classes:" << all_classes;

    return all_classes;
}

// Slots

// Generate Code for this component
// TODO: How to add new generators without changing this code?
// FIXME: This implementation needs low-level access..
void ComponentElement::slotRegenerate()
{
    QString cpp_coder_path        = Globals::self().cppCoder();
    QString statechart_coder_path = Globals::self().stateChartCoder();

    QString path_to_auto_dir  = model()->modelPath() + filePath() + "/" + g_autoDirName;
    QString path_to_component = model()->modelPath() + filePath() + "/" + AstadeDataModelPrivate::modelNodeContextFileName();
    qDebug() << "File-Path to component: " << path_to_component;

    // Cleanup auto dir
    QDir auto_dir( path_to_auto_dir );
    QStringList file_list = auto_dir.entryList( QStringList() << "*", QDir::Files );
    foreach( QString file, file_list )
    {
        if ( !file.endsWith( "ModelNode.ini" ) )
            auto_dir.remove( file );
    }

    QStringList all_classes = belongingClasses();

    if ( !m_pProcess )
    {
        m_pProcess = new QProcess(  ProcessView::self()  );
        connect( m_pProcess, SIGNAL( readyReadStandardOutput() ), this, SLOT( slotReadyReadStandardOutput() ) );
        connect( m_pProcess, SIGNAL( readyReadStandardError() ), this, SLOT( slotReadyReadStandardError() ) );
        connect( m_pProcess, SIGNAL( started() ), this, SLOT( slotProcessStarted() ) );
        connect( m_pProcess, SIGNAL( finished( int ) ), this, SLOT( slotProcessFinished() ) );
    }

    m_pProcess->setWorkingDirectory( model()->modelPath() );
    foreach( QString class_model_path, all_classes )
    {
        QSettings class_data( model()->modelPath() + class_model_path, QSettings::IniFormat );
        QString class_name = class_data.value( g_contextInfoElementNameKey, "" ).toString();

        if ( class_name.isEmpty() )
        { continue; }

        QStringList arguments;

        arguments << model()->modelPath() + class_model_path;
        arguments << path_to_auto_dir + "/" + class_name;
        arguments << path_to_component;

        // qDebug() << "Call: " << cpp_coder_path << "with arguments:" << arguments;
        m_pProcess->start( cpp_coder_path, arguments );
    }
}

void ComponentElement::slotStopProcess()
{
        m_pProcess->kill();
}

void ComponentElement::slotReadyReadStandardOutput()
{
        qDebug() << "regenerate stdout:" << m_pProcess->readAllStandardOutput();
}

void ComponentElement::slotReadyReadStandardError()
{
        qDebug() << "regenerate stderr:" << m_pProcess->readAllStandardError();
}

void ComponentElement::slotProcessStarted()
{
        model()->elementUpdated( this, false );
}

void ComponentElement::slotProcessFinished()
{
        model()->elementUpdated( this, true );
}
