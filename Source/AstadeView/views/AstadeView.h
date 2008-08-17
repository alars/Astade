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
#ifndef AstadeView_H_
#define AstadeView_H_

#include <QWidget>
#include <QModelIndex>

class QAbstractItemModel;
class QItemSelectionModel;
class AstadeDataModel;

class AstadeView : public QWidget {
    Q_OBJECT
public:
    AstadeView( QWidget* parent );
    virtual void setModels( QAbstractItemModel* model, QItemSelectionModel* selections ) = 0;
    virtual void setRootIndex( const QModelIndex& index ) = 0;
    
    /**
     * Shows the context menu for the selected Element.
     */
    virtual void contextMenuRequested( QAbstractItemModel* model, 
                                      const QModelIndex& requestedIndex, 
                                      const QPoint& pos );
    
    /**
     * Find Astade model. The Astade model may be hidden by other proxy models. This functions
     * tries to find it.
     */
    AstadeDataModel* obtainAstadeModelForModel( QAbstractItemModel* model ) const;
    QModelIndex convertProxyModelIndexToAstadeDataModelIndex( QAbstractItemModel* dataModel, 
                                                             const QModelIndex& proxyIndex ) const;
 
};


#endif // AstadeView_H_


