return (	(dynamic_cast<AstadeClasses*>(globalCopySource) != NULL)
		||	(dynamic_cast<AstadeSequences*>(globalCopySource) != NULL)
		||	(dynamic_cast<AstadePackage*>(globalCopySource) != NULL));