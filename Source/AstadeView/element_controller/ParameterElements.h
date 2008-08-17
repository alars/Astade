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
#ifndef PARAMETER_ELEMENTS_H_
#define PARAMETER_ELEMENTS_H_

#include "Element.h"

/**
 * Class to define the behavior of parameters for methods.
 */ 
class ParameterElements: public Element
{
    Q_OBJECT
public:
    ParameterElements( QObject* parent );

    bool isEditable() const;
    bool isDragable() const;
    bool isDropable() const;
    bool isReferenceToExternalElement() const;
    void initElementProperties();
    
    QString toString( StringOutputRole stringRole = Element::SOR_Default ) const;
    
    /** Puts the parameters into the correct order */
    void updateOrderOfChildren();
    
protected:
};

#endif // PARAMETER_ELEMENTS_H_
