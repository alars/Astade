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
#include "AstadeDataModelPrivate.h"

#include <QDebug>
#include <QSettings>
#include <QDirModel>

#include "ElementFactory.h"
#include "Globals.h"
#include "ModelPropertyKeys.h"
#include "RootElement.h"

AstadeDataModelPrivate::AstadeDataModelPrivate( QObject * parent ): 
QSortFilterProxyModel( parent )
{
    m_pDirModel = new QDirModel( this );
    
    setSourceModel( m_pDirModel );
}

QModelIndex AstadeDataModelPrivate::index ( const QString & path, int column ) const
{
    Q_UNUSED( column );
    
    return mapFromSource( m_pDirModel->index( path ) );
}

Element* AstadeDataModelPrivate::createElementForIndex( const QModelIndex& index, Element* parent ) const
{
    bool is_dir = false;
    QMap<QString, QVariant> context_data = contextDataForElementAtIndex( index, is_dir );
    if ( context_data.isEmpty() && ( parent == NULL ) )
    {
        // No data found for root element: New database should be created.
        // We nee the corrent context data for a root element. We create it by asking 
        // the root element for it.
        qDebug() << "No context data => Create new context for new root element";
        RootElement* root_element = qobject_cast<RootElement*>( ElementFactory::self().newObject( Elements::ET_MODEL, NULL ) );
        root_element->initElementProperties();
        context_data = root_element->propertyMap();
        delete root_element;
    }
    
    Element* element = ElementFactory::self().newObject( elementTypeFromContext( context_data ), NULL );
    if ( element ){
        element->setLowLevelModelIndex( index );
        element->setPropertyMap( context_data );
        if ( parent != NULL ){ 
            element->setParent( parent );
            parent->updateOrderOfChildren();
        }
        // element->setFilename( filenameForIndex( index ) );
        element->setFilePath( filePathForIndex( index ) );
        element->setIsContainer( is_dir );
        
        // The state of the element will be modified here.. We will reset it..
        element->setModified( false );
    }
    return element;
}

// TODO: Handle save operation of newly created elements. These elements
//       may need a filename and path!?
bool AstadeDataModelPrivate::saveTree( Element* rootElement )
{
    Q_ASSERT( rootElement );
#if 1
    // qDebug() << "Write file: " << rootElement->filename();
    qDebug() << "Write dir : " << rootElement->filePath();
    qDebug() << "Is Directo: " << rootElement->isContainer();
    // qDebug() << "Content   : " << rootElement->propertyMap();
#endif
    
    bool error = false;
    
    // Save this element
    error = saveElement( rootElement );

    if ( !error )
    {
        // Write all chilren to disk!
        foreach( QObject* child_object, rootElement->children() )
        {
            // Recursive decent
            if ( !saveTree( qobject_cast<Element*>( child_object ) ) )
                error = true;
        }
    }
    
    return error;
}

bool AstadeDataModelPrivate::saveElement( Element* element )
{
    Q_ASSERT( element );
    // Elements which are just created to represent external items
    // should not be written..
    if ( element->isModified() && !element->isReferenceToExternalElement() )
    {
        QString model_path = Globals::self().currentModel();
        if ( !model_path.endsWith( "/" ) )
        { model_path += "/"; }
        QString file_path_and_name = Globals::self().currentModel() + element->filePath();
        
        if ( element->isContainer() )
        {
            if ( !file_path_and_name.endsWith( "/" ) )
                file_path_and_name += "/";
            
            file_path_and_name += g_contextInfoFileName;
        }
        else
        {
            // The following line is not needed, because "filePath()" already
            // contains the filename..
            // file_path_and_name += element->filename();
        }
        // qDebug() << "Write to: " << file_path_and_name;
        
        if ( !file_path_and_name.endsWith( "ini" ) ){
            // Currently, we just support ini-files for writing!!
            Q_ASSERT_X( false, 
                       "AstadeDataModelPrivate::saveTree()", 
                       "Try to write data into a file that does not seem to be an ini file!" );
            qWarning() << "Cannot save data: One element does not seem to be an ini file! In don't know how to handle such a file!";
            qWarning() << "Element file path: " << file_path_and_name;
            return false;
        }
        // Write context data into the ini file..
        QSettings settings( file_path_and_name, QSettings::IniFormat );
        
        //FIXME: Think, whether we really need the follwing line. But, it is useful
        //       For testing the save operation
        settings.remove( "" ); // Remove all entries from the current group
        
        QMap<QString, QVariant> properties( element->propertyMap() );
        QMap<QString, QVariant>::iterator it = properties.begin();
        while ( it != properties.end() ) {
            // Do not save properties that was added for internal reasons.
            if ( it.key().startsWith( "X-" ) ){
                ++it;
                continue;
            }
            
            settings.setValue( it.key(), it.value() );
            ++it;
        }
        
        // Element was successfully written. Thus, set modified flag to false.
        element->setModified( false );
    }
   
    // Fall through
    return true;
}

