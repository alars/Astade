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

#include "Globals.h"
#include "ModelPropertyKeys.h"
#include "ElementFactory.h"
#include "AstadeDataModel.h"
#include "FilesElement.h"

namespace  
{
    const char* g_autoDirName   = "auto";
    const char* g_manualDirName = "manual";
    const char* g_classGroup    = "classes/";
}

ComponentElement::ComponentElement( QObject* parent ):
Element( parent )
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

QList<QAction* > ComponentElement::supportedActions()
{
    QList<QAction* > ret_list( Element::supportedActions() );
    
    QAction* regenerate_action = new QAction( tr( "Regenerate All" ), NULL );
    ret_list.append( regenerate_action );
    connect( regenerate_action, SIGNAL( triggered() ), this, SLOT( slotRegenerate() ) );
    
    return ret_list;    
}

QString ComponentElement::toString( StringOutputRole stringRole) const
{
    Q_UNUSED( stringRole );
	return property( g_contextInfoElementNameKey ).toString();
}

void ComponentElement::initElementProperties()
{
    Element::initElementProperties();
    
    // This element contains other elements. Thus, it is constructed as container.
    setIsContainer( true );
    setFilePath( qobject_cast<Element*>( parent() )->filePath() + "/components_" + QUuid::createUuid().toString() );
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
// FIXME: This is implementation needs low-level access.. 
void ComponentElement::slotRegenerate() 
{
#if 0
    QString ccoder_path           = Globals::self().cCoder();
    QString cpp_coder_path        = Globals::self().cppCoder();
    QString statechart_coder_path = Globals::self().stateChartCoder();
    
    qDebug() << "File-Path to component: " << Globals::self().currentModel() + filePath();
    QString path_to_auto_dir = Globals::self().currentModel() + filePath() + "/" + g_autoDirName; // Is used a component name
    
    // Cleanup auto dir
    QDir auto_dir( path_to_auto_dir );
    QStringList file_list = auto_dir.entryList( QStringList() << "*", QDir::Files );
    foreach( QString file, file_list )
    {
        if ( !file.endsWith( "ModelNode.ini" ) )
            auto_dir.remove( file );
    }
    
    QStringList all_classes = belongingClasses();
    
    QProcess generate_process;
    foreach( QString class_model_path, all_classes )
    {
        QStringList arguments;
        
        arguments << Globals::self().currentModel() + class_model_path;
        arguments << Globals::self().currentModel() + path_to_auto_dir;

        qDebug() << "Call: " << cpp_coder_path << "with arguments:" << arguments;
        generate_process.start( cpp_coder_path, arguments );
        generate_process.waitForFinished();
    }
#endif
}

