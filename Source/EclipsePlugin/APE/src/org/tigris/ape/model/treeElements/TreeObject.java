/**
 * 
 */
package org.tigris.ape.model.treeElements;

import org.eclipse.core.runtime.IAdaptable;

/**
 * @author Tobias Zipfel
 *
 */
public interface TreeObject extends IAdaptable {

	/**
	 * @param newName
	 */
	public void setName(String newName);
	
	/**
	 * @return
	 */
	public String getName();
	
	/**
	 * @return
	 */
	public String toString();

}
