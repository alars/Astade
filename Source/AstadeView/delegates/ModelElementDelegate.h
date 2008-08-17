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
#ifndef MODEL_ELEMENT_DELEGATE_H_
#define MODEL_ELEMENT_DELEGATE_H_

#include <QItemDelegate>
#include <QPointer>
#include <QModelIndex>
#include <QStyleOptionViewItem>
#include <QRect>

class QPainter;
class QTextDocument;
class ModelElementDelegate: public QItemDelegate
{
    Q_OBJECT
public:
    ModelElementDelegate ( QObject* parent = 0 );
    
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData ( QWidget* editor, const QModelIndex& index ) const;
    void setModelData ( QWidget* editor, QAbstractItemModel* model, const QModelIndex & index ) const;
    
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void updateEditorGeometry ( QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
    
protected:
    void drawDisplay ( QPainter * painter, const QStyleOptionViewItem & option, const QRect & rect, const QString & text ) const;
    QTextDocument* TextDocumentForIndex( const QModelIndex & index );
    void updateLayoutWithText( const QString& text );
        
private slots:
    void slotEditorClosed( QWidget *editor, QAbstractItemDelegate::EndEditHint hint = NoHint );
    
private:
    bool isTextToWrap( const QStyleOptionViewItemV2& option ) const;
    void setTextOptions( QTextDocument* textDocument, const QStyleOptionViewItemV2& option ) const;
    QRect decorationRect( const QStyleOptionViewItemV2& option, const QModelIndex& index ) const;
    
    QPointer<QWidget> m_editorWidget;
    QModelIndex m_editedIndex;
    QTextDocument* m_pTextDocument;
};


#endif // MODEL_ELEMENT_DELEGATE_H_
