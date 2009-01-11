int w,h;
myParent->GetSize(&w,&h);

AddSpeed(myGravityArea.GetBorderForce(w,h));

glFloatingItem::Move();