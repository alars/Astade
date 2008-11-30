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
#include "Element.h"

#include <QDebug>
#include <QDesktopServices>
#include <QUrl>

#include "Globals.h"
#include "ModelPropertyKeys.h"
#include "AstadeDataModel.h"
#include "ElementDependencyMapper.h"
#include "ElementFactory.h"

namespace
{
    // Default ordering regarding the type and name
    bool parameterLessThan(const QObject* left, const QObject* right )
    {
        const Element* left_element = qobject_cast<const Element*>( left );
        const Element* right_element= qobject_cast<const Element*>( right );
        Q_ASSERT( left_element );
        Q_ASSERT( right_element );

        QString left_name = left_element->property( g_contextInfoElementNameKey ).toString();
        QString right_name = right_element->property( g_contextInfoElementNameKey ).toString();

        return ( ( QString::number( left_element->type() ) + left_name.toLower() )
                < ( QString::number( right_element->type() ) + right_name.toLower() ) );
    }
}


Element::Element( QObject* parent): QObject( parent ), m_pDataBaseModel( NULL ), m_isModified( false )
{
}

void Element::initElementProperties()
{
    m_isModified = true;

    setProperty( g_contextInfoElementNameKey, "Unknown" );
    setProperty( g_contextInfoElementTypeKey, Elements::ET_UNKNOWN );

    // Do not call "model()->slotCommit( this );" here!. The element is not configured completely
    // "slotCommit" is called later by elements that extends this.
}

void Element::setLowLevelModelIndex( QModelIndex index )
{
    m_isModified = true;
    // Create a persistant model index. Otherwise we will
    // get problems if the model changes.
    m_lowLevelModelIndex = QPersistentModelIndex( index );
}

QModelIndex Element::lowLevelModelIndex() const
{
    return m_lowLevelModelIndex;
}

int Element::posInChildrenList() const
{
    int pos = 0;
    foreach ( QObject* obj, parent()->children() )
    {
        Element* elem = qobject_cast<Element*>( obj );
        if ( elem == this )
            return pos;
        ++pos;
    }
    Q_ASSERT_X( false,
               "Element::posInChildrenList()",
               "This element is not contained in the list of child objects of its parent!" ); // Should never happen!
    return -1;
}

bool Element::contains( const QString& pattern )
{
    QObjectList children_list = children();

    // Return true if one of the children contains this string.
    // Thus, predecessors of the containing element will be shown.
    foreach( QObject* child, children_list )
    {
        Element* element = qobject_cast<Element*>( child );

        if ( element->contains( pattern ) )
            return true;
    }

    QList<QByteArray> dynamic_property_names = dynamicPropertyNames();
    foreach( QByteArray property_name, dynamic_property_names )
    {
        if ( property( property_name ).toString().contains( pattern, Qt::CaseInsensitive ) )
            return true;
    }

    // Fall through
    return false;
}

void Element::setDataBaseModel( AstadeDataModel* model )
{
    // This change will not influence the isModified() flag, because
    // it is just called on creation time.
    m_pDataBaseModel = model;
}

void Element::orderChanged()
{
    // Do not set the modified flag (m_isModified)! The modified flag signals that this element was changed.
    // "orderChanged()" signals that any (!) element was changed. The subclass has to decide
    // whether changing the modified flag is needed!

    // Just inform all child elements about changes.
    foreach ( QObject* child, d_ptr->children )
    {
        Element* element = qobject_cast<Element*>( child );
        if ( element )
        { element->orderChanged(); }
        else
        { 
            qWarning() << "Element::orderChanged(): Child of Element seems not to be of class Element! Type: " 
                       << child->metaObject()->className(); 
        }
    }
}

#if 1

QString Element::filename() const
{
    QString file_path = property( "X-FILEPATH" ).toString();
    int pos_of_last_slash = file_path.lastIndexOf( "/" );
    return file_path.right( pos_of_last_slash );
}

/** Set the path to the file. It should be relative to the model path */
void Element::setFilePath( const QString& filepath )
{
    QString file_path = filepath;
    m_isModified = true;
    Q_ASSERT( !file_path.startsWith( "/" ) );

    if ( file_path.isEmpty() )
    {
        file_path = "./";
    }
    qDebug() << "Path: " << file_path;
    setProperty( "X-FILEPATH", file_path );
}

/** The path to the file. Relative to the model path */
QString Element::filePath() const
{
    return property( "X-FILEPATH" ).toString();
}

// FIXME: This can be resolved without using a "X-" property: See flag: "ET_FOLDER"
bool Element::isContainer() const
{
    return property( "X-ISDIRECTORY" ).toBool();
}

void Element::setIsContainer( bool isContainer )
{
    m_isModified = true;
    setProperty( "X-ISDIRECTORY", isContainer );
}


#endif

