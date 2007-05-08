package org.tigris.ape.model.cppModelElements;

import java.io.IOException;
import java.util.Iterator;
import java.util.List;

import org.apache.log4j.Level;
import org.apache.log4j.Logger;
import org.tigris.ape.defines.CppDefines;
import org.tigris.ape.defines.IniDefines;
import org.tigris.ape.model.genericModelElements.ModelElement;

import ch.ubique.inieditor.IniEditor;

public class ElementFactory {
	
	static Logger logger = Logger.getLogger(ElementFactory.class.getName());
	
	static private ElementFactory me = null;
	
	static private IniEditor editor = null; 
	
	private ElementFactory(){
		editor = new IniEditor(true);
	}
	
	public static ElementFactory getInstance(){
		
		if (me == null) {
			me = new ElementFactory();
		}
		
		return me;
	}
	
	public ModelElement getModelElement(String path){
		
		if (path.length() < 1) {
			logger.info("No path to model is set!");
			return null;
		}

		try {
			editor.load(path + IniDefines.INIFILE);

		} catch (IOException e) {
			logger.error("Model could not be loaded. Model.ini was not found in "	+ path);
			e.printStackTrace();
			return null;
		}

		ModelElement newElement = null;
		
		String type = editor.get(IniDefines.S_ASTADE, IniDefines.O_TYPE);
		
		int cleanType = Integer.parseInt(type) & CppDefines.ITEM_TYPE_MASK;
		
		logger.debug("CleanType is " + cleanType);
		
		switch(cleanType){
			case CppDefines.ITEM_IS_MODEL:
				logger.info("new 'model' created!");
				newElement = new Model(path);
				break;
				
			case CppDefines.ITEM_IS_COMPONENTS:
				logger.info("new 'components' created!");
				newElement = new Components(path);
				break;
				
			case CppDefines.ITEM_IS_PACKAGE:
				logger.info("new 'package' created!");
				newElement = new Package(path);
				break;
				
			case CppDefines.ITEM_IS_CLASSES:
				logger.info("new 'classes' created!");
				newElement = new Classes(path);
				break;
			
			case CppDefines.ITEM_IS_COMPONENT:
				logger.info("new 'classes' created!");
				newElement = new Component(path);
				break;
				
			default:
				return null;
		}

		newElement.setName(editor.get(IniDefines.S_ASTADE, IniDefines.O_NAME));

		if (logger.isEnabledFor(Level.DEBUG)) {
			List options = editor.optionNames(IniDefines.S_ASTADE);
			for (Iterator iter = options.iterator(); iter.hasNext();) {
				String option = (String) iter.next();
				logger.debug(option + " = "
						+ editor.get(IniDefines.S_ASTADE, option));
			}
		}
		
		return newElement; 
	}

}
