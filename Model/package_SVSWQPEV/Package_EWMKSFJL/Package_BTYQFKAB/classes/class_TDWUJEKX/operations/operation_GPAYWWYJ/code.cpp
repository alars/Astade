int refreshwidth = 2*my_Radius;
if (labelwidth > refreshwidth)
    refreshwidth = labelwidth;
myParent->RefreshRect(wxRect(absGetDrawPosition().xCoord()-(refreshwidth/2)-1, absGetDrawPosition().yCoord()-my_Radius-1, refreshwidth + 2, 2*my_Radius + 2));
