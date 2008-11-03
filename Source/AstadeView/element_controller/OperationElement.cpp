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
#include "OperationElement.h"

#include <QDebug>
#include <QObjectList>
#include <QUuid>
#include <QFile>

#include "globals.h"
#include "ModelPropertyKeys.h"
#include "AstadeDataModel.h"
#include "ParameterElements.h"
#include "CppFileElement.h"
#include "ElementFactory.h"

namespace{
    const char* g_constructorName = "constructor";
    const char* g_destructorName  = "destructor";
    const char* g_codeFileName    = "code.cpp";
    const char* g_startCode       = "//// Enter your code here!";
}

OperationElement::OperationElement( QObject* parent ): Element( parent )
{
	
}

QString OperationElement::toString( StringOutputRole stringRole ) const
{
    Q_UNUSED( stringRole );
    
    QString ret_string;
    
    QString return_type = property( g_contextOperationCodingTypeKey ).toString();
    QString operation_name = property( g_contextInfoElementNameKey ).toString();
    
    // The constructor and destructor has the name of the class type.
    if ( ( operation_name == g_constructorName ) || ( operation_name == g_destructorName ) ){
        QObject* first_parent = parent();
        Q_ASSERT( first_parent );
        Element* class_element = qobject_cast<Element*>(first_parent->parent());
        if ( class_element )
        {
            operation_name = class_element->property( g_contextInfoElementNameKey ).toString();
        }
    }
             
         
    MemberScope scope = memberScope();
    switch ( scope ){
        case MS_PUBLIC:
            ret_string = "+";
            break;
        case MS_PRIVATE:
            ret_string = "-";
            break;
        case MS_PROTECTED:
            ret_string = "#";
            break;
        default:
            // ignore
            break;
    };
    
    // Load all children to obtain the parameters. 
    model()->addChildrenToElement( const_cast<OperationElement*>(this) ); //FIXME: Remove const cast.
    
    // Get all parameters from list..
    QString parameters;
    QObjectList child_objects = children();
    QObject* child_object;
    foreach ( child_object, child_objects ){
        if ( child_object->inherits( "ParameterElements" ) ){
            parameters += qobject_cast<ParameterElements*>( child_object )->toString( Element::SOR_Internal );
        }
    }

    ret_string += "  <span style=\" color:#0000ff;\">" 
        + operation_name 
        + "</span>( " 
        + parameters 
        + " )";

    if ( !return_type.isEmpty() )
        ret_string +=  ": " 
            + QString( "<span style=\" color:#b22222;;\">" )
            + return_type 
            + "</span>";
    
    return ret_string;
    
}

QStringList OperationElement::publicProperties() const
{
    QStringList properties;
    properties << Element::publicProperties()
        << g_contextOperationCodingTypeKey
        << g_contextOperationVirtualKey 
        << g_contextOperationAbstractKey 
        << g_contextOperationStaticKey 
        << g_contextOperationConstKey 
        << g_contextOperationInlineKey
        << g_contextOperationRetDescriptionKey;
    
    return properties;
}

QList<QAction* > OperationElement::supportedActions() const
{
    QList<QAction* > ret_list( Element::supportedActions() );
    qDebug() << "Operation Member Scope: " << memberScope();
    QAction* public_action = new QAction( tr( "&Public" ), NULL );
    public_action->setCheckable( true );
    public_action->setChecked( memberScope() == MS_PUBLIC );
    ret_list.append( public_action );

    QAction* protected_action = new QAction( tr( "P&rotected" ), NULL );
    protected_action->setCheckable( true );
    protected_action->setChecked( memberScope() == MS_PROTECTED );
    ret_list.append( protected_action );

    QAction* private_action = new QAction( tr( "Pr&ivate" ), NULL );
    private_action->setCheckable( true );
    private_action->setChecked( memberScope() == MS_PRIVATE );
    ret_list.append( private_action );
    
    QAction* separator = new QAction( "", NULL );
    separator->setSeparator( true );
    ret_list.append( separator );

    connect( public_action, SIGNAL( triggered() ), this, SLOT( slotMakePublic() ) );        
    connect( protected_action, SIGNAL( triggered() ), this, SLOT( slotMakeProtected() ) );        
    connect( private_action, SIGNAL( triggered() ), this, SLOT( slotMakePrivate() ) );        
    
    return ret_list;
}


