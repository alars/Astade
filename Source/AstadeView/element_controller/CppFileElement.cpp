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
#include "CppFileElement.h"

#include <QUuid>

#include "Globals.h"
#include "ModelPropertyKeys.h"

CppFileElement::CppFileElement( QObject* parent ):
Element( parent )
{
	
}

void CppFileElement::setElementName( const QString& name )
{
    setProperty( g_contextInfoElementNameKey, name );
}

QList<QAction* > CppFileElement::supportedActions()
{
    QList<QAction* > ret_list( Element::supportedActions() );
    
    QAction* open_action = new QAction( tr( "&Open File" ), NULL );
    ret_list.append( open_action );
    connect( open_action, SIGNAL( triggered() ), this, SLOT( slotEdit() ) );    
    
    return ret_list;
}


bool CppFileElement::isEditable() const
{
	return false;
}

// Important to return true here. Otherwise an ini file will be saved for this external element.
bool CppFileElement::isReferenceToExternalElement() const
{
	return true;
}

QString CppFileElement::toString( StringOutputRole stringRole) const
{
    Q_UNUSED( stringRole );
	return property( g_contextInfoElementNameKey ).toString();
}

void CppFileElement::initElementProperties()
{
    Element::initElementProperties();

    setIsContainer( false );    
    setProperty( g_contextInfoElementTypeKey, Elements::ET_CPPFILE );
}


