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
#include "AstadeDataModel.h"

#include <QDebug>
#include <QDirModel>
#include <QMimeData>
#include <QFile>
#include <QPointer>
#include <QMessageBox>

#include "Globals.h"
#include "ModelPropertyKeys.h"
#include "AstadeDataModelPrivate.h"
#include "Element.h"
#include "IconProvider.h"
#include "ElementFactory.h"

class QDirModel;

namespace {
    const char* g_customElementMimeType = "astade/x-elementdata";

    /**
     * Streams the content of the element. Used to serialize the content. The default
     * implementation streams the class name and all its properties.
     */
    QDataStream & operator<< ( QDataStream & stream, const Element& element )
    {
        stream << element.type();
        stream << element.propertyMap();

        return stream;
    }
}

struct AstadeDataModelData
{
    QPointer<Element> m_pRootElement;
    QPointer<AstadeDataModelPrivate> m_pLowLevelModel;

    QString m_modelRootDir;
    IconProvider m_iconProvider;
    
    void init()
    {
        m_pRootElement = NULL;
        m_pLowLevelModel = NULL;
    }
};

AstadeDataModel::AstadeDataModel( QObject * parent ): QAbstractItemModel( parent ), d( new AstadeDataModelData )
{
    d->init();

    setSupportedDragActions( Qt::MoveAction );
}

AstadeDataModel::~AstadeDataModel()
{
    slotCommit();
    delete d->m_pRootElement;
    delete d;
}

// TODO: Add UNDO-Support (?)
QModelIndex AstadeDataModel::setModelRootDir( const QString& dir )
{
    QFileInfo model_dir( dir );
    if ( !model_dir.isDir() )
    {
        qWarning() << "AstadeDataModel::setModelRootDir(): Given model directory is invalid: " << dir;
        return QModelIndex();
    }

    d->m_modelRootDir = dir;

    d->m_pLowLevelModel = new AstadeDataModelPrivate( this );

    QModelIndex source_index = d->m_pLowLevelModel->index( d->m_modelRootDir );
    d->m_pRootElement = d->m_pLowLevelModel->createElementForIndex( source_index );
    d->m_pRootElement->setModel( this );

    // Load all children of the root element..
    addChildrenToElement( d->m_pRootElement );

    return QModelIndex();
}

QModelIndex AstadeDataModel::index ( int row, int column, const QModelIndex& parent ) const
{
    Q_ASSERT( d );
    if ( !d || !d->m_pRootElement )
        return QModelIndex();

    if ( ( row < 0 )
        || ( column < 0 )
        || ( column >= columnCount(parent) ) )
    { return QModelIndex(); }

    Element* parent_element = NULL;
    if ( !parent.isValid() )
    { parent_element = d->m_pRootElement; }
    else
    { parent_element = static_cast<Element*>( parent.internalPointer() ); }

    Q_ASSERT( parent_element );
    if ( NULL == parent_element )
        return QModelIndex();

    QObjectList children = parent_element->children();
    if ( ( row >= children.count() ) || ( children.count() < 0 ) )
        return QModelIndex();

    return createIndex( row, column, children.at(row) );
}

QModelIndex AstadeDataModel::parent(const QModelIndex &child) const
{
    if ( !child.isValid() )
        return QModelIndex();

    Element* child_element = static_cast<Element*>( child.internalPointer() );
    Q_ASSERT( child_element );
    if ( NULL == child_element )
        return QModelIndex();

    if ( child_element == d->m_pRootElement )
    {
        // The root element don't have children!
        return QModelIndex();
    }

    Element* parent = qobject_cast<Element*>( child_element->parent() );
    Q_ASSERT( parent );
    if ( parent == d->m_pRootElement ) // The parent of a root element should be invalid!
        return QModelIndex();

    return createIndex( parent->posInChildrenList(), 0 , parent );
}

