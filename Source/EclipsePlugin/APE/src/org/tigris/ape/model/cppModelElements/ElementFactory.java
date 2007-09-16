package org.tigris.ape.model.cppModelElements;

import java.io.File;
import java.io.IOException;
import java.util.Iterator;
import java.util.List;

import org.apache.log4j.Level;
import org.apache.log4j.Logger;
import org.tigris.ape.defines.CppDefines;
import org.tigris.ape.defines.IniDefines;
import org.tigris.ape.model.cppModelElements.astadeElements.Autofolder;
import org.tigris.ape.model.cppModelElements.astadeElements.Component;
import org.tigris.ape.model.cppModelElements.astadeElements.Components;
import org.tigris.ape.model.cppModelElements.astadeElements.Configuration;
import org.tigris.ape.model.cppModelElements.astadeElements.Manualfolder;
import org.tigris.ape.model.cppModelElements.astadeElements.Model;
import org.tigris.ape.model.cppModelElements.astadeElements.Sequences;
import org.tigris.ape.model.cppModelElements.astadeElements.State;
import org.tigris.ape.model.cppModelElements.astadeElements.UsecaseDiagrams;
import org.tigris.ape.model.cppModelElements.fileElements.Headerfile;
import org.tigris.ape.model.cppModelElements.fileElements.Makefile;
import org.tigris.ape.model.cppModelElements.fileElements.Sourcefile;
import org.tigris.ape.model.cppModelElements.fileElements.Textfile;
import org.tigris.ape.model.cppModelElements.fileElements.Unknown;
import org.tigris.ape.model.cppModelElements.languageElements.Attribute;
import org.tigris.ape.model.cppModelElements.languageElements.Attributes;
import org.tigris.ape.model.cppModelElements.languageElements.Class;
import org.tigris.ape.model.cppModelElements.languageElements.Classes;
import org.tigris.ape.model.cppModelElements.languageElements.Consructor;
import org.tigris.ape.model.cppModelElements.languageElements.Destructor;
import org.tigris.ape.model.cppModelElements.languageElements.Operation;
import org.tigris.ape.model.cppModelElements.languageElements.Operations;
import org.tigris.ape.model.cppModelElements.languageElements.Package;
import org.tigris.ape.model.cppModelElements.languageElements.Parameter;
import org.tigris.ape.model.cppModelElements.languageElements.Parameters;
import org.tigris.ape.model.cppModelElements.languageElements.Relations;
import org.tigris.ape.model.cppModelElements.languageElements.Types;
import org.tigris.ape.model.genericModelElements.ModelElement;

import ch.ubique.inieditor.IniEditor;

public class ElementFactory {

	static Logger logger = Logger.getLogger(ElementFactory.class.getName());

	static private ElementFactory me = null;

	static private IniEditor editor = null;

	private ElementFactory() {
		editor = new IniEditor(true);
	}

	public static ElementFactory getInstance() {

		if (me == null) {
			me = new ElementFactory();
		}

		return me;
	}

	public ModelElement getModelElement(File file) {

		if (file == null || !file.exists()) {
			logger.info("File does not exists!");
			return null;
		}

		// skip ModelNode.ini, these are loaded if the parent directory is
		// visible
		if (("\\" + file.getName()).compareTo(IniDefines.INIFILE) == 0) {
			return null;
		}

		if (file.isDirectory()) {
			// it's a normal Directory which ModelElement representation is
			// described in ModelNode.ini
			return getModelElementOfIni(file.getAbsolutePath(),
					IniDefines.INIFILE);
		} else if (file.getName().matches(".+\\.ini")) {
			// it's a parameter, attribute, type, relation...
			return getModelElementOfIni(file.getParent(), "\\" + file.getName());
		}

		// file can be cpp, txt or h
		return getModelElementOfFile(file);
	}

	private ModelElement getModelElementOfFile(File file) {

		ModelElement newElement = null;
		
		if (file.getName().matches(".+\\.cpp")) {
			newElement = new Sourcefile(file.getParent(), "\\" + file.getName());
		} else if (file.getName().matches(".+\\.h")) {
			newElement = new Headerfile(file.getParent(), "\\" + file.getName());
		} else if (file.getName().matches(".+\\.txt")) {
			newElement = new Textfile(file.getParent(), "\\" + file.getName());
		} else if (file.getName().matches("Makefile")) {
			newElement = new Makefile(file.getParent(), "\\" + file.getName());
		} else {
			newElement = new Unknown(file.getParent(), "\\" + file.getName());
		}
		
		newElement.setName(file.getName());
		return newElement;
	}

