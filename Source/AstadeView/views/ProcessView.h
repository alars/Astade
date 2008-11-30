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
#ifndef ProcessView_H_
#define ProcessView_H_

#include <QObject>

class ProcessViewPrivate;

/**
 * View to monitor and handle all running processes.
 * This class is currently just a place holder for a future class that will visualize
 * all running processes.<br>
 * <br>
 * How to use: <br>
 * Use this class as parent for the process: new QProcesss( ProcessView::self() );
 */
class ProcessView : public QObject
{
    Q_OBJECT
public:
    static ProcessView* self();
    
protected:
    ProcessView();
    ~ProcessView();
    
private:
    static ProcessViewPrivate* d;
};

#endif //ProcessView_H_
