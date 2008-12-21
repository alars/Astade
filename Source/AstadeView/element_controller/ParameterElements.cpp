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
#include "ParameterElements.h"

#include <QStringList>
#include <QDebug>

#include "Globals.h"
#include "ModelPropertyKeys.h"
#include "AstadeDataModel.h"
#include "ParameterElement.h"

namespace
{
    // A parameter element has a fixed position. This position
    // is requested by the property mechanism.
    bool parameterLessThan(const QObject* o1, const QObject* o2 )
    {
        QVariant position_1 = o1->property( "position" );
        QVariant position_2 = o2->property( "position" );
        
        Q_ASSERT( position_1.isValid() );
        Q_ASSERT( position_2.isValid() );
        
        // This should never happen. But it should be save to ignore it.
        if ( !position_1.isValid() || !position_2.isValid() ){
            qWarning() << "ParameterElement does not return a position."
            "This may be an indication of an incorrect Model!"
            "We will ignore this and hope the best..";
            
            return false;
        }

        return ( position_1.toInt() < position_2.toInt() );
    }
}

ParameterElements::ParameterElements( QObject* parent )
{
	Q_UNUSED( parent );
}

bool ParameterElements::isEditable() const
{
    return false;
}

bool ParameterElements::isDropable() const
{
    return true;
}

bool ParameterElements::isDragable() const
{
    return true;
}

bool ParameterElements::isReferenceToExternalElement() const
{
    return false;
}

void ParameterElements::initElementProperties()
{
    Element::initElementProperties();
    
    setIsContainer( true );
    
    setFilePath( qobject_cast<Element*>( parent() )->filePath() + "/parameters" );
    setProperty( g_contextInfoElementNameKey, "Parameters" );
    setProperty( g_contextInfoElementTypeKey, Elements::ET_FOLDER | Elements::ET_PARAMETERS );
    
    // Save data.
    model()->slotCommit( model()->indexForElement( this ) );    
}

QString ParameterElements::toString( StringOutputRole stringRole ) const
{
    QString param_string;
    
    // Load all children to obtain the parameters. 
    model()->addChildrenToElement( const_cast<ParameterElements*>(this) ); //FIXME: Remove const cast.
    
    switch ( stringRole ){
        case Element::SOR_Internal:
        {
            QStringList parameters;
            QObjectList child_objects = children();
            QObject* child_object;
            foreach ( child_object, child_objects ){
                if ( child_object->inherits( "ParameterElement" ) ){
                    ParameterElement* param_element = qobject_cast<ParameterElement*>( child_object );
                    parameters.insert( param_element->position(), param_element->toString() );
                }
            }
        
            param_string = parameters.join( ", " );
        }
            break;
        default:
            param_string = tr( "Parameters" );
            break;
    }
	return param_string;
}

void ParameterElements::updateOrderOfChildren()
{
   qSort( d_ptr->children.begin(), d_ptr->children.end(), parameterLessThan );
}


