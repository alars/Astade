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
#ifndef ASTADE_DATA_MODEL_H_
#define ASTADE_DATA_MODEL_H_

#include <QAbstractItemModel>
#include <QMap>

#include "Elements.h"

class AstadeDataModelData;
class AstadeDataModelPrivate;
class Element;
/**
 * This model provides read and write access to the Astade model database.
 * It is a Qt data model.
 */
class AstadeDataModel: public QAbstractItemModel
{
    Q_OBJECT
public:
    enum ColumnTypes{
        CT_ElementName = 0,
        CT_ElementDescription
    };

    enum CustomRoles{
        /** Returns the path to the element node. */
        CR_PathToNode = Qt::UserRole,
        CR_ElementAttributes,
        CR_ElementType
    };

    AstadeDataModel( QObject * parent = 0 );
    ~AstadeDataModel();
    /**
     * Sets the model to the given root directory.
     * @param dir Directory to the model data.
     * @param createWhenEmpty If the directory is empty a root element is created.
     */
    QModelIndex setModelRootDir( const QString& dir );

    QModelIndex index ( int row,
                        int column,
                        const QModelIndex& parent = QModelIndex() ) const;

    QModelIndex parent( const QModelIndex& child ) const;

    QVariant data ( const QModelIndex& index,
                    int role = Qt::DisplayRole ) const;

    /**
     * Change element at given index.
     * @param index The index of the element that should be changed.
     * @param value Data to store into the element. If role CR_ElementAttributes is used: A QMap<QString, QVariant> is expected
     *              that contains the modified attributes.
     * @param role Currently just CR_ElementAttributes is implemented to modify the attributes of the addressed element.
     */
    bool setData ( const QModelIndex& index,
                   const QVariant & value,
                   int role = Qt::EditRole );

#if 0
    bool insertRows ( int row,
                      int count,
                      const QModelIndex & parent = QModelIndex() );
#endif
    bool addChildToElement( Element* child, QModelIndex parentIndex );

    bool removeRows ( int row,
                      int count,
                      const QModelIndex & parent = QModelIndex() );

    bool hasChildren ( const QModelIndex & parent = QModelIndex() ) const;

    int rowCount ( const QModelIndex& parent ) const;

    int columnCount ( const QModelIndex& parent = QModelIndex() ) const;

    QVariant headerData ( int section,
                          Qt::Orientation orientation,
                          int role = Qt::DisplayRole ) const;

    Qt::ItemFlags flags ( const QModelIndex& index ) const;

    Qt::DropActions supportedDropActions () const;

    QStringList mimeTypes () const;

    QMimeData* mimeData(const QModelIndexList &indexes) const;

    bool dropMimeData( const QMimeData *data,
                       Qt::DropAction action,
                       int row,
                       int column,
                       const QModelIndex &parent );

    /**
     * Returns the element for the given index. Do not delete this element! It is
     * owned by the model!
     */
    Element* elementForIndex( const QModelIndex& index ) const;
    
    /**
     * Returns the index for the given element.
     */
    QModelIndex indexForElement( const Element* element ) const;

    /**
     * Adds all children elements to <i>parent</i>.
     * This function only adds children if parent does not has any children. It is not
     * sending any update signals to the view! This needs to be done by the caller.
     * Use deleteSubtree() to remove them if it is necessary to reload the subtree.
     * @return Number of children added.
     */
    int addChildrenToElement( Element* parent ) const;

    /**
     * Update children.
     * This function checks for changes on the low-level database and updates the children
     * accordingly. This function descends recursivly on the sub-tree below parent.
     */
    void updateChildren( Element* parent );

    /**
     * Element updated.
     * This slot is called by elements if internal changes occured that will
     * inluence the view. The view will be informed by this model that an update makes sense.
     * @param element The element that is updated.
     * @param reloadSubtree The subtree for this element should be reloaded as well.
     */
    void elementUpdated( Element* element, bool reloadSubtree );

    /**
     * Path to model base directory
     */
    QString modelPath() const;
        
public slots:
    /**
     * Writes data back to disk.
     * @param rootIndex The element where saving starts. The element and all subelements will be stored.
     *                    If nothing is given, the whole model tree is saved.
     */
    bool slotCommit( const QModelIndex& rootIndex = QModelIndex() );
    
    /**
     * Remove element.
     * This slot removes the given element including all of its sub elements.
     * @param element The element to remove. This pointer is deleted after this call!
     */
    void slotRemoveElement( Element* element );

protected:
    QString visualStringForElement( const QModelIndex& index ) const;
    QString descriptionForElement( const QModelIndex& index ) const;
    void emitModelChangesToParents( const QModelIndex& index );
    
    /**
     * Deletes subtree below parent.
     * The user is asked whether a modified element should be saved before it will be removed.
     */
    void deleteSubtree( Element* parent );
        
    /** 
     * Delete row on high level model only including all its sub elements. 
     * Operation does not support UNDO! 
     */
    bool removeRowsHighLevelOnly( int row,
                                  int count,
                                  const QModelIndex & parent = QModelIndex() );
    

private:
    AstadeDataModelData* d;

    friend class AstadeDataModelPrivate;
};



#endif // ASTADE_DATA_MODEL_H_
