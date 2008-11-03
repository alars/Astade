/*
 *  Created on: Nov 1, 2008
 *    
 * GlobalsXmlHandler.h
 * Copyright (C) 2008 Kyung Un Choi
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

#ifndef GLOBALSXMLHANDLER_H_
#define GLOBALSXMLHANDLER_H_
#include <QString>
#include <QFile>
#include <QHash>
#include <QXmlStreamReader>

class GlobalsXmlHandler: public QXmlStreamReader {
public:
	GlobalsXmlHandler();
	virtual ~GlobalsXmlHandler();

	enum ExitCode {
		Success, ParseFailure, ArgumentError, ReadError, FileFailure
	};

	int parseGlobalXML(QString);
	QString readDefaultKeyValue(QString key);

private:
	QHash<QString, QString> globalsHash;
	QString fileName;
	QFile inputFile;
	void makeXMLHashTable();
};

#endif /* GLOBALSXMLHANDLER_H_ */