Elements::ElementTypes AstadeDataModelPrivate::elementTypeFromContext( const QMap<QString, QVariant>& contextData ) const
{
    bool conversion_ok;
    int type = contextData[g_contextInfoElementTypeKey].toInt( &conversion_ok );
    
    if ( !conversion_ok )
        return Elements::ET_UNKNOWN;
    
    return static_cast<Elements::ElementTypes>( type & Elements::ET_MASK );
}

#if 0
Elements::RelationTypes AstadeDataModelPrivate::relationTypeForIndex( const QModelIndex& index ) const
{
    int type = contextInfoForIndexAndKey( index, g_contextInfoElementTypeKey ).toInt();
    
    return static_cast<Elements::RelationTypes>( type & Elements::RT_MASK );    
}
#endif

bool AstadeDataModelPrivate::filterAcceptsRow ( int source_row, const QModelIndex & source_parent ) const
{
    if(!source_parent.isValid() || source_row < 0 )
        return false;
    
    QDirModel* dir_model = qobject_cast<QDirModel *>( sourceModel() );
    
    // We will not show ini files
    if ( dir_model->fileName( source_parent.child( source_row, 0 ) ) == g_contextInfoFileName )
        return false;
    
    // fall through..
    return true;
}


QString AstadeDataModelPrivate::pathForIndex( const QModelIndex& index ) const
{    
    return m_pDirModel->filePath( mapToSource( index ) );
}


QString AstadeDataModelPrivate::filenameForIndex( const QModelIndex& index ) const
{    
    return m_pDirModel->fileName( mapToSource( index ) );
}

QString AstadeDataModelPrivate::filePathForIndex( const QModelIndex& index ) const
{   
    qDebug() << "Current model: " << Globals::self().currentModel();
    QDir dir( Globals::self().currentModel() );
    qDebug() << "file path: " << m_pDirModel->filePath( mapToSource( index ) );
    return dir.relativeFilePath( m_pDirModel->filePath( mapToSource( index ) ) );
}



QMap<QString, QVariant> AstadeDataModelPrivate::contextDataForElementAtIndex( const QModelIndex& index, bool& isDir ) const
{
    QString file_name = m_pDirModel->fileName( mapToSource( index ) );
    QString file_path = m_pDirModel->filePath( mapToSource( index ) );
    
    QString filename_and_path;
    if ( m_pDirModel->isDir( mapToSource( index ) ) ){
        filename_and_path = file_path + "/" + g_contextInfoFileName;
        isDir = true;
    } else {
        isDir = false;
        // Read from ini file if possible
        if ( file_name.endsWith( "ini" ) ) {
            filename_and_path = file_path;
        } else {
            // This may be a single file that may be of known type. We will handle
            // these files here. This is bad because no model element should need
            // hard wired implementations in a generic model implementation!
            // FIXME: Discuss an architectural change: The model should contain an INI-File for every file that 
            //        describes the type. The is needed to extend the model with future types
            //        without modifying the code here!
            if ( file_name.endsWith( "cpp" ) )
            {
                // Detected CPP code..
                QMap<QString, QVariant> cpp_ret_map;
                cpp_ret_map.insert( g_contextInfoElementTypeKey, Elements::ET_CPPFILE );
                cpp_ret_map.insert( g_contextInfoFileName, file_name );
                cpp_ret_map.insert( g_contextInfoElementNameKey, file_name );
                return cpp_ret_map;
            } 
            if ( file_name.endsWith( "h" ) )
            {
                // Detected H code..
                QMap<QString, QVariant> cpp_ret_map;
                cpp_ret_map.insert( g_contextInfoElementTypeKey, Elements::ET_HFILE );
                cpp_ret_map.insert( g_contextInfoFileName, file_name );
                cpp_ret_map.insert( g_contextInfoElementNameKey, file_name );
                return cpp_ret_map;
            } 
            else
            {
                // Unknown type: Ignore it!!
            }
        }
    }
    
    QMap<QString, QVariant> ret_map;
    if ( filename_and_path.isEmpty() )
        return ret_map;
    
    QSettings settings( filename_and_path, QSettings::IniFormat );

    QStringList all_keys = settings.allKeys();
    QString key;
    foreach ( key, all_keys ){
        ret_map.insert ( key, settings.value( key ) );
    }

    return ret_map;
}

