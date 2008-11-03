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
#ifndef OPERATION_ELEMENT_H_
#define OPERATION_ELEMENT_H_

#include "Element.h"

/**
 * Class to define the behavior of operations (aka. functions).
 */ 
class OperationElement: public Element
{
    Q_OBJECT
public:
    enum MemberScope{
        MS_MASK             = 0x0000E00,
        MS_PUBLIC			= 0x0000200,
        MS_PROTECTED		= 0x0000400,
        MS_PRIVATE			= 0x0000800,
    };        

    enum MemberTypes{
        MT_NONE             = 0x00000000,
        MT_VIRTUAL          = 0x00000001,
        MT_FIRSTTYPE        = MT_VIRTUAL,  // Keep this updated
        MT_ABSTRACT         = 0x00000002,
        MT_STATIC           = 0x00000004,
        MT_CONST            = 0x00000008,
        MT_INLINE           = 0x00000010,
        MT_CONSTRUCTOR      = 0x00000020,
        MT_DESTRUCTOR       = 0x00000040,
        MT_QTSIGNAL         = 0x00000080,
        MT_QTSLOT           = 0x00000100,
        MT_LAST             = 0x00000200   // Keep this updated!
    };
    
    OperationElement( QObject* parent );
    
    QString toString( StringOutputRole stringRole = Element::SOR_Default ) const;
    
    QStringList publicProperties() const;
    QList<QAction* > supportedActions() const;
    
    bool isEditable() const;
    bool isReferenceToExternalElement() const;
    
    MemberScope memberScope() const;
    MemberTypes memberTypes() const;
    
    void initElementProperties();

    
protected slots:
    void slotMakePublic();
    void slotMakeProtected();
    void slotMakePrivate();
    
};

#endif // OPERATION_ELEMENT_H_
