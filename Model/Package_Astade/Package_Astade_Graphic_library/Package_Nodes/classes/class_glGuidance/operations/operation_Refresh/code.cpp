//~~ void Refresh() [glTool] ~~
int refreshwidth = 2*my_Radius;
if (labelwidth > refreshwidth)
    refreshwidth = labelwidth;
RefreshRect(wxRect(absGetDrawPosition().xCoord()-(refreshwidth/2)-5, absGetDrawPosition().yCoord()-my_Radius-1, refreshwidth + 2, 2*my_Radius + 10));
