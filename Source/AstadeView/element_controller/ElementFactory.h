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
#ifndef ELEMENT_FACTORY_H_
#define ELEMENT_FACTORY_H_

#include <QObject>

#include "Elements.h"
#include "Element.h"

class AstadeDataModel;

/**
 * Class to create elements of a given type.
 * TODO: Allow to register foreign element types
 */
class ElementFactory: public QObject
{
    Q_OBJECT
public:
    static ElementFactory& self();
    
    /** 
     * Creates and returns an element of given type. The parent of the created object is this factory.
     * This factory inserts the pointer of the containing model into the element.
     * @param type Element type to create
     * @param containingModel Pointer to the model that contains this element.
     * @return Created and initialized element.
     */
    virtual Element* newObject( Elements::ElementTypes type, AstadeDataModel* containingModel );
    
protected:
    ElementFactory() {}
    
private:
    static ElementFactory* instance;
};


#endif
