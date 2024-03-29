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

DrawOnCr(myfile);

myfile << "      </root>\n";
myfile << "    </mxGraphModel>\n";
myfile << "  </diagram>\n";
myfile << "</mxfile>\n";

myfile.close();