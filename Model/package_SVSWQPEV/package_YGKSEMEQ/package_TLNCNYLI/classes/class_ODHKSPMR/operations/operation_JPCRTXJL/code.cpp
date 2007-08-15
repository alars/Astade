wxTreeItemId aID = myTree->GetSelection();   					   	//Get Tree item from mouse click
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();   		//get the parents name
parentPath.SetFullName("main.cpp");  						//make full path included file name

wxFile *mainFile = NULL;
mainFile = new wxFile(parentPath.GetFullPath(), wxFile::write);		//make file object and open for write


wxString contents_1 = "using namespace std; \n\n";
wxString contents_2 =  "int main(int argc, char** argv)\n";
	     contents_2 += "{ \n\n";
	     contents_2 += "	//Write an implementation for the main function here \n\n";
	     contents_2 += "return 0;\n"; 
	     contents_2 += "}";

mainFile->Write(contents_1);
mainFile->Write(contents_2);	  	//complete writing the contents into file

mainFile->Close(); 					//close file all the time
delete mainFile; 					//relese memory to hip all the time

UpdateSubtree(aID);    				//refresh Astade tree to update new file.