	private ModelElement getModelElementOfIni(String path, String fileName) {

		try {
			editor.load(path + fileName);
		} catch (IOException e) {
			logger.error("Model could not be loaded. " + fileName
					+ " was not found at " + path);
			// e.printStackTrace();
			return null;
		}

		ModelElement newElement = null;

		// the string with the type info
		String rawTypeInfo = editor.get(IniDefines.S_ASTADE, IniDefines.O_TYPE);
		if (rawTypeInfo == null) {
			logger.error(IniDefines.INIFILE + " in path " + path
					+ " contains no option " + IniDefines.O_TYPE + " !");
			return null;
		}

		// the int with the type info, extracted from the string rawTypeInfo
		int type;

		try {
			type = Integer.parseInt(rawTypeInfo);
		} catch (NumberFormatException e) {
			logger.error("Type " + rawTypeInfo + " is not convertable to int!");
			return null;
		}

		int itemType = type & CppDefines.MASK_ITEM_TYPE;

		logger.debug("CleanType is " + itemType);

		String name = editor.get(IniDefines.S_ASTADE, IniDefines.O_NAME);

		switch (itemType) {
		case CppDefines.ITEM_IS_MODEL:
			newElement = new Model(path);
			name = "Model at " + path;
			break;

		case CppDefines.ITEM_IS_COMPONENTS:
			newElement = new Components(path);
			break;

		case CppDefines.ITEM_IS_COMPONENT:
			newElement = new Component(path);
			break;

		case CppDefines.ITEM_IS_CONFIGURATION:
			newElement = new Configuration(path);
			break;

		case CppDefines.ITEM_IS_FILES:
			
			if((type & CppDefines.MASK_ITEM_ACCESS) == CppDefines.ITEM_IS_FOLDER){
				if(name.matches("manual")){
					newElement = new Manualfolder(path);
				} else if(name.matches("auto")){
					newElement = new Autofolder(path);
				}
			}
			break;
			
		case CppDefines.ITEM_IS_PACKAGE:
			newElement = new Package(path);
			break;

		case CppDefines.ITEM_IS_CLASSES:
			newElement = new Classes(path);
			break;

		case CppDefines.ITEM_IS_CLASS:
			newElement = new Class(path);
			break;

		case CppDefines.ITEM_IS_OPERATIONS:
			newElement = new Operations(path);
			break;

		case CppDefines.ITEM_IS_OPERATION:

			int operationType = type & CppDefines.MASK_OPERATION_TYPE;

			if (operationType == CppDefines.ITEM_IS_NORMALOP) {

				newElement = new Operation(path);

			} else if (operationType == 0) {

				newElement = new Consructor(path);

			} else if (operationType == CppDefines.ITEM_IS_DEST) {

				newElement = new Destructor(path);
			}
			break;

		case CppDefines.ITEM_IS_TYPES:
			newElement = new Types(path);
			break;

		case CppDefines.ITEM_IS_ATTRIBUTES:
			newElement = new Attributes(path);
			break;

		case CppDefines.ITEM_IS_ATTRIBUTE:
			newElement = new Attribute(path, fileName);
			break;

		case CppDefines.ITEM_IS_PARAMETERS:
			newElement = new Parameters(path);
			break;

		case CppDefines.ITEM_IS_PARAMETER:
			newElement = new Parameter(path, fileName);
			break;

		case CppDefines.ITEM_IS_RELATIONS:
			newElement = new Relations(path);
			break;

		case CppDefines.ITEM_IS_SEQUENCES:
			newElement = new Sequences(path);
			break;

		case CppDefines.ITEM_IS_STATE:
			newElement = new State(path);
			break;

		case CppDefines.ITEM_IS_USECASEDIAGRAMS:
			newElement = new UsecaseDiagrams(path);
			break;

		default:
			newElement = new Unknown(path, fileName);
			if (name == null) {
				name = "Unknown";
			}
			name += " / not implemented";
			break;
		}

		logger.info("new " + newElement.getType().getPrintName()
				+ " with name " + name + " created!");

		if (name == null) {
			name = "No name";
		}

		newElement.setName(name);

		if (logger.isEnabledFor(Level.DEBUG)) {
			List<String> options = editor.optionNames(IniDefines.S_ASTADE);
			String elementInfo = newElement.getType().getPrintName() + " "
					+ name + " has the following options:";
			for (Iterator<String> iter = options.iterator(); iter.hasNext();) {
				String option = iter.next();
				elementInfo += "\n\t" + option + " = "
						+ editor.get(IniDefines.S_ASTADE, option) + ".";
			}
			logger.debug(elementInfo);
		}

		return newElement;

	}

}
