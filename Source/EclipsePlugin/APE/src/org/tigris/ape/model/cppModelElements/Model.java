/**
 * 
 */
package org.tigris.ape.model.cppModelElements;

import org.tigris.ape.model.genericModelElements.DirectoryElement;

/**
 * @author Tobias Zipfel
 *
 */
public class Model extends DirectoryElement {

	public Model(String pathName) {
		super("model", pathName);
		loadModel();
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

	private void loadModel() {
		// TODO Auto-generated method stub
	}
}
