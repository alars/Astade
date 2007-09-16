package org.tigris.ape.model.cppModelElements.languageElements;

import org.tigris.ape.model.cppModelElements.CppModelElementType;
import org.tigris.ape.model.genericModelElements.IModelElementType;
import org.tigris.ape.model.genericModelElements.RelationBase;

public class Relation extends RelationBase {

	public Relation(String pathName, String fileName) {
		super(pathName, fileName);
	}

	@Override
	public IModelElementType getType() {
		return CppModelElementType.RELATION;
	}

}
