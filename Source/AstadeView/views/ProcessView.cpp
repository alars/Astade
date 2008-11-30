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

#include "ProcessView.h"

#include <QApplication>

struct ProcessViewPrivate
{
    static ProcessView* m_pProcessView;
};

ProcessView* ProcessViewPrivate::m_pProcessView = NULL;
ProcessViewPrivate* ProcessView::d = NULL;

ProcessView::ProcessView()
{
    d = new ProcessViewPrivate;
}

ProcessView::~ProcessView()
{
}

ProcessView* ProcessView::self()
{
    if ( ( d == NULL ) || ( d->m_pProcessView == NULL ) )
    {
        ProcessView* process_view = new ProcessView; // Initializes D-Pointer!
        d->m_pProcessView = process_view;
        d->m_pProcessView->setParent( qApp );  // This factory should be destroyed if qApp dies.
    }
    
    Q_ASSERT( d->m_pProcessView );
    if ( !d->m_pProcessView )
    { qFatal( "ProcessView::self(): Out of memory!!" ); }
    
    return d->m_pProcessView;
    
}


