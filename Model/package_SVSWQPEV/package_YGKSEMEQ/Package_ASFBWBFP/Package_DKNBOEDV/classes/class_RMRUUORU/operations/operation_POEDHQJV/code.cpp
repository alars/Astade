GrafUseCase* aUseCase = dynamic_cast<GrafUseCase*>(&destination);

if (aUseCase && relationType == generalisationID)
	{
		GrafArrow* anArrow = new GrafArrow(*this,*aUseCase,ARROWHEADSOLID,"",wxSOLID,"blue");
		mySuperclass.insert(mySuperclass.begin(),anArrow);
		m_Parent->DeclareEdge(anArrow);
		m_Parent->NotifyModification();
	}

if (aUseCase &&	relationType == extendID)
	{
		GrafArrow* anArrow = new GrafArrow(*this,*aUseCase,ARROWHEADVEE,"\xab" "extend" "\xbb",wxSHORT_DASH,"blue");
		myExtend.insert(myExtend.begin(),anArrow);
		m_Parent->DeclareEdge(anArrow);
		m_Parent->NotifyModification();
	}

if (aUseCase &&	relationType == includeID)
	{
		GrafArrow* anArrow = new GrafArrow(*this,*aUseCase,ARROWHEADVEE,"\xab" "include" "\xbb",wxSHORT_DASH,"blue");
		myInclude.insert(myInclude.begin(),anArrow);
		m_Parent->DeclareEdge(anArrow);
		m_Parent->NotifyModification();
	}

