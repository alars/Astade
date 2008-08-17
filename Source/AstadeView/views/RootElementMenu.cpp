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
#include "RootElementMenu.h"

#include <QModelIndex>

#include "AstadeDataModel.h"
#include "Element.h"

RootElementMenu::RootElementMenu( QWidget* parent ): 
QMenu( parent ), 
m_pModel( NULL )
{
    init();
}

RootElementMenu::RootElementMenu( const QString & title, AstadeDataModel* model, QWidget * parent):
QMenu( title, parent ),
m_pModel( model )
{
	init();
}

RootElementMenu::~RootElementMenu()
{
	// Empty
}

void RootElementMenu::setModel( AstadeDataModel* model )
{
    m_pModel = model;
}

void RootElementMenu::init()
{
	connect( this, SIGNAL( aboutToShow() ), this, SLOT( slotAboutToShow() ) );
}

void RootElementMenu::slotAboutToShow()
{
    clear(); // Should delete the contained actions.
	if ( !m_pModel )
    {
        addAction( tr( "No Menu available! " ) );
        return;
    }
    
    // Get root element and get list of actions..
    Element* element = m_pModel->elementForIndex( QModelIndex() );
    addActions( element->supportedActions() );
}