QVariant AstadeDataModel::data( const QModelIndex& index, int role ) const
{
    if ( !index.isValid() )
        return QVariant();

    // Load possible children
    addChildrenToElement( elementForIndex( index ) );

    switch ( role ){
        case Qt::DisplayRole:
            switch ( index.column() )
            {
                case CT_ElementName:
                    return visualStringForElement( index );
                case CT_ElementDescription:
                    return descriptionForElement( index );
                default:
                    return QString( "Invalid section." );
            }
        case Qt::DecorationRole:
            if ( index.column() == CT_ElementName )
            {
                return d->m_iconProvider.iconForType( elementForIndex( index ) );
            }
            break;
        case Qt::ToolTipRole:{
            QString description( descriptionForElement( index ) );
            return description.isEmpty() ? QVariant() : description;
          } break;
        case CR_PathToNode:{ // TODO: Remove a.s.a.p.! This exposes low level data to public! (se)
            Element* element = elementForIndex( index );
            QString ret_path_to_node = modelPath();
            ret_path_to_node += element->filePath();
            if ( element->isContainer() ){
                ret_path_to_node += QString( "/" ) + AstadeDataModelPrivate::modelNodeContextFileName();
            }

            qDebug() << "Element path = " << ret_path_to_node;

#ifndef Q_OS_WIN32
            // TODO: Check why this doesn't work on windows
            if ( !QFile::exists( ret_path_to_node ) )
                ret_path_to_node.clear();
#endif

            return ret_path_to_node;
        }
        case CR_ElementType:{
            Element* element = elementForIndex( index );
            Q_ASSERT( element );
            return element->type();
        }
        case Qt::StatusTipRole:{
            Qt::ItemFlags element_flags = flags( index );
            if ( element_flags & Qt::ItemIsDragEnabled )
            { return tr( "Drag Element to change position" ); }
            else
            {
                if ( element_flags & Qt::ItemIsEditable )
                { return tr( "Double-click to open editor" ); }
                else
                { return tr( "No help available.." ); }
            }
        } break;
        default:
            // Empty
            break;
    }

    // Fall through
    return QVariant();

}

// TODO: Implement UNDO here..
bool AstadeDataModel::setData ( const QModelIndex & index, const QVariant & value, int role )
{
    qDebug() << "AstadeDataModel::setData for Index" << index << "setting value:" << value << "for role:" << role;

    if ( !index.isValid() || !value.isValid() || role != CR_ElementAttributes )
    {
        qWarning() << "AstadeDataModel::setData(): Incorrect data!";
        return false;
    }

    // Update attributes of element addressed by index
    Element* element = elementForIndex( index );

    if ( !element )
    {
        qWarning() << "AstadeDataModel::setData(): Index addresses non existing element!";
        Q_ASSERT( false );
        return false;
    }

    element->setPropertyMap( value.value<QMap<QString,QVariant> >() );

    // Handle model update..
    // First: Tell the view that we have changed the edited element.
    emit dataChanged( index, index );

    // This is a tree: Changing an element may modify the element of the parent, too.
    // Second: Update all parents..
    emitModelChangesToParents( index );

    // Save this element to disk if it was modified.
    d->m_pLowLevelModel->saveElement( element );

    return true;
}

#if 0
bool AstadeDataModel::insertRows ( int row, int count, const QModelIndex & parent )
{
    Q_UNUSED( row );
    Q_UNUSED( count );
    emit beginInsertRows( parent, 0, 0 );
    // TODO: Implement this!
    qDebug() << "AstadeDataModel::insertRows()";
    emit endInsertRows();

    // Fall through
    return false;
}
#endif

// TODO: Add UNDO-Support
bool AstadeDataModel::addChildToElement( Element* child, QModelIndex parentIndex )
{
    Element* parent_element = NULL;

    if ( parentIndex.isValid() )
    { parent_element = elementForIndex( parentIndex ); }
    else
    { parent_element = d->m_pRootElement; }

    Q_ASSERT( child );
    Q_ASSERT( parent_element );

    if ( !child
        || !parent_element )
    {
        return false;
    }

    emit beginInsertRows( parentIndex, rowCount( parentIndex ), rowCount( parentIndex ) + 1 );
    child->setParent( parent_element );
    emit endInsertRows();

    // Fall through..
    return true;
}

// TODO: Add UNDO-Support
bool AstadeDataModel::removeRows ( int row, int count, const QModelIndex & parent )
{
    Element* parent_element    = elementForIndex( parent );
    int children_count = parent_element->children().count();
    
    Q_ASSERT( parent_element );
    Q_ASSERT( d->m_pLowLevelModel );
    Q_ASSERT( count > 0 );
    Q_ASSERT( (row + count) <= children_count );
    
    if ( ( count <= 0 ) 
        || ( (row + count) > children_count ) )
    { 
        return false;
    }
    
    for ( int i = row; i < (row + count); ++i )
    {
        Element* element_to_remove = qobject_cast<Element*>( parent_element->children().at( i ) );
        Q_ASSERT( element_to_remove );

        d->m_pLowLevelModel->removeDataOfChildren( element_to_remove );
        d->m_pLowLevelModel->removeDataOfElement( element_to_remove );
    }
    removeRowsHighLevelOnly( row, count, parent );    
    
    return true;
}

