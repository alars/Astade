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
#include "FilesElement.h"

#include <QUuid>

#include "Globals.h"
#include "ModelPropertyKeys.h"

FilesElement::FilesElement( QObject* parent ):
Element( parent )
{
	
}

void FilesElement::setElementName( const QString& name )
{
    setProperty( g_contextInfoElementNameKey, name );
}

QList<QAction* > FilesElement::supportedActions()
{
    QList<QAction* > ret_list( Element::supportedActions() );

    return ret_list;
}


bool FilesElement::isEditable() const
{
	return true;
}

bool FilesElement::isReferenceToExternalElement() const
{
	return false;
}

QString FilesElement::toString( StringOutputRole stringRole) const
{
    Q_UNUSED( stringRole );
	return property( g_contextInfoElementNameKey ).toString();
}

void FilesElement::initElementProperties()
{
    Element::initElementProperties();
    
    // This element contains other elements. Thus, it is constructed as directory.
    setIsContainer( true );
    setFilePath( qobject_cast<Element*>( parent() )->filePath() + "/files_" + QUuid::createUuid().toString() );

    setProperty( g_contextInfoElementNameKey, "Files" );
    setProperty( g_contextInfoElementTypeKey, Elements::ET_FOLDER | Elements::ET_FILES );
}