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
#ifndef PARAMETER_ELEMENT_H_
#define PARAMETER_ELEMENT_H_

#include "Element.h"

/**
 * Class to define the behavior of one parameter for methods.
 */ 
class ParameterElement: public Element
{
    Q_OBJECT
    Q_PROPERTY( int position READ position )
public:
    ParameterElement( QObject* parent );
    
    QString toString( StringOutputRole stringRole = Element::SOR_Default ) const;
    int position();  
    QStringList publicProperties() const;
    
    bool isEditable() const;
    bool isDropable() const;
    bool isDragable() const;
    bool isReferenceToExternalElement() const;
    
    /** Update internal order index */
    void orderChanged();
protected:
};

#endif // PARAMETER_ELEMENT_H_
