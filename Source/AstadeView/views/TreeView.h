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
#ifndef TREE_VIEW_H_
#define TREE_VIEW_H_

#include <QItemSelection>
#include <QPointer>

#include <AstadeView.h>

class AstadeDataModel;
class QTreeView;
class QPushButton;
class QSortFilterProxyModel;

class TreeView: public AstadeView
{
    Q_OBJECT
public:
    TreeView( QWidget* parent );
    void setModels( QAbstractItemModel* model, QItemSelectionModel *selections );
    void setRootIndex( const QModelIndex& index );
    
protected slots:
    void slotContextMenuRequested( const QPoint& pos );
    void slotSelectionChanged( const QItemSelection& selected, const QItemSelection& deselected );
    
private:
    void init();
    
    QPointer<QAbstractItemModel> m_pDataModel;
    QTreeView* m_pTreeView;
    QSortFilterProxyModel* m_pProxyModel;
};

#endif // TREE_VIEW_H_

