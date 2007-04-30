/**
 * 
 */
package org.tigris.ape.model.genericModelElements;

/**
 * @author Tobias Zipfel
 * 
 */
public abstract class ModelRoot extends ModelContainer {

	public ModelRoot(String pathName) {
		super(pathName);
		loadModel();
	}

	abstract public void loadModel();
}
