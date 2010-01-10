glNode* toNode = getMouseOverNode();

if ((toNode == NULL) || (toNode == this) || (dynamic_cast<glClass*>(toNode) == NULL))
    return;

new glRelation(myParent, *this, *getMouseOverNode());
