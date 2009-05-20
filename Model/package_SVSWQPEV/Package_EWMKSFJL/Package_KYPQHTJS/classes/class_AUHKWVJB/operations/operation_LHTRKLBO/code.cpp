wxCoord x,y;
dc.GetTextExtent(string,&x,&y);
if (x >= pixelCount)
{
    do
    {
        string.RemoveLast();
        dc.GetTextExtent(string+"...",&x,&y);
    } while(x >= pixelCount);
    string += "...";
}
