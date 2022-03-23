//~~ void writeFile(const wxString& filename) [SeqDrawIO] ~~
std::ofstream myfile;
myfile.open (filename.utf8_str());

myfile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
myfile << "<mxfile host=\"Trace2UML\">\n";
myfile << "  <diagram>\n";
myfile << "    <mxGraphModel>\n";
myfile << "      <root>\n";
myfile << "        <mxCell id=\"0\" />\n";
myfile << "        <mxCell id=\"1\" parent=\"0\" />\n";

/*

for (int i = 0; i < dataBase->GetClassCount(); i++)
{
myfile << "        <mxCell id=\"" 
       << "class:" 
       << i 
       << "\" value=\""
       << dataBase->GetClassName(i)
       << "\" style=\"shape=umlLifeline;perimeter=lifelinePerimeter;container=1;collapsible=0;recursiveResize=0;rounded=0;shadow=0;strokeWidth=1;strokeColor=#008000;\" parent=\"1\" vertex=\"1\">\n";
myfile << "          <mxGeometry x=\""
       << dataBase->GetClassMiddle(i) - (dataBase->GetClassBoxWidth(i) / 2)
       << "\" y=\"80\" width=\""
       << dataBase->GetClassBoxWidth(i) 
       << "\" height=\"300\" as=\"geometry\" />\n";
myfile << "        </mxCell>\n";

}

*/

DrawOnCr(myfile);

myfile << "      </root>\n";
myfile << "    </mxGraphModel>\n";
myfile << "  </diagram>\n";
myfile << "</mxfile>\n";

myfile.close();