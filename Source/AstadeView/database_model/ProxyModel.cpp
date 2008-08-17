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
#include "ProxyModel.h"

#include <QDebug>

#include "AstadeDataModel.h"

#include "Elements.h"
#include "Element.h"


ProxyModel::ProxyModel( QObject * parent ): QSortFilterProxyModel( parent )
{
}

bool ProxyModel::filterAcceptsRow ( int source_row, const QModelIndex & source_parent ) const
{    
    if ( filterRegExp().isEmpty() )
        return true;

    AstadeDataModel* astade_model = qobject_cast<AstadeDataModel*>( sourceModel() );
    
    // If the undelying model is _not_ the astade model, we will not filter anything..
    if ( !astade_model )
        return true;
    
    Element* parent_element = astade_model->elementForIndex( source_parent );
    if ( !parent_element )
        return false;
    
    Element* row_element = qobject_cast<Element*>( parent_element->children().at( source_row ) );
    if ( !row_element )
        return false;
    
    return row_element->contains( filterRegExp().pattern() );
}

#if 0
bool ProxyModel::lessThan ( const QModelIndex & left, const QModelIndex & right ) const
{
    if ( sourceModel()->data( left ).toInt() == -1 )
        return false;
    return QSortFilterProxyModel::lessThan( left, right );
}
#endif