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
#include "TreeView.h"

#include <QDebug>
#include <QDirModel>
#include <QTreeView>
#include <QColumnView>
#include <QVBoxLayout>
#include <QSplitter>
#include <QPushButton>
#include <QAbstractItemModel>
#include <QAbstractProxyModel>
#include <QAbstractItemDelegate>
#include <QMenu>

#include "Globals.h"
#include "AstadeDataModel.h"
#include "ModelElementDelegate.h"
#include "Element.h"

#include <QSortFilterProxyModel>

TreeView::TreeView( QWidget* parent ): 
AstadeView( parent ), 
m_pDataModel( NULL ), 
m_pTreeView( NULL ),
m_pProxyModel( NULL )
{
    init();
}

void TreeView::setModels( QAbstractItemModel* model, QItemSelectionModel *selections )
{
    m_pDataModel = model;

    connect( selections, SIGNAL( selectionChanged( const QItemSelection&, const QItemSelection& ) ),
            this, SLOT( slotSelectionChanged( const QItemSelection&, const QItemSelection& ) ) );
    
    m_pTreeView->setModel( m_pDataModel );
    m_pTreeView->setSelectionModel( selections );
}

void TreeView::setRootIndex( const QModelIndex& index )
{
    m_pTreeView->setRootIndex( index );
}

void TreeView::slotContextMenuRequested( const QPoint& pos )
{
    Q_ASSERT( m_pDataModel );
    
    qDebug() << "TreeView::slotContextMenuRequested(" << pos << ")";
    QModelIndex requested_index = m_pTreeView->indexAt( pos );
    if ( !requested_index.isValid() )
        return;
    
    contextMenuRequested( m_pDataModel, requested_index, m_pTreeView->mapToGlobal( pos ) );
}

void TreeView::slotSelectionChanged( const QItemSelection& selected, const QItemSelection& deselected )
{
    Q_UNUSED(selected);
    Q_UNUSED(deselected);
#if 1
    qDebug() << "Selection Changed:";
    qDebug() << "Selected  :" << selected;
    qDebug() << "DeSelected:" << deselected;
#endif
    
}

void TreeView::init()
{
    m_pTreeView = new QTreeView( this );
    m_pTreeView->setMouseTracking( true ); // Enable requesting of statusTip role on mouse enter event.
    m_pTreeView->setContextMenuPolicy( Qt::CustomContextMenu );
    // Enable drag'n'drop
    m_pTreeView->setDragEnabled( true );
    m_pTreeView->setAcceptDrops( true );
    m_pTreeView->setDropIndicatorShown( true );
    m_pTreeView->setDragDropMode( QAbstractItemView::InternalMove ); // Move data internally
    m_pTreeView->setSortingEnabled( false ); // Do not use sorting!
    connect( m_pTreeView, SIGNAL( customContextMenuRequested ( const QPoint& ) ),
            this, SLOT( slotContextMenuRequested( const QPoint& ) ) );
    
    
    // Use special delegate to influence the look and feel
    ModelElementDelegate* element_delegate = new ModelElementDelegate( this );
    m_pTreeView->setItemDelegate( element_delegate );
    
    QVBoxLayout* layout = new QVBoxLayout( this );
    layout->addWidget( m_pTreeView );
}

