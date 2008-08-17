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
#include "PropertyEditor.h"

#include <QDebug>
#include <QMetaProperty>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QVariant>
#include <QStringList>

// TODO: Use input widgets regarding to the data type displayed. And improve the type awareness..

PropertyEditor::PropertyEditor( QWidget* parent, Qt::WindowFlags f ): QWidget( parent, f )
{
    
}

void PropertyEditor::setObject( QObject* object )
{
    m_pProcessedObject = object;
    updateView();
}


void PropertyEditor::updateView()
{
    Q_ASSERT( m_pProcessedObject );
    
    m_inputWidgets.clear();
    
    // First get a list of public properties, if possible.
    QStringList public_properties;
    int index = m_pProcessedObject->metaObject()->indexOfProperty( "publicProperties" );
    if ( -1 != index )
    {
        public_properties = m_pProcessedObject->metaObject()->property( index ).read( m_pProcessedObject ).toStringList();
    }
    
    // Request all properties and create view for it.
    QGridLayout* grid_layout = new QGridLayout( this );
    
    int number_of_properties = m_pProcessedObject->metaObject()->propertyCount();
    int row = 0;
    
    // Show static properties
    for ( int i = 0; i < number_of_properties; ++i )
    {
        QMetaProperty property = m_pProcessedObject->metaObject()->property( i );
        if ( !property.isReadable() )
            continue;
        
        // Ignore all properties that are not in the list of public ones. But just
        // if the list isn't empty.
        if ( !public_properties.isEmpty() )
        {
            if ( !public_properties.contains( property.name() ) )
            { continue; }
        }
        
        // Ignore all properties that are black listed
        if ( m_ignoredProperties.contains( property.name() ) )
        { continue; }
        
        grid_layout->addWidget( new QLabel( property.name(), this ), row, 0 );

        QLineEdit* editor_widget = new QLineEdit( this );
        QVariant variant_property = property.read( m_pProcessedObject );
        editor_widget->setText( variant_property.toString() );
        editor_widget->setReadOnly( !property.isWritable() );
        editor_widget->setObjectName( property.name() );
        m_inputWidgets.append( editor_widget );
        
        grid_layout->addWidget( editor_widget, row, 1 );
        
        ++row;
    }
    
    // Dynamic Properties
    QList<QByteArray> dynamic_property_names;
    if ( public_properties.isEmpty() )
    {
        dynamic_property_names = m_pProcessedObject->dynamicPropertyNames();
    } 
    else
    {
        // Show all dynamic properties that were exported by the object
        QString prop_name;
        foreach ( prop_name, public_properties )
            dynamic_property_names.append( prop_name.toLocal8Bit() );
    }
        
    QString dynamic_property_name;
    foreach( dynamic_property_name, dynamic_property_names )
    {
        grid_layout->addWidget( new QLabel( dynamic_property_name, this ), row, 0 );
        
        QLineEdit* editor_widget = new QLineEdit( this );

        QString string_property;
        QVariant variant_property = m_pProcessedObject->property( dynamic_property_name.toLocal8Bit().data() );
        qDebug() << "Cannot convert type: " << variant_property.typeName();
        // Manually convert QStringList to a string
        if ( QString( variant_property.typeName() ) == "QStringList" )
        {
            // StringsLists are caused by a unprotected "," in the INI-File. We will fix this here..
            string_property = variant_property.value<QStringList>().join( ", " );
        }
        else
        {
            if ( variant_property.canConvert<QString>() )
            {
                string_property = variant_property.toString();
            }
            else
            {
                qWarning() << "Property of type: " << variant_property.typeName() << "cannot be converted to a string!";
            }
        }
        
        editor_widget->setText( string_property );
        editor_widget->setObjectName( dynamic_property_name );
        m_inputWidgets.append( editor_widget );
        
        grid_layout->addWidget( editor_widget, row, 1 );
        
        ++row;
    }
    
    
    update();
}

void PropertyEditor::commit()
{
    bool hasChanged = false;
    
    QMap<QString, QVariant> changed_attributes = changedProperties();
    foreach( QString attribute_name, changed_attributes.keys() )
    {
        m_pProcessedObject->setProperty( attribute_name.toLocal8Bit().data(), 
                                        changed_attributes.value( attribute_name ) );
        hasChanged = true;
    }

    if ( hasChanged )
    {
        // emit signalContentChanged();
    }
}


void PropertyEditor::ignoreProperties( const QStringList& propertyNames )
{
    m_ignoredProperties = propertyNames;
}

QMap<QString, QVariant> PropertyEditor::changedProperties()
{
    QMap<QString, QVariant> ret_map;
    
    // Iterate over all input widgets and write its data back into the object
    QLineEdit* edit_widget = NULL;
    foreach( edit_widget, m_inputWidgets )
    {
        QString property_name = edit_widget->objectName();
        QMetaProperty property = m_pProcessedObject->metaObject()->property( m_pProcessedObject->metaObject()->indexOfProperty( property_name.toLocal8Bit().data() ) );
        
        qDebug() << "Check for modified properties:" << m_pProcessedObject->property( property_name.toLocal8Bit().data() )
        << " != " << edit_widget->text();
        if ( m_pProcessedObject->property( property_name.toLocal8Bit().data() ) != edit_widget->text() )
        {
            qDebug() << "save modified property: " << property_name << "with text = " << edit_widget->text();
            ret_map.insert( property_name, edit_widget->text() );
        }
    }
    return ret_map;
}
