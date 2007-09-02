package org.tigris.ape.model.cppModelElements;

import org.tigris.ape.model.genericModelElements.DirectoryElement;
import org.tigris.ape.model.genericModelElements.IModelElementType;

public class UsecaseDiagrams extends DirectoryElement {

	public UsecaseDiagrams(String pathName) {
		super(pathName);
	}

	@Override
	public IModelElementType getType() {
		return CppModelElementType.USECASEDIAGRAMS;
	}

}
