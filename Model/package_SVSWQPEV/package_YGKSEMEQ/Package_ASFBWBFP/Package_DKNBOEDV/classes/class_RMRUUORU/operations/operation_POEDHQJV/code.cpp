GrafUseCase* aUseCase = dynamic_cast<GrafUseCase*>(&destination);

if (aUseCase && (relationType==generalisationID))
	{
		mySuperclass.insert(mySuperclass.begin(),new GrafArrow(*this,*aUseCase,ARROWHEADSOLID,"",wxSOLID,"blue"));
		m_Parent->NotifyModification();
	}

if (aUseCase &&	(relationType==extendID))
	{
		myExtend.insert(myExtend.begin(),new GrafArrow(*this,*aUseCase,ARROWHEADVEE,"<<extend>>",wxSHORT_DASH,"blue"));
		m_Parent->NotifyModification();
	}

if (aUseCase &&	(relationType==includeID))
	{
		myInclude.insert(myInclude.begin(),new GrafArrow(*this,*aUseCase,ARROWHEADVEE,"<include>>",wxSHORT_DASH,"blue"));
		m_Parent->NotifyModification();
	}