bool Element::isEditable() const
{
    return false;
}

bool Element::isDragable() const
{
    return false;
}

bool Element::isDropable() const
{
    return false;
}

bool Element::isReferenceToExternalElement() const
{
    return true;
}

bool Element::isModified() const
{
    return m_isModified;
}

void Element::setModified( bool modified )
{
    m_isModified = modified;
}


QList<QAction* > Element::supportedActions() const
{
    QList<QAction* > ret_list;

#ifdef TESTMODE_
    QAction* edit_action = new QAction( tr( "&Debug" ), NULL );
    connect( edit_action, SIGNAL( triggered() ), this, SLOT( slotEdit() ) );
    ret_list << edit_action;

    QAction* separator = new QAction( "", NULL );
    separator->setSeparator( true );
    ret_list << separator;
#endif

    // Take the list of possible children from the dependency mapper
    QList<ElementDependencyMapper::AddableElement> possible_children( ElementDependencyMapper::self().addAbleElementsByType( type() ) );

    foreach( ElementDependencyMapper::AddableElement add_able_element, possible_children )
    {
        // TODO: Check whether these elements will ever be deleted!
        QAction* child_adder = new QAction( add_able_element.contextText, NULL );
        child_adder->setData( static_cast<int>( add_able_element.child_type ) );
        connect( child_adder, SIGNAL( triggered() ), this, SLOT( slotAddChild() ) );
        ret_list << child_adder;
    }

    return ret_list;
}

QString Element::toString( StringOutputRole stringRole ) const
{
    Q_UNUSED( stringRole );
    QString ret_string = property( g_contextInfoElementNameKey ).toString();

    if ( ret_string.isEmpty() ){
        return filename();
    }

    // Debug only!
    //ret_string += " (" + propertyMap()["X-FILENAME"].toString() + ") of Type: " + QString::number( propertyMap()[g_contextInfoElementTypeKey].toInt(), 16 );
    ret_string += " of Type: 0x" + QString::number( property( g_contextInfoElementTypeKey ).toInt(), 16 );

    return ret_string;
}

Elements::ElementTypes Element::type() const
{
    int type_property = property( g_contextInfoElementTypeKey ).toInt();

    return static_cast<Elements::ElementTypes>( type_property & Elements::ET_MASK );
}


void Element::setPropertyMap( const QMap<QString, QVariant>& data )
{
    QString key;
    foreach( key, data.keys() )
    {
        m_isModified = true;
        setProperty( key.toLocal8Bit().data(), data[key] );
    }
}

QMap<QString, QVariant> Element::propertyMap() const
{
    QMap< QString, QVariant > ret_map;

    QList<QByteArray> property_names = dynamicPropertyNames();
    QString property_name;
    foreach( property_name, property_names ){
        ret_map.insert( property_name, property( property_name.toLocal8Bit().data() ) );
    }

    return ret_map;
}

QStringList Element::publicProperties() const
{
    qDebug() << "Element::publicProperties()";
    QStringList ret_list;
    ret_list << g_contextInfoElementNameKey;
    ret_list << g_contextInfoElementDescriptionKey;
    return ret_list;
}

void Element::updateOrderOfChildren()
{
    qSort( d_ptr->children.begin(), d_ptr->children.end(), parameterLessThan );
}

QPixmap Element::decorationPixmap() const
{
    return QPixmap();
}

bool Element::moveChildElementFromTo( int from, int to, Element* element )
{
    m_isModified = true;

    Q_ASSERT( ( from >= 0 ) && ( to >= 0 ) );
    Q_ASSERT( element );

    if ( d_ptr->children.at( from ) != element )
        return false;

    d_ptr->children.move( from, to );

    // Now tell all child elements that something changed
    orderChanged();

    // Fall through
    return true;
}


void Element::slotEdit()
{
    QDesktopServices::openUrl( QUrl::fromLocalFile( Globals::self().currentModel()
                                                    + "/" + filePath() ) );
}

void Element::slotAddChild()
{
    m_isModified = true;

    Q_ASSERT( m_pDataBaseModel );
    if ( !m_pDataBaseModel )
    {
        qCritical() << "Element without pointer to its database detected!";
        return;
    }

    QAction* current_sender = qobject_cast<QAction*>( sender() );
    qDebug() << "Add Child of type: " << ( current_sender ? current_sender->data() : "NONE" );

    if ( ! current_sender )
        return;

    Element* element_to_add = ElementFactory::self().newObject( static_cast<Elements::ElementTypes>( current_sender->data().toInt() ), m_pDataBaseModel );
    m_pDataBaseModel->addChildToElement( element_to_add, m_pDataBaseModel->indexForElement( this ) );
    element_to_add->initElementProperties();
}

// Protected ..
AstadeDataModel* Element::model() const
{
    return m_pDataBaseModel;
}



