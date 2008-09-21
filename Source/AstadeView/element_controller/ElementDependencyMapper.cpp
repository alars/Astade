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
#include "ElementDependencyMapper.h"

#include <QApplication>

// This implementation is currently static. Future implementations will provide
// dynamic adding of dependencies. Thus, we can add them while loading plugins to gain
// full dynamic dependencies by runtime..

ElementDependencyMapper* ElementDependencyMapper::instance = NULL;

ElementDependencyMapper& ElementDependencyMapper::self()
{
    if ( instance == NULL ){
        instance = new ElementDependencyMapper;
        instance->setParent( qApp );  // This factory should be destroyed if qApp dies.
    }
    
    return *instance;    
}

QList<ElementDependencyMapper::AddableElement> ElementDependencyMapper::addAbleElementsByType( Elements::ElementTypes type ) const
{
    return m_dependencyMap.value( type );
}

ElementDependencyMapper::ElementDependencyMapper()
{
    // Dependency to model element "components"
    AddableElement element = { tr( "Add Component" ), Elements::ET_COMPONENT };
    QList<AddableElement> element_list; 
    element_list.append( element );
	m_dependencyMap.insert( Elements::ET_COMPONENTS, element_list );
    
    // Dependency to model element "component"
    element_list.clear();
    AddableElement config_element = { tr( "Add Configuration" ), Elements::ET_CONFIGURATION };
    element_list.append( config_element );
    AddableElement usecase_element = { tr( "Add UseCase Diagrams" ), Elements::ET_USECASEDIAGRAMS };
    element_list.append( usecase_element );
    m_dependencyMap.insert( Elements::ET_COMPONENT, element_list );
    
    // Dependency to model element "root"
    element_list.clear();
    AddableElement package_element = { tr( "Add Package" ), Elements::ET_PACKAGE };
    element_list.append( package_element );
    AddableElement components_element = { tr( "Add Components" ), Elements::ET_COMPONENTS };
    element_list.append( components_element );
    m_dependencyMap.insert( Elements::ET_MODEL, element_list );

    // Dependency to model element "Package"
    element_list.clear();
    AddableElement rec_package_element = { tr( "Add Package" ), Elements::ET_PACKAGE };
    element_list.append( rec_package_element );
    AddableElement classes_element = { tr( "Add Classes" ), Elements::ET_CLASSES };
    element_list.append( classes_element );
    m_dependencyMap.insert( Elements::ET_PACKAGE, element_list );

    // Dependency to model element "Classes"
    element_list.clear();
    AddableElement class_element = { tr( "Add Class" ), Elements::ET_CLASS };
    element_list.append( class_element );
    m_dependencyMap.insert( Elements::ET_CLASSES, element_list );
    
    // Dependency to model element "Class"
    element_list.clear();
    AddableElement attributes_element = { tr( "Add Attributes" ), Elements::ET_ATTRIBUTES };
    element_list.append( attributes_element );
    AddableElement operations_element = { tr( "Add Operations" ), Elements::ET_OPERATIONS };
    element_list.append( operations_element );
    AddableElement types_element = { tr( "Add Types" ), Elements::ET_TYPES };
    element_list.append( types_element );
    m_dependencyMap.insert( Elements::ET_CLASS, element_list );
 
    // Dependency to model element "Operations"
    element_list.clear();
    AddableElement operation_element = { tr( "Add Operation" ), Elements::ET_OPERATION };
    element_list.append( operation_element );
//    AddableElement operation_element = { tr( "Add Classes" ), Elements::ET_CLASSES };
//    element_list.append( operation_element );
    m_dependencyMap.insert( Elements::ET_OPERATIONS, element_list );
    
#if 0
    // Dependency to model element "Attributes"
    element_list.clear();
    AddableElement operation_element = { tr( "Add Package" ), Elements::ET_PACKAGE };
    element_list.append( operation_element );
    AddableElement operation_element = { tr( "Add Classes" ), Elements::ET_CLASSES };
    element_list.append( operation_element );
    m_dependencyMap.insert( Elements::ET_PACKAGE, element_list );
#endif
}

