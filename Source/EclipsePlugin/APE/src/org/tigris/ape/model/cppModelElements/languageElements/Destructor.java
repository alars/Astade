package org.tigris.ape.model.cppModelElements.languageElements;

import org.tigris.ape.model.cppModelElements.CppModelElementType;
import org.tigris.ape.model.genericModelElements.IModelElementType;
import org.tigris.ape.model.genericModelElements.OperationBase;

public class Destructor extends OperationBase {

	public Destructor(String pathName) {
		super(pathName);
	}

	@Override
	public IModelElementType getType() {
		return CppModelElementType.DESTRUCTOR;
	}
}
