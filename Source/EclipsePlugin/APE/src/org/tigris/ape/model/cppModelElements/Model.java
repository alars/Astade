/**
 * 
 */
package org.tigris.ape.model.cppModelElements;

import org.apache.log4j.Logger;
import org.tigris.ape.model.genericModelElements.DirectoryElement;

/**
 * @author Tobias Zipfel
 *
 */
public class Model extends DirectoryElement {
	
	static Logger logger = Logger.getLogger(Model.class.getName());

	public Model(String pathName) {
		super(pathName);
	}

	/* (non-Javadoc)
	 * @see org.tigris.ape.model.genericModelElements.ModelElement#getParent()
	 */
	@Override
	public DirectoryElement getParent() {
		return null;
	}

	/* (non-Javadoc)
	 * @see org.tigris.ape.model.genericModelElements.ModelElement#setParent(org.tigris.ape.model.genericModelElements.ModelContainer)
	 */
	@Override
	public void setParent(DirectoryElement parent) {
		return;
	}

}

