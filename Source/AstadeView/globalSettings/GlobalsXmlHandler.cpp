/*
 *  Created on: Nov 1, 2008
 *
 * XmlHandler.cpp
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
#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include "GlobalsXmlHandler.h"

GlobalsXmlHandler::GlobalsXmlHandler(){

}

GlobalsXmlHandler::~GlobalsXmlHandler() {
    //inputFile.close();
}

int GlobalsXmlHandler::parseGlobalXML(QString fileName)
{
    //Create QDevice object.
    inputFile.setFileName(fileName);
    QTextStream errorStream(stderr);

    if(!QFile::exists(fileName)){
        errorStream << "The file is not exist\n";
        return FileFailure;
    }
   else if(!inputFile.open(QIODevice::ReadOnly)){
        errorStream << "Fail to open the file";
        return ReadError;
    }

    makeXMLHashTable();
    return Success;
}


QString GlobalsXmlHandler::readDefaultKeyValue(QString key){
    return globalsHash.value(key);
}

void GlobalsXmlHandler::makeXMLHashTable(){
    setDevice(&inputFile);
    while(!atEnd()){
        readNext();
        if(isStartElement()){
            if(name() == "settingsproperty"){
                globalsHash.insert(attributes().value("key").toString(), attributes().value("default").toString());
            }
        }
    }
    clear();
    inputFile.close();
}
