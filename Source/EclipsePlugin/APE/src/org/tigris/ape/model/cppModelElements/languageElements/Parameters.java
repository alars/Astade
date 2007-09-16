package org.tigris.ape.model.cppModelElements.languageElements;

import org.tigris.ape.model.cppModelElements.CppModelElementType;
import org.tigris.ape.model.genericModelElements.DirectoryElement;
import org.tigris.ape.model.genericModelElements.IModelElementType;

public class Parameters extends DirectoryElement {

	public Parameters(String pathName) {
		super(pathName);
	}

	@Override
	public IModelElementType getType() {
		return CppModelElementType.PARAMETERS;
	}

}
