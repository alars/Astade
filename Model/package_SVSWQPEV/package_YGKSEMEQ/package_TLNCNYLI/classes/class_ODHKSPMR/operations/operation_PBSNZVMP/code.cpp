if (jumpList.find(event.GetId()) != jumpList.end())
		myTree->ShowNode(jumpList[event.GetId()].GetFullPath());