package org.tigris.ape.model.cppModelElements.languageElements;

import org.tigris.ape.model.cppModelElements.CppModelElementType;
import org.tigris.ape.model.genericModelElements.IModelElementType;
import org.tigris.ape.model.genericModelElements.OperationBase;

public class Operation extends OperationBase {

	public Operation(String pathName) {
		super(pathName);
	}

	@Override
	public IModelElementType getType() {
		return CppModelElementType.OPERATION;
	}

}