bool OperationElement::isEditable() const
{
    return true;
}

bool OperationElement::isReferenceToExternalElement() const
{
    return false;
}


OperationElement::MemberScope OperationElement::memberScope() const
{
    return static_cast<MemberScope>(property(g_contextInfoElementTypeKey).toInt() 
                                    & MS_MASK );

}

OperationElement::MemberTypes OperationElement::memberTypes() const
{
    int ret_types = MT_NONE;
    
    if ( property( g_contextOperationVirtualKey ).toString() == "yes" )
    {
        ret_types |= MT_VIRTUAL;
    }
    if ( property( g_contextOperationAbstractKey ).toString() == "yes" )
    {
        ret_types |= MT_ABSTRACT;
    }
    if ( property( g_contextOperationStaticKey ).toString() == "yes" )
    {
        ret_types |= MT_STATIC;
    }
    if ( property( g_contextOperationConstKey ).toString() == "yes" )
    {
        ret_types |= MT_CONST;
    }
    if ( property( g_contextOperationInlineKey ).toString() == "yes" )
    {
        ret_types |= MT_INLINE;
    }
    if ( property( g_contextInfoElementNameKey ) == g_constructorName )
    {
        ret_types |= MT_CONSTRUCTOR;
    }
    if ( property( g_contextInfoElementNameKey ) == g_destructorName )
    {
        ret_types |= MT_DESTRUCTOR;
    }
    
    
    
    return static_cast<OperationElement::MemberTypes>( ret_types );
}

void OperationElement::initElementProperties()
{
    Element::initElementProperties();
    
    setIsContainer( true );
    
    setFilePath( qobject_cast<Element*>( parent() )->filePath() + "/operation_" + QString::number( QUuid::createUuid().data1 ) );
    setProperty( g_contextInfoElementNameKey, "New Operation" );
    setProperty( g_contextInfoElementTypeKey, Elements::ET_FOLDER | Elements::ET_OPERATION | Elements::ET_NORMALOP | OperationElement::MS_PUBLIC );

    // Create file "code.cpp"
    QFile code_file( filePath() + "/" + g_codeFileName );
    if ( !code_file.exists() )
    {
        code_file.open( QIODevice::WriteOnly );
        code_file.write( g_startCode, qstrlen( g_startCode ) );
        code_file.flush();
        code_file.close();
    }
    
    // Create element for code.cpp
    CppFileElement* code_element = qobject_cast<CppFileElement*>( ElementFactory::self().newObject( Elements::ET_CPPFILE, model() ) );
    
    model()->addChildToElement( code_element, model()->indexForElement( this ) );
    code_element->initElementProperties();
    code_element->setElementName( g_codeFileName );
    code_element->setFilePath( filePath() + "/" + g_codeFileName );
    
    // Save data.
    model()->slotCommit( model()->indexForElement( this ) );    
}

// Slots
void OperationElement::slotMakePublic()
{
    setProperty( g_contextInfoElementTypeKey, ( property( g_contextInfoElementTypeKey ).toInt() & ~MS_MASK ) | MS_PUBLIC );
    setModified( true );
    model()->slotCommit( model()->indexForElement( this ) );
}

void OperationElement::slotMakeProtected()
{
    setProperty( g_contextInfoElementTypeKey, ( property( g_contextInfoElementTypeKey ).toInt() & ~MS_MASK ) | MS_PROTECTED );
    setModified( true );
    model()->slotCommit( model()->indexForElement( this ) );
}

void OperationElement::slotMakePrivate()
{
    setProperty( g_contextInfoElementTypeKey, ( property( g_contextInfoElementTypeKey ).toInt() & ~MS_MASK ) | MS_PRIVATE );
    setModified( true );
    model()->slotCommit( model()->indexForElement( this ) );
}




