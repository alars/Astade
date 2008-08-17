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
    QModelIndex indexForElement( const Element* element ) const;

    /**
     * Adds all children elements to <i>element</i>, starting with <i>element</i>.
     */ 
    void addChildrenToElement( Element* element ) const;
    
public slots:
    /**
     * Writes data back to disk.
     * @param rootIndex The element where saving starts. The element and all subelements will be stored. 
     *                    If nothing is given, the whole model tree is saved.
     */
    bool slotCommit( const QModelIndex& rootIndex = QModelIndex() );
       
protected:
    QString visualStringForElement( const QModelIndex& index ) const;
    QString descriptionForElement( const QModelIndex& index ) const;
    void emitModelChangesToParents( const QModelIndex& index );

private:
    AstadeDataModelData* d;
    
};



#endif // ASTADE_DATA_MODEL_H_
