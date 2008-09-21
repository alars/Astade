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
#include "PackageElement.h"

#include <QUuid>

#include "AstadeDataModel.h"
#include "Globals.h"
#include "ModelPropertyKeys.h"

PackageElement::PackageElement( QObject* parent ):
Element( parent )
{
	
}

bool PackageElement::isEditable() const
{
	return true;
}

bool PackageElement::isReferenceToExternalElement() const
{
	return false;
}

void PackageElement::initElementProperties()
{
    Element::initElementProperties();
    
    setIsContainer( true );

    setFilePath( qobject_cast<Element*>( parent() )->filePath() + "/Package_" + QString::number( QUuid::createUuid().data1 ) );
    setProperty( g_contextInfoElementNameKey, "New Package" );
    setProperty( g_contextInfoElementTypeKey, Elements::ET_FOLDER | Elements::ET_PACKAGE );
    
    // Save data.
    model()->slotCommit( model()->indexForElement( this ) );    
}

QString PackageElement::toString( StringOutputRole stringRole) const
{
    Q_UNUSED( stringRole );
    return property( g_contextInfoElementNameKey ).toString();
}


