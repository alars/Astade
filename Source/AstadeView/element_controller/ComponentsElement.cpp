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
#include "ComponentsElement.h"

#include <QUuid>

#include "Globals.h"
#include "ModelPropertyKeys.h"
#include "AstadeDataModel.h"

ComponentsElement::ComponentsElement( QObject* parent ):
Element( parent )
{
	
}

QList<QAction* > ComponentsElement::supportedActions() const
{
    QList<QAction* > ret_list( Element::supportedActions() );

    return ret_list;
}


bool ComponentsElement::isEditable() const
{
	return true;
}

bool ComponentsElement::isReferenceToExternalElement() const
{
	return false;
}

QString ComponentsElement::toString( StringOutputRole stringRole) const
{
    Q_UNUSED( stringRole );
	return property( g_contextInfoElementNameKey ).toString();
}

void ComponentsElement::initElementProperties()
{
    Element::initElementProperties();
    
    // This element contains other elements. Thus, it is constructed as directory.
    setIsContainer( true );
    setFilePath( qobject_cast<Element*>( parent() )->filePath() + "/components_" + QString::number( QUuid::createUuid().data1 ) );

    setProperty( g_contextInfoElementNameKey, "New Components" );
    setProperty( g_contextInfoElementTypeKey, Elements::ET_FOLDER | Elements::ET_COMPONENTS );
    
    // Save data.
    model()->slotCommit( model()->indexForElement( this ) );
}