// Removing without deleting the data from the low level model
bool AstadeDataModel::removeRowsHighLevelOnly( int row,
                            int count,
                            const QModelIndex & parent )
{
    qDebug() << "AstadeDataModel::removeRows(" << row << "," << count << ")";
    Q_ASSERT( count > 0 );
    
    beginRemoveRows( parent, row, row + (count - 1) );
    Element* parent_element = static_cast<Element*>( elementForIndex( parent ) );
    Q_ASSERT( NULL != parent_element );
    
    QObjectList children = parent_element->children();
    for ( int i = 0; i < count; ++i )
    {
        delete children.at( row + i );
    }
    
    // Tell all childs that something has changed.
    parent_element->orderChanged();
    
    endRemoveRows();
    
    // Fall through
    return true;
}

bool AstadeDataModel::hasChildren ( const QModelIndex & parent ) const
{
    Q_ASSERT( d );
    if ( !d || !d->m_pRootElement )
        return false;

    Element* parent_element = NULL;
    if ( !parent.isValid() )
    { parent_element = d->m_pRootElement; }
    else
    {  parent_element = elementForIndex( parent ); }

    if ( !parent_element )
        return false;
    
    addChildrenToElement( parent_element );

    return !parent_element->children().isEmpty();
}

int AstadeDataModel::rowCount ( const QModelIndex & parent ) const
{
    Q_ASSERT( d );
    if ( !d || !d->m_pRootElement )
        return 0;

    Element* parent_element = NULL;
    if ( !parent.isValid() )
    { parent_element = d->m_pRootElement; }
    else
    { parent_element = static_cast<Element*>( parent.internalPointer() ); }

    Q_ASSERT( NULL != parent_element );
    if ( NULL == parent_element )
        return 0;

    addChildrenToElement( parent_element );
    // qDebug() << "AstadeDataModel::rowCount: " << parent_element->children().count();

    return parent_element->children().count();
}

int AstadeDataModel::columnCount( const QModelIndex & parent ) const
{
    Q_UNUSED( parent );
    return 1; // Supported are two columns..
}


QVariant AstadeDataModel::headerData( int section, Qt::Orientation orientation, int role ) const
{
    Q_UNUSED( orientation )
//    if ( ( role != Qt::DisplayRole ) || ( section != 0 ) || ( orientation != Qt::Horizontal ) )
//        return m_pBackend->headerData( section, orientation, role );
    if ( role != Qt::DisplayRole )
        return QVariant();

    switch ( section ){
        case CT_ElementName:
            return QString( tr( "Model at: %1" ) ).arg( d->m_modelRootDir );
        case CT_ElementDescription:
            return QString( tr( "Description" ) );
        default:
            return QString( tr( "Unknown Section" ) );
    }

}

Qt::ItemFlags AstadeDataModel::flags ( const QModelIndex& index ) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags( index );

    if ( !index.isValid() )
        return flags;

    if ( elementForIndex( index )->isEditable() )
        flags |= Qt::ItemIsEditable;

    // Elements define itself whether they are dropable
    if ( elementForIndex( index )->isDropable() )
        flags |= Qt::ItemIsDropEnabled;

    // Currently we do not support dragging of
    // elements with children.
    // TODO: Implement recurrent drag and drop operations!
    if ( !hasChildren( index ) )
    {
        // Elements define itself whether they are draggable
        if ( elementForIndex( index )->isDragable() )
            flags |= Qt::ItemIsDragEnabled;

    }
    return flags;
}

Qt::DropActions AstadeDataModel::supportedDropActions () const
{
    return Qt::MoveAction;
}

QStringList AstadeDataModel::mimeTypes () const
{
    QStringList types;
    types << g_customElementMimeType;
    return types;
}

