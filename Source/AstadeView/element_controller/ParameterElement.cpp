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
#include "ParameterElement.h"

#include "Globals.h"
#include "ModelPropertyKeys.h"
#include "Elements.h"

ParameterElement::ParameterElement( QObject* parent )
{
	Q_UNUSED( parent );
}

QString ParameterElement::toString( StringOutputRole stringRole ) const
{
    Q_UNUSED( stringRole );
	return "<span style=\" color:#b22222;;\">" 
        + property( g_contextOperationCodingTypeKey ).toString() 
        + "</span> " 
        + property( g_contextInfoElementNameKey ).toString();
}

int ParameterElement::position()
{
    return property( g_contextInfoElementTypeKey ).toInt() & Elements::ET_ATTORDERMASK;
}


QStringList ParameterElement::publicProperties() const
{    
    QStringList properties;
    properties << Element::publicProperties();
    properties << g_contextOperationCodingTypeKey;
    
    return properties;
}

bool ParameterElement::isEditable() const
{
    return true;
}

bool ParameterElement::isDropable() const
{
    return false;
}

bool ParameterElement::isDragable() const
{
    return true;
}

bool ParameterElement::isReferenceToExternalElement() const
{
    return false;
}


void ParameterElement::orderChanged()
{
    int element_info = property( g_contextInfoElementTypeKey ).toInt() & ~Elements::ET_ATTORDERMASK;
    int new_info = element_info | posInChildrenList();
    setProperty( g_contextInfoElementTypeKey, new_info );
}
