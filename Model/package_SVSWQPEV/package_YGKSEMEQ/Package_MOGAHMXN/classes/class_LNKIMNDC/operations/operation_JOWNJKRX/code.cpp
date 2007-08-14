return 	(	(dynamic_cast<AstadeOperation*>(globalCopySource) != NULL)
		||	(dynamic_cast<AstadeConstructor*>(globalCopySource) != NULL)
		||	(	(dynamic_cast<AstadeDestructor*>(globalCopySource) != NULL)
			&&	(!dynamic_cast<AdeDirectoryElement*>(myModelElement)->GetHasDestructor())
			)
	  	);