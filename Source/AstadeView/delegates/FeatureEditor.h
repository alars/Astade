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
#ifndef FEATURE_EDITOR_H_
#define FEATURE_EDITOR_H_

#include <QWidget>

#include "ui_FeatureEditor.h"

class Element;
class FeatureEditor: public QWidget, private Ui::FeatureEditor
{
    Q_OBJECT
public:
    FeatureEditor( QWidget* parent = NULL, Qt::WindowFlags f = 0 );
    void setElement( Element* element ); 
    QMap<QString, QVariant> changedProperties();
};

#endif // FEATURE_EDITOR_H_
