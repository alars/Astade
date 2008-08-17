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
#include "ColumnView.h"

#include <QDebug>
#include <QDirModel>
#include <QColumnView>
#include <QVBoxLayout>
#include <QSplitter>
#include <QPushButton>
#include <QAbstractItemModel>
#include <QAbstractItemDelegate>
#include <QMenu>

#include "Globals.h"
#include "AstadeDataModel.h"
#include "ModelElementDelegate.h"
#include "Element.h"

ColumnView::ColumnView( QWidget* parent ): 
AstadeView( parent ), 
m_pDataModel( NULL ), 
m_pColumnView( NULL )
{
    init();
}

void ColumnView::setModels( QAbstractItemModel* model, QItemSelectionModel *selections )
{
    m_pDataModel = model;
    connect( selections, SIGNAL( selectionChanged( const QItemSelection&, const QItemSelection& ) ),
            this, SLOT( slotSelectionChanged( const QItemSelection&, const QItemSelection& ) ) );
    
    m_pColumnView->setModel( m_pDataModel );
    m_pColumnView->setSelectionModel( selections );

}

void ColumnView::setRootIndex( const QModelIndex& index )
{
    m_pColumnView->setRootIndex( index );    
}


void ColumnView::slotContextMenuRequested( const QPoint& pos )
{
    Q_ASSERT( m_pDataModel );
    
    qDebug() << "ColumnView::slotContextMenuRequested(" << pos << ")";
    QModelIndex requested_index = m_pColumnView->indexAt( pos );
    if ( !requested_index.isValid() )
        return;
    
    contextMenuRequested( m_pDataModel, requested_index, m_pColumnView->mapToGlobal( pos ) );    
}

void ColumnView::slotSelectionChanged( const QItemSelection& selected, const QItemSelection& deselected )
{
    Q_UNUSED(selected);
    Q_UNUSED(deselected);
#if 0
    qDebug() << "Selection Changed:";
    qDebug() << "Selected  :" << selected;
    qDebug() << "DeSelected:" << deselected;
#endif
    
}

void ColumnView::init()
{
    m_pColumnView = new QColumnView( this ); 
    m_pColumnView->setMouseTracking( true ); // Enable requesting of statusTip role on mouse enter event.
    m_pColumnView->setContextMenuPolicy( Qt::CustomContextMenu );
    // Endable drag'n'drop
    m_pColumnView->setDragEnabled( true );
    m_pColumnView->setAcceptDrops( true );
    m_pColumnView->setDropIndicatorShown( true );
    m_pColumnView->setDragDropMode( QAbstractItemView::InternalMove ); // Move data internally
    connect( m_pColumnView, SIGNAL( customContextMenuRequested ( const QPoint& ) ),
            this, SLOT( slotContextMenuRequested( const QPoint& ) ) );
    
    // Use special delegate to influence the look and feel
    ModelElementDelegate* element_delegate = new ModelElementDelegate( this );
    m_pColumnView->setItemDelegate( element_delegate );
    
    QVBoxLayout* layout = new QVBoxLayout( this );
    layout->addWidget( m_pColumnView );
    
}

