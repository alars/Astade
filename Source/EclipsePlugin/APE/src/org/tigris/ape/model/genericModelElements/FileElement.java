package org.tigris.ape.model.genericModelElements;

public abstract class FileElement extends ModelElement {

	private String fileName;
	
	public FileElement(String pathName, String fileName) {
		super(pathName);
		if(fileName.matches("\\.+")){
			this.fileName = fileName;
		} else {
			this.fileName = "\\" + fileName;
		}
	}

	public String getFileName() {
		return fileName;
	}
	
	
}