QMimeData* AstadeDataModel::mimeData(const QModelIndexList &indexes) const
{
    QMimeData *mimeData = new QMimeData();
    QByteArray encodedData;

    QDataStream stream( &encodedData, QIODevice::WriteOnly );

    // We want to copy an element.
    // We receive an index for every row and (!) every column.
    // But, all columns of a row belonging to the same element. Therefore,
    // we have to count the elements to copy..
    int element_count = 0;
    foreach( QModelIndex index, indexes )
    {
        if ( index.isValid() && ( index.column() == 0 ) )
        {
            ++element_count;
        }
    }
    stream << element_count;

    foreach ( QModelIndex index, indexes ) {
        if ( index.isValid() ) {
            // Just use indexes of column 0. Column > 0 is just a different view
            // to the element and does not need to be copied.
            if ( index.column() > 0 )
                continue;

            qDebug() << "AstadeDataModel::mimeData():row = " << index.row();
            Element* element = static_cast<Element*>( index.internalPointer() );
            Q_ASSERT( element );
            stream << *element;
        }
    }
    mimeData->setData( g_customElementMimeType, encodedData );
    return mimeData;
}

#include <QApplication>

// TODO: Add UNDO-Support
bool AstadeDataModel::dropMimeData( const QMimeData *data,
                                    Qt::DropAction action,
                                    int row,
                                    int column,
                                    const QModelIndex &parent )
{
    if (action == Qt::IgnoreAction)
        return true;

    if ( !data->hasFormat( g_customElementMimeType ) )
        return false;

    if ( column > 0 )
        return true;

    int beginRow = -1;

    if ( row != -1 )
    {
        // Dropped between items. Row is valid and should be used.
        beginRow = row;
    }
    else if ( parent.isValid() )
    {
        // Dropped on an item that is not a toplevel item.
        beginRow = rowCount( parent );
    }
    else
    {
        // Dropped on an toplevel item
        beginRow = rowCount( QModelIndex() );
    }

    Element* parent_element = NULL;
    if ( parent.isValid() )
    {
        parent_element = static_cast<Element*>( parent.internalPointer() );
        Q_ASSERT( parent_element );
    }

    QByteArray encodedData = data->data( g_customElementMimeType );
    QDataStream stream( &encodedData, QIODevice::ReadOnly );

    int rows = 0;
    int count = 0;

    stream >> count;
    Q_ASSERT( count > 0 );

    beginInsertRows( parent, beginRow, beginRow + ( count - 1 ) );
    while ( !stream.atEnd() && count )
    {
        int int_type;
        stream >> int_type;
        Element* element = ElementFactory::self().newObject( static_cast<Elements::ElementTypes>( int_type ), this );
        Q_ASSERT( element );
        QMap<QString, QVariant> property_map;
        stream >> property_map;

        // Initialize Element
        element->setPropertyMap( property_map );
        if ( parent_element )
            element->setParent( parent_element );
        else
            element->setParent( d->m_pRootElement );

        // Move Element at the given position
        // Note: The element is alread added to the end of the list by calling
        //       "setParent()". Thus, we have to move it from the end of the list
        //       to the correct position.
        parent_element->moveChildElementFromTo( parent_element->children().count() - 1, beginRow, element );

        ++beginRow;
        ++rows;
        --count;
    }
    endInsertRows();

    return true;
}

Element* AstadeDataModel::elementForIndex( const QModelIndex& index ) const
{
    Element* ret_element = NULL;
    if ( index.isValid() )
    { ret_element = qobject_cast<Element*>( (QObject*)index.internalPointer() ); }
    else
    { ret_element = d->m_pRootElement; }

    Q_ASSERT( ret_element );

    return ret_element;
}

QModelIndex AstadeDataModel::indexForElement( const Element* element ) const
{
    Q_ASSERT( element );
    Q_ASSERT( d->m_pRootElement );
    
    if ( element == d->m_pRootElement )
    { return QModelIndex(); }

    return createIndex( element->posInChildrenList(), 0, (void*)element );
}


// Add children elements to given element
// This function is not really "const". It just has to be defined as const to 
// enable functions like "data()" to call it.
// TODO: Find a solution to avoid this const casts!!
int AstadeDataModel::addChildrenToElement( Element* element ) const
{
    if ( !element )
    { return 0; }

    // Stop when the element already has children. This happens when
    // this function was already called for this element.
    if ( !element->children().isEmpty() )
    { return 0; }

    QModelIndex parent_lowlevel_index = element->lowLevelModelIndex();

    // Iterate over all childs, create elements and add them to this..
    int row_count = 0;
    QModelIndex child_index;
    do {
        child_index = parent_lowlevel_index.child( row_count, 0 );
        if ( child_index.isValid() ){
            // qDebug() << "Create Element for index:" << child_index << "at row:" << row_count - 1 ;
            Element* sub_element = d->m_pLowLevelModel->createElementForIndex( child_index, element );
            Q_ASSERT( sub_element );
            if ( sub_element )
            {
                sub_element->setModel( const_cast<AstadeDataModel*>(this) ); 
            }
            ++row_count;
        }
    } while ( child_index.isValid() );
    
    return row_count;
}

