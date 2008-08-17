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
#ifndef AstadeDataModelPrivate_h_
#define AstadeDataModelPrivate_h_

#include <QSortFilterProxyModel.h>

#include <Elements.h>

namespace {
    const char* g_contextInfoFileName = "ModelNode.ini";
}

class Element;
class QDirModel;

/** Low level access to the data structure.. */
class AstadeDataModelPrivate: public QSortFilterProxyModel
{
    Q_OBJECT
public:
    AstadeDataModelPrivate( QObject * parent = 0 );
    QModelIndex index ( const QString & path, int column = 0 ) const;
    Element* createElementForIndex( const QModelIndex& index, Element* parent = NULL ) const;
    bool saveTree( Element* rootElement );
    
    //** Saves the element if it was modified and if it does not references external objects */
    bool saveElement( Element* element );
    // Elements::RelationTypes relationTypeForIndex( const QModelIndex& index ) const;  
protected:
    Elements::ElementTypes elementTypeFromContext( const QMap<QString, QVariant>& contextData ) const;
    bool filterAcceptsRow ( int source_row, const QModelIndex & source_parent ) const;  
    QString pathForIndex( const QModelIndex& index ) const;
    QString filenameForIndex( const QModelIndex& index ) const;
    QString filePathForIndex( const QModelIndex& index ) const;
    QMap<QString, QVariant> contextDataForElementAtIndex( const QModelIndex& index, bool& isDir ) const;
    
protected:
    
private:
    QDirModel* m_pDirModel;
};

#endif // AstadeDataModelPrivate_h_

