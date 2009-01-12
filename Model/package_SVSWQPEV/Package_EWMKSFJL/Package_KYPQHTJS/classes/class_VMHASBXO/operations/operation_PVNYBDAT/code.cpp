int w,h;
myParent->GetVirtualSize(&w,&h);

AddSpeed(myGravityArea.GetBorderForce(w,h));

glFloatingItem::Move();