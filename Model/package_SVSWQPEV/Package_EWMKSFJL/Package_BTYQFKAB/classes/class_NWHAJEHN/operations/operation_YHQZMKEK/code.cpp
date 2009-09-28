glNode* toNode = getMouseOverNode();

if ((toNode == NULL) || (toNode == this) || (dynamic_cast<glState*>(toNode) == NULL))
    return;

new glTransition(myParent, *this, *toNode);

