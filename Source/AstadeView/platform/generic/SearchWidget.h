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
#ifndef SearchWidget_H_
#define SearchWidget_H_
#include <QWidget>

class QLineEdit;

class SearchWidget: public QWidget
{
    Q_OBJECT
public:
    SearchWidget( QWidget* parent = NULL );
    
signals:
    void signalTextChanged( const QString& text );
    void signalStopClicked();

protected slots:
    void slotStopPressed();
    
private:
    QLineEdit* m_pEditField;
};

#endif // SearchWidget_H_
