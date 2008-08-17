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
#include "ClassesElement.h"

#include "ModelPropertyKeys.h"
#include "AstadeDataModel.h"

// TODO: Set the correct order of parameters.

ClassesElement::ClassesElement( QObject* parent )
{
	Q_UNUSED( parent );
}

bool ClassesElement::isEditable() const
{
    return false;
}

bool ClassesElement::isReferenceToExternalElement() const
{
    return false;
}

void ClassesElement::initElementProperties()
{
    Element::initElementProperties();
    
    setIsContainer( true );
    
    setFilePath( qobject_cast<Element*>( parent() )->filePath() + "/classes" );
    setProperty( g_contextInfoElementNameKey, "classes" );
    setProperty( g_contextInfoElementTypeKey, Elements::ET_FOLDER | Elements::ET_CLASSES );
    
    // Save data.
    model()->slotCommit( model()->indexForElement( this ) );    
}


QString ClassesElement::toString( StringOutputRole stringRole ) const
{
    Q_UNUSED( stringRole );
	return tr( "Classes" );
}

