RefreshRect(wxRect(absGetDrawPosition().xCoord()-my_Radius-8, absGetDrawPosition().yCoord()-my_Radius-8, 2*my_Radius + 16, 2*my_Radius + 16));
const_cast<glSelfRelation*>(this)->myLabel.Refresh();
const_cast<glSelfRelation*>(this)->myStartMult.Refresh();
const_cast<glSelfRelation*>(this)->myEndMult.Refresh();
