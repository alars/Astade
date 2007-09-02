package org.tigris.ape.model.cppModelElements;

import org.tigris.ape.model.genericModelElements.DirectoryElement;
import org.tigris.ape.model.genericModelElements.IModelElementType;
import org.tigris.ape.model.genericModelElements.RelationBase;

public class Relation extends RelationBase {

	public Relation(String pathName, DirectoryElement parent) {
		super(pathName, parent);
		// TODO Auto-generated constructor stub
	}

	@Override
	public IModelElementType getType() {
		return CppModelElementType.RELATION;
	}

}
