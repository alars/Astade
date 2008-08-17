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
#include "AstadeView.h"

#include <QDebug>
#include <QModelIndex>
#include <QAbstractProxyModel>

#include <QMenu>

#include "AstadeDataModel.h"
#include "Element.h"


AstadeView::AstadeView( QWidget* parent ): QWidget( parent )
{
}

AstadeDataModel* AstadeView::obtainAstadeModelForModel( QAbstractItemModel* model ) const
{
    // Expect that the Astade data model is the current model or the source model (if it is a proxy model)
    // Try to find it..
    AstadeDataModel* astade_model = qobject_cast<AstadeDataModel*>( model );
    if ( !astade_model )
    {
        const QAbstractProxyModel* proxy_model = qobject_cast<const QAbstractProxyModel*>( model );
        astade_model = qobject_cast<AstadeDataModel*>( proxy_model->sourceModel() );
    }
    
    return astade_model;
}

void AstadeView::contextMenuRequested( QAbstractItemModel* model, 
                                      const QModelIndex& requestedIndex, 
                                      const QPoint& pos )
{
    // Expect that the Astade data model is the current model or the source model (if it is a proxy model)
    // Try to find it..
    AstadeDataModel* astade_model = obtainAstadeModelForModel( model );
    QModelIndex requested_source_index = convertProxyModelIndexToAstadeDataModelIndex( model, requestedIndex );
    if ( !astade_model )
    {
        qWarning() << "Unable to access Astade data model. It may be hidden behind a proxy model. No context menu access is possible!";
        return;
    }    
    
    Element* requested_element = astade_model->elementForIndex( requested_source_index );
    Q_ASSERT( requested_element );
    QList<QAction* > supported_actions = requested_element->supportedActions(); 
    
    if ( supported_actions.isEmpty() )
        return;
    
    QMenu context_menu( tr( "Context for Element" ), this );
    context_menu.addActions( supported_actions );
    context_menu.exec( pos ); 
    
    // Delete Actions
    foreach( QAction* action, supported_actions )
    {
        delete action;
    }
}

QModelIndex AstadeView::convertProxyModelIndexToAstadeDataModelIndex( QAbstractItemModel* dataModel, 
                                                                     const QModelIndex& proxyIndex ) const
{
    // Expect that the Astade data model is the current model or the source model (if it is a proxy model)
    // Try to find it..
    AstadeDataModel* astade_model = qobject_cast<AstadeDataModel*>( dataModel );
    QModelIndex requested_source_index;
    if ( astade_model )
    { requested_source_index = proxyIndex; }
    if ( !astade_model )
    {
        QAbstractProxyModel* proxy_model = qobject_cast<QAbstractProxyModel*>( dataModel );
        astade_model = qobject_cast<AstadeDataModel*>( proxy_model->sourceModel() );
        if ( astade_model )
        { requested_source_index = proxy_model->mapToSource( proxyIndex ); }
    }
    return requested_source_index;
}