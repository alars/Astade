package org.tigris.ape.model.cppModelElements;

import org.tigris.ape.model.genericModelElements.DirectoryElement;
import org.tigris.ape.model.genericModelElements.IModelElementType;

public class Relations extends DirectoryElement {

	public Relations(String pathName) {
		super(pathName);
		// TODO Auto-generated constructor stub
	}

	@Override
	public IModelElementType getType() {
		return CppModelElementType.RELATIONS;
	}

}
