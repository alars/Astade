//~~ void SaveDrawIo(const wxString& saveFileName) [glGraphicPanel] ~~

std::ofstream myfile;
myfile.open (saveFileName.utf8_str());

myfile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
myfile << "<mxfile host=\"Trace2UML\">\n";
myfile << "  <diagram>\n";
myfile << "    <mxGraphModel>\n";
myfile << "      <root>\n";
myfile << "        <mxCell id=\"0\" />\n";
myfile << "        <mxCell id=\"1\" parent=\"0\" />\n";

glNode::UnifyNodeIds();

int count = 1;
glNode* aNode = glNode::getNodeById(count);

while (aNode)
{
	aNode->SaveDrawIo(myfile);

	count++;
    aNode = glNode::getNodeById(count);
}

myfile << "      </root>\n";
myfile << "    </mxGraphModel>\n";
myfile << "  </diagram>\n";
myfile << "</mxfile>\n";

myfile.close();

