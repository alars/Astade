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
#ifndef ProxyModel_H_
#define ProxyModel_H_

#include <QSortFilterProxyModel>

/** Custom filter proxy to filter the content */
class ProxyModel : public QSortFilterProxyModel {
    Q_OBJECT
public:
    ProxyModel( QObject * parent = 0 );
    
    virtual bool filterAcceptsRow ( int source_row, const QModelIndex & source_parent ) const;
#if 0
    virtual bool lessThan ( const QModelIndex & left, const QModelIndex & right ) const;
#endif
};


#endif // ProxyModel_H_
