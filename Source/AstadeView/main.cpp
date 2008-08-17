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
#include <QApplication>

#include "MainWindow.h"

#ifdef DEBUG_CONSOLE_
#  include "uidebugconsole.h"
#endif

const char* GetCharArrayFromQString( const QString &qstr, int id )
{
    Q_UNUSED( id );
	return qPrintable(qstr);
}

int main(int argc, char** argv) {
	QApplication app(argc,argv);
    
#ifdef DEBUG_CONSOLE_    
    UiDebugConsole *udc = new UiDebugConsole;
    Q_UNUSED( udc );
#endif
    
	MainWindow mw( NULL );
	mw.show();
	return app.exec();
}