// TODO: Add UNDO-Support
void AstadeDataModel::deleteSubtree( Element* parent )
{
    if ( !parent )
    { return; }

    // Iterate over all already known childs and remove it.
    // If an element needs to be saved: Ask user, otherwise
    // we will overwrite external changes..
    foreach( QObject* child, parent->children() )
    {
        Element* child_element = qobject_cast<Element*>( child );
        if ( !child_element )
        { continue; }

        // Recursive descend..
        deleteSubtree( child_element );

        Q_ASSERT( child_element );

        if ( child_element->isModified() )
        {
            QMessageBox msgBox;
            msgBox.setIcon( QMessageBox::Question );
            msgBox.setWindowTitle( tr( "Reload data" ) );
            msgBox.setText( tr( "The data was modified and will get lost if not saved!<br>Should I save?<br>Element: %1" ).arg( child_element->toString( Element::SOR_Default ) ) ); // TODO: Improve this message (se)
            msgBox.setStandardButtons( QMessageBox::Yes | QMessageBox::No );
            switch (msgBox.exec()) {
            case QMessageBox::Yes:
                slotCommit( indexForElement( child_element ) );
                break;
            case QMessageBox::No:
                child_element->setModified( false );
                break;
            default:
                // Ignored
                break;
            }
        }
        int row = child_element->posInChildrenList();
        removeRowsHighLevelOnly( row, 1, indexForElement( parent ) );
    }

}

void AstadeDataModel::updateChildren( Element* parent )
{
    if ( !parent )
    { return; }

    // Remove all children.
    deleteSubtree( parent );

    // Reload children
    int count = addChildrenToElement( parent );
    
    // Update View
    if ( count > 0 )
    {
        beginInsertRows( indexForElement( parent ), 0, count - 1 );
        endInsertRows();
    }
}

void AstadeDataModel::elementUpdated( Element* element, bool reloadSubtree )
{
    Q_ASSERT( element );
    if ( !element )
    { return; }

    emit dataChanged( indexForElement( element ), indexForElement( element ) );

    if ( reloadSubtree )
    { 
        d->m_pLowLevelModel->invalidate();
        updateChildren( element ); 
    }
}


// Protected Functions

// Returns a human readable String representation of the element at pos <i>index</i>.
// This function uses the element factory to handle the elements..
QString AstadeDataModel::visualStringForElement( const QModelIndex& index ) const
{

    QString ret_string;

    Element* element = elementForIndex( index );
    if ( !element ){
        Q_ASSERT( false );
        ret_string = QString("Invalid Element" );  // Fallback for invalid types
    } else {
        ret_string = element->toString();
    }

    return ret_string;
}

QString AstadeDataModel::descriptionForElement( const QModelIndex& index ) const
{
    if ( !index.isValid() )
        return QString();

    Element* element = static_cast<Element*>( index.internalPointer() );
    Q_ASSERT( element );

    return element->property( g_contextInfoElementDescriptionKey ).toString();
}


void AstadeDataModel::emitModelChangesToParents( const QModelIndex& index )
{
    if ( index.parent().isValid() )
    {
        emit dataChanged( index.parent(), index.parent() );

        // Recursive ascent
        emitModelChangesToParents( index.parent() );
    }
}

// TODO: Add UNDO-Support
bool AstadeDataModel::slotCommit( const QModelIndex& rootIndex )
{
    Q_ASSERT( d->m_pLowLevelModel );
    Q_ASSERT( d->m_pRootElement );
    if ( !d->m_pRootElement || !d->m_pLowLevelModel )
        return false;

    d->m_pLowLevelModel->saveTree( ( rootIndex.isValid()) ? elementForIndex( rootIndex ) : d->m_pRootElement.data() );
    return true;
}


void AstadeDataModel::slotRemoveElement( Element* element )
{
    qDebug() << "AstadeDataModel::slotRemoveElement: Class:" << element->metaObject()->className();
    
    removeRows( element->posInChildrenList(), 1, indexForElement( qobject_cast<Element*>( element->parent() ) ) );
}

QString AstadeDataModel::modelPath() const
{
    return d->m_modelRootDir;
}

