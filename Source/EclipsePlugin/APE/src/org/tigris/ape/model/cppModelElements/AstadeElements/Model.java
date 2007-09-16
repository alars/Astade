/**
 * 
 */
package org.tigris.ape.model.cppModelElements.astadeElements;

import org.apache.log4j.Logger;
import org.tigris.ape.model.cppModelElements.CppModelElementType;
import org.tigris.ape.model.genericModelElements.DirectoryElement;
import org.tigris.ape.model.genericModelElements.IModelElementType;

/**
 * Represents the root model node.
 * @author Tobias Zipfel
 *
 */
public class Model extends DirectoryElement {
	
	static Logger logger = Logger.getLogger(Model.class.getName());

	public Model(String pathName) {
		super(pathName);
	}

	@Override
	public IModelElementType getType() {
		return CppModelElementType.MODEL;
	}
}

