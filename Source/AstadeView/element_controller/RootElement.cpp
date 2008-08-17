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
#include "RootElement.h"

#include "AstadeDataModel.h"
#include "Elements.h"
#include "ModelPropertyKeys.h"

RootElement::RootElement( QObject* parent ): 
Element( parent )
{
}

bool RootElement::isReferenceToExternalElement() const
{
    return false;
}


void RootElement::initElementProperties()
{
    Element::initElementProperties();
    
    setIsContainer( true );

    setProperty( g_contextInfoElementNameKey, "Model" );
    setProperty( g_contextInfoElementTypeKey, Elements::ET_FOLDER | Elements::ET_MODEL );
    
    // Do not call commit! This element may be created before the initial setup was completed! 
    // This element will be saved on demand.
    // model()->slotCommit();
}
