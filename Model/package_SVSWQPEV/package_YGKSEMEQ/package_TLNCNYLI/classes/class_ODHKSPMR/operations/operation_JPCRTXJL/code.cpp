wxTreeItemId aID = myTree->GetSelection();   					   	//Get Tree item from mouse click
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();   		//get the parents name
parentPath.SetFullName("main.cpp");    								//make full path included file name

wxFile *mainFile = NULL;
mainFile = new wxFile(parentPath.GetFullPath(), wxFile::write);		//make file object and open for write

//Copy right statments
wxString heading =
        "/* \n";
heading += "* Astade is a UML tool for C++\n";
heading += "* Copyright (C) 2005,2006 Anders Larsen and Thomas Spitzer\n";
heading += "*\n";
heading += "* Astade is free software; you can redistribute it and/or\n ";
heading += "* modify it under the terms of the GNU General Public License\n";
heading += "* as published by the Free Software Foundation; either version 2\n";
heading += "* of the License, or (at your option) any later version.\n";
heading += "*\n";
heading += "* Astade  is distributed in the hope that it will be useful,\n";
heading += "* but WITHOUT ANY WARRANTY; without even the implied warranty of\n";
heading += "* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n";
heading += "* GNU General Public License for more details.\n";
heading += "*\n";
heading += "* You should have received a copy of the GNU General Public License\n";
heading += "* along with this program; if not, write to the Free Software\n";
heading += "* Foundation, Inc., 51 Franklin St., Fifth Floor, Boston, MA 02110-1301, USA\n";
heading += "*/\n\n\n";

wxString contents_1 = "using namespace std; \n\n";
wxString contents_2 =  "int main()\n";
	     contents_2 += "{ \n";
	     contents_2 += "	//Write the implementation for the main function here \n\n";
	     contents_2 += "}";

mainFile->Write(heading);    		//Start write statments into main.cpp
mainFile->Write(contents_1);
mainFile->Write(contents_2);	  	//complete writing the contents into file

mainFile->Close(); 					//close file all the time
delete mainFile; 					//relese memory to hip all the time

UpdateSubtree(aID);    				//refresh Astade tree to update new file.


