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
#include "ElementFactory.h"

#include <QApplication>

#include "OperationsElement.h"
#include "OperationElement.h"
#include "ParameterElements.h"
#include "ParameterElement.h"
#include "ClassesElement.h"
#include "ClassElement.h"
#include "ComponentsElement.h"
#include "ComponentElement.h"
#include "ConfigurationElement.h"
#include "PackageElement.h"
#include "FilesElement.h"
#include "CppFileElement.h"
#include "HFileElement.h"
#include "RootElement.h"

ElementFactory* ElementFactory::instance = NULL;

ElementFactory& ElementFactory::self()
{
	if ( instance == NULL ){
        instance = new ElementFactory;
        instance->setParent( qApp );  // This factory should be destroyed if qApp dies.
    }
    
    Q_ASSERT( instance );
    if ( !instance )
    { qFatal( "ElementFactory::self(): Out of memory!!" ); }
    
    return *instance;
}

Element* ElementFactory::newObject( Elements::ElementTypes type, AstadeDataModel* containingModel )
{
    Element* ret_element = NULL;
	switch ( type ){
        case Elements::ET_OPERATION:
            ret_element = new OperationElement( this );
            break;
        case Elements::ET_PARAMETERS:
            ret_element = new ParameterElements( this );
            break;
        case Elements::ET_PARAMETER:
            ret_element = new ParameterElement( this );
            break;
        case Elements::ET_OPERATIONS:
            ret_element = new OperationsElement( this );
            break;
        case Elements::ET_CLASSES:
            ret_element = new ClassesElement( this );
            break;
        case Elements::ET_CLASS:
            ret_element = new ClassElement( this );
            break;
        case Elements::ET_COMPONENTS:
            ret_element = new ComponentsElement( this );
            break;
        case Elements::ET_COMPONENT:
            ret_element = new ComponentElement( this );
            break;
        case Elements::ET_CONFIGURATION:
            ret_element = new ConfigurationElement( this );
            break;
        case Elements::ET_PACKAGE:
            ret_element = new PackageElement( this );
            break;
        case Elements::ET_FILES:
            ret_element = new FilesElement( this );
            break;
        case Elements::ET_CPPFILE:
            ret_element = new CppFileElement( this );
            break;
        case Elements::ET_HFILE:
            ret_element = new HFileElement( this );
            break;
        case Elements::ET_MODEL:
            ret_element = new RootElement( this );
            break;            
        default:
            // Use generic element
            ret_element = new Element( this );
            break;
    }
    
    // Initialize..
    ret_element->setDataBaseModel( containingModel );
    
    return ret_element;
}

