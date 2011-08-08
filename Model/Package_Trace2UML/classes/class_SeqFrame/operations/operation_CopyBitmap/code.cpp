//~~ void CopyBitmap(wxCommandEvent& event) [SeqFrame] ~~

// Allocate a buffer large enough to store the image data. Use malloc()
// instead of new(). Each 
unsigned int image_buffer_len = dataBase->GetGraphWidth() * dataBase->GetGraphHeight() * 4;
unsigned char* image_buffer = (unsigned char*)malloc(image_buffer_len);

cairo_surface_t* cairo_surface = cairo_image_surface_create_for_data(
                            image_buffer,
                            CAIRO_FORMAT_RGB24,
                            dataBase->GetGraphWidth(),
                            dataBase->GetGraphHeight(),
                            dataBase->GetGraphWidth() * 4);

cairo_t* cr = cairo_create(cairo_surface);
cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
cairo_rectangle(cr, 0.0, 0.0, dataBase->GetGraphWidth(), dataBase->GetGraphHeight());
cairo_translate(cr, 0.5, 0.5);
cairo_fill(cr);

graphTab->DrawOnCr(cr, false);

// Now translate the raw image data from the format stored
// by cairo into a format understood by wxImage.
unsigned char* output = (unsigned char*)malloc(image_buffer_len);
int offset = 0;
for(size_t count = 0; count < image_buffer_len; count+=4)
{
    int r = *(image_buffer+count+2);
    *(output + offset) = r;
    offset++;
    int g = *(image_buffer+count+1);
    *(output + offset) = g;
    offset++;
    int b = *(image_buffer+count+0);
    *(output + offset) = b;
    offset++;
} 

// Create a wxImage from the buffer and then a wxBitmap from that
wxImage img(dataBase->GetGraphWidth(), dataBase->GetGraphHeight(), output, true);
wxBitmap bmp(img);

if (wxTheClipboard->Open())
{
	// These data objects are held by the clipboard,
	// so do not delete them in the app.
	wxTheClipboard->SetData(new wxBitmapDataObject(bmp));
	wxTheClipboard->Close();
}

cairo_destroy(cr);
cairo_surface_destroy(cairo_surface);
free(image_buffer);
free(output);