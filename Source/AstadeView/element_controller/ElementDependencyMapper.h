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
#ifndef ElementDependencyMapper_h_
#define ElementDependencyMapper_h_

#include "ElementDependencyMapper.h"

#include <QObject>
#include <QMap>

#include "Elements.h"

/**
 * Handles the dependency between model elements.
 * If a model element wants to be added by an other element, it has
 * to register itself to this class 
 */
class ElementDependencyMapper: public QObject
{
    Q_OBJECT
public:
    /**
     * Structure to define an element that may be added by a given element type.
     */
    struct AddableElement{
        /** Text that should be displayed to the user. This is usually used for menu entries */
        QString contextText;
        /** Element type that can be added */
        Elements::ElementTypes child_type;
    };

    static ElementDependencyMapper& self();
    
    /**
     * Returns which model elements can be added by the given element type.
     * @param type Element type of the requesting element.
     * @return A list of elements which can be added to the element of type <i>type</i>
     */
    QList<AddableElement> addAbleElementsByType( Elements::ElementTypes type ) const;

protected:
    ElementDependencyMapper();

private:
    static ElementDependencyMapper* instance;
    QMap<Elements::ElementTypes, QList<AddableElement> > m_dependencyMap;
};

#endif // ElementDependencyMapper_h_
