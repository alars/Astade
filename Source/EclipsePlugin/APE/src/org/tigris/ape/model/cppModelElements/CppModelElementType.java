package org.tigris.ape.model.cppModelElements;

import org.tigris.ape.model.genericModelElements.IModelElementType;
import org.tigris.ape.model.genericModelElements.ModelElementType;

public abstract class CppModelElementType extends ModelElementType {

	public static final CppModelElementType ATTRIBUTE = new CppModelElementType(
			"Attribute", "Attribute", 1) {
	};

	public static final CppModelElementType ATTRIBUTES = new CppModelElementType(
			"Attributes", "Attributes", 1) {
	};

	public static final CppModelElementType AUTOFOLDER = new CppModelElementType(
			"Autofolder", "Automatic generated source code", 2) {
	};

	public static final CppModelElementType CLASS = new CppModelElementType(
			"Class", "Class", 1) {
	};

	public static final CppModelElementType CLASSES = new CppModelElementType(
			"Classes", "Classes", 3) {
	};

	public static final CppModelElementType COMPONENT = new CppModelElementType(
			"Component", "Component", 1) {
	};

	public static final CppModelElementType COMPONENTS = new CppModelElementType(
			"Components", "Components", 1) {
	};

	public static final CppModelElementType CONFIGURATION = new CppModelElementType(
			"Configuration", "Configruation", 1) {
	};

	public static final CppModelElementType CONSTRUCTOR = new CppModelElementType(
			"Constructor", "Constructor", 1) {
	};

	public static final CppModelElementType DESTRUCTOR = new CppModelElementType(
			"Destructor", "Destructor", 3) {
	};

	public static final CppModelElementType MAKEFILE = new CppModelElementType(
			"Makefile", "Make file", 1) {
	};

	public static final CppModelElementType MANUALFOLDER = new CppModelElementType(
			"Manualfolder", "manual programmed source code", 3) {
	};

	public static final CppModelElementType MODEL = new CppModelElementType(
			"Model", "Model", 1) {
	};

	public static final CppModelElementType OPERATION = new CppModelElementType(
			"Operation", "Operation", 3) {
	};

	public static final CppModelElementType OPERATIONS = new CppModelElementType(
			"Operations", "Operations", 2) {
	};

	public static final CppModelElementType PACKAGE = new CppModelElementType(
			"Package", "Package", 2) {
	};

	public static final CppModelElementType PARAMETER = new CppModelElementType(
			"Parameter", "Parameter", 1) {
	};

	public static final CppModelElementType PARAMETERS = new CppModelElementType(
			"Parameters", "Parameters", 1) {
	};

	public static final CppModelElementType RELATION = new CppModelElementType(
			"Relation", "Relation", 1) {
	};

	public static final CppModelElementType RELATIONS = new CppModelElementType(
			"Relations", "Relations", 3) {
	};

	public static final CppModelElementType SEQUENCE = new CppModelElementType(
			"Sequence", "Sequence diagram", 1) {
	};

	public static final CppModelElementType SEQUENCES = new CppModelElementType(
			"Sequences", "Sequence diagrams", 5) {
	};

	public static final CppModelElementType SOURCEFILE_CPP = new CppModelElementType(
			"Sourcefile_cpp", "Source file", 4) {
	};

	public static final CppModelElementType SOURCEFILE_H = new CppModelElementType(
			"Sourcefile_h", "Header file", 4) {
	};

	public static final CppModelElementType STATE = new CppModelElementType(
			"State", "State", 1) {
	};

	public static final CppModelElementType TYPES = new CppModelElementType(
			"Types", "Types", 5) {
	};

	public static final CppModelElementType USECASEDIAGRAM = new CppModelElementType(
			"UsecaseDiagram", "Usecase Diagram", 1) {
	};

	public static final CppModelElementType USECASEDIAGRAMS = new CppModelElementType(
			"UsecaseDiagrams", "Usecase Diagrams", 4) {
	};

	private static final CppModelElementType[] MODELTYPES = { ATTRIBUTE,
			ATTRIBUTES, AUTOFOLDER, CLASS, CLASSES, COMPONENT, COMPONENTS,
			CONFIGURATION, CONSTRUCTOR, DESTRUCTOR, MAKEFILE, MANUALFOLDER,
			MODEL, OPERATION, OPERATIONS, PACKAGE, PARAMETER, PARAMETERS,
			RELATION, RELATIONS, SEQUENCE, SEQUENCES, STATE, TYPES,
			USECASEDIAGRAM, USECASEDIAGRAMS };

	public static CppModelElementType[] getTypes() {
		return MODELTYPES;
	}

	private CppModelElementType(String id, String printName, int ordinal) {
		super(id, printName, ordinal);
	}

	@Override
	public int compareTo(IModelElementType arg0) {
		return this.ordinal - arg0.getOrdinal();
	}
}
