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
#include "Iconprovider.h"

#include <QDebug>
#include <QPixmap>
#include <QPainter>

#include <Elements.h>
#include <Element.h>
#include <OperationElement.h>

namespace {
    const int g_pixmapWidth  = 26;
    const int g_pixmapHeight = 20;
}

QIcon IconProvider::iconForType( const Element* element )
{
    Q_ASSERT( element );
    if ( !element )
    {
        qWarning() << "IconProvider::iconForType: Paremeter is NULL. Ignored!";
        return QIcon();
    }

    QString icon_name;
    QStringList overlay_icon_names;

    switch ( element->type() ) {
        case Elements::ET_CLASSES:
        case Elements::ET_CLASS:
            icon_name = ":Elements/class.png";
            break;
        case Elements::ET_MODEL:
            icon_name = ":Elements/model.png";
            break;
        case Elements::ET_COMPONENTS:
        case Elements::ET_COMPONENT:
            icon_name = ":Elements/component.png";
            break;
        case Elements::ET_CONFIGURATION:
            icon_name = ":Elements/configuration.png";
            break;
//        case Elements::ET_DEPENDENCY:
//            icon_name = ":Elements/";
//            break;
        case Elements::ET_ATTRIBUTES:
            icon_name = ":Elements/attribute.png";
            break;
        case Elements::ET_OPERATIONS:
            icon_name = ":Elements/operation.png";
            break;
        case Elements::ET_OPERATION:{
            const OperationElement* op_element = qobject_cast<const OperationElement*>( element );
            Q_ASSERT( op_element );

            switch( op_element->memberScope() )
            {
                case OperationElement::MS_PUBLIC:
                    icon_name = ":Elements/public.png";
                    break;
                case OperationElement::MS_PRIVATE:
                    icon_name = ":Elements/private.png";
                    break;
                case OperationElement::MS_PROTECTED:
                    icon_name = ":Elements/protected.png";
                    break;
                default:
                    icon_name = ":Elements/deprecated.png";
                    break;
            }
            for( int mask = OperationElement::MT_FIRSTTYPE; mask < OperationElement::MT_LAST; mask <<= 1 )
            {
                switch( op_element->memberTypes() & mask )
                {
                    case  OperationElement::MT_NONE:
                        // IGNORE
                        break;
                    case OperationElement::MT_CONST:
                        overlay_icon_names << ":Elements/const.png";
                        break;
                    case OperationElement::MT_INLINE:
                        overlay_icon_names << ":Elements/inline.png";
                        break;
                    case OperationElement::MT_STATIC:
                        overlay_icon_names << ":Elements/static.png";
                        break;
                    case OperationElement::MT_VIRTUAL:
                        overlay_icon_names << ":Elements/virtual.png";
                        break;
                    case OperationElement::MT_ABSTRACT:
                        overlay_icon_names << ":Elements/abstract.png";
                        break;
                    case OperationElement::MT_CONSTRUCTOR:
                        overlay_icon_names << ":Elements/constructor.png";
                        break;
                    case OperationElement::MT_DESTRUCTOR:
                        overlay_icon_names << ":Elements/destructor.png";
                        break;
                    default:
                        qWarning() << "No icon for member type" << QString::number( op_element->memberTypes() & mask, 16 ) << "available!";
                        break;
                }
            }

        }
            break;
        case Elements::ET_PACKAGE:
            icon_name = ":Elements/package.png";
            break;
        case Elements::ET_WEBSITE:
            icon_name = ":Elements/website.png";
            break;
        case Elements::ET_PARAMETERS:
            icon_name = ":Elements/parameter.png";
            break;
        case Elements::ET_RELATIONS:
        case Elements::ET_RELATION:
        case Elements::ET_INRELATION:
            icon_name = ":Elements/relation.png";
            break;
        case Elements::ET_FILES:
            icon_name = ":Elements/file.png";
            break;
        case Elements::ET_HFILE:
            icon_name = ":Elements/h.png";
            break;
        case Elements::ET_CPPFILE:
            icon_name = ":Elements/cpp.png";
            break;
        case Elements::ET_MAKE:
            icon_name = ":Elements/make.png";
            break;
        case Elements::ET_TYPES:
        case Elements::ET_TYPE:
            icon_name = ":Elements/type.png";
            break;
        case Elements::ET_STATECHART:
            icon_name = ":Elements/statechart.png";
            break;
        case Elements::ET_STATE:
            icon_name = ":Elements/state.png";
            break;
        case Elements::ET_TRANSITION:
            icon_name = ":Elements/transition.png";
            break;
        case Elements::ET_USECASEDIAGRAMS:
            icon_name = ":Elements/usecasediagram.png";
            break;
//        case Elements::ET_ACTIVITYDIAGRAMS:
//            icon_name = ":Elements/";
//            break;
        case Elements::ET_SEQUENCES:
        case Elements::ET_SEQUENCE:
            icon_name = ":Elements/sequence.png";
            break;
        case Elements::ET_DOXFILE:
            icon_name = ":Elements/doxygen.png";
            break;
        case Elements::ET_USECASE:
            icon_name = ":Elements/usecasediagram.png";
            break;
        case Elements::ET_FILE:
            icon_name = ":Elements/file.png";
            break;

            // Do not show anything
        case Elements::ET_ATTRIBUTE:
        case Elements::ET_PARAMETER:
            icon_name = "";
            break;

        case Elements::ET_UNKNOWN:
        default:
            icon_name = ":Elements/depricated.png";
        break;
    }

    // Base pixmap can be overridden by element.
    QPixmap composition_pixmap;
    QPixmap base_pixmap = element->decorationPixmap();
    if ( base_pixmap.isNull() )
    {
        composition_pixmap.load( icon_name );
    }
    else
    {
        composition_pixmap = base_pixmap;
    }

    composition_pixmap = composition_pixmap.scaled( g_pixmapWidth, g_pixmapHeight, Qt::KeepAspectRatio );
    foreach ( QString overlay_icon_name, overlay_icon_names )
    {
        if ( !overlay_icon_name.isEmpty() )
        {
            QPixmap overlay_pixmap( overlay_icon_name );

            // Use QPainter to overlay two pixmaps.
            QPainter painter( &composition_pixmap );
            QRect overlay_rect( overlay_pixmap.rect() );

            // The overlay image alignment should be lower-right
            QRect paint_rect( composition_pixmap.rect() );
            int vert_move = composition_pixmap.height() - overlay_pixmap.height();
            int hor_move  = composition_pixmap.width() - overlay_pixmap.width();
            overlay_rect.adjust( hor_move, vert_move, hor_move, vert_move );

            painter.drawPixmap( overlay_rect, overlay_pixmap, overlay_pixmap.rect() );
            //        painter.setPen( Qt::green );
            //        painter.drawRect( overlay_rect );

        }
    }
    return QIcon( composition_pixmap );

}
