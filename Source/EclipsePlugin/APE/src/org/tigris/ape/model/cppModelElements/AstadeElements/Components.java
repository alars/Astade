/**
 * 
 */
package org.tigris.ape.model.cppModelElements.astadeElements;

import org.tigris.ape.model.cppModelElements.CppModelElementType;
import org.tigris.ape.model.genericModelElements.DirectoryElement;
import org.tigris.ape.model.genericModelElements.IModelElementType;

public class Components extends DirectoryElement {

	public Components(String pathName) {
		super(pathName);
	}

	@Override
	public IModelElementType getType() {
		return CppModelElementType.COMPONENTS;
	}

	
}
