if (AstadeComponent::jumpList.find(event.GetId()) != AstadeComponent::jumpList.end())
		myTree->ShowNode(AstadeComponent::jumpList[event.GetId()].GetFullPath());
