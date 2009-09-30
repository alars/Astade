glNode* toNode = getMouseOverNode();

if ((toNode == NULL) || (toNode == this) || 
		((dynamic_cast<glState*>(toNode) == NULL) && (dynamic_cast<glEndNode*>(toNode) == NULL))
	 )
    return;

new glTransition(myParent, *this, *toNode);

