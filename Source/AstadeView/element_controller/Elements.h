/*
 * AstadeView
 * Copyright (C) 2008 Stefan Eilers
 *
 * Astade is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License V2
 * as published by the Free Software Foundation.
 *
 * Astade  is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St., Fifth Floor, Boston, MA 02110-1301, USA
 */
#ifndef ELEMENTS_H
#define ELEMENTS_H

// TODO: Rename this to ElementTypes

/**
 * Common known constants related to Elements
 */ 
struct Elements{
    enum RelationTypes{
        RT_MASK				= 0x000000F,
        RT_GENERALIZATION	= 0x0000000,
        RT_COMPOSITION		= 0x0000001,
        RT_AGGREGATION		= 0x0000002,
        RT_ASSOCIATION		= 0x0000003,
        RT_SPEC_DEPENDENCY	= 0x0000004,
        RT_IMPL_DEPENDENCY	= 0x0000005,
        RT_FRIEND			= 0x0000006
    };
        
    enum ElementTypes{
        ET_FOLDER			= 0x0000100,
        
        ET_DEST				= 0x0004000,
        ET_NORMALOP			= 0x0008000,
        
        ET_MASK				= 0xFF00000,  // Element type mask
        ET_ATTORDERMASK     = 0x00000FF,  // Attribute order mask
        ET_MODEL			= 0x0100000,
        ET_CLASS			= 0x0200000,
        ET_COMPONENTS		= 0x0300000,
        ET_COMPONENT		= 0x0400000,
        ET_CONFIGURATION	= 0x0500000,
        ET_DEPENDENCY		= 0x0600000,
        ET_ATTRIBUTE		= 0x0700000,
        ET_OPERATION		= 0x0800000,
        ET_PACKAGE			= 0x0900000,
        ET_WEBSITE			= 0x0A00000,
        ET_ATTRIBUTES		= 0x0B00000,
        ET_OPERATIONS		= 0x0C00000,
        ET_PARAMETERS		= 0x0D00000,
        ET_CLASSES			= 0x0E00000,
        ET_PARAMETER		= 0x0F00000,
        ET_RELATION		    = 0x1000000,
        ET_RELATIONS		= 0x1100000,
        ET_INRELATION		= 0x1200000,
        ET_FILES			= 0x1300000,
        ET_HFILE			= 0x1400000,
        ET_CPPFILE			= 0x1500000,
        ET_MAKE				= 0x1600000,
        ET_TYPES			= 0x1700000,
        ET_TYPE				= 0x1800000,
        ET_STATECHART		= 0x1900000,
        ET_STATE			= 0x1A00000,
        ET_TRANSITION		= 0x1B00000,
        ET_USECASEDIAGRAMS	= 0x1C00000,
        ET_ACTIVITYDIAGRAMS = 0x1D00000,
        ET_SEQUENCES		= 0x1E00000,
        ET_SEQUENCE			= 0x1F00000,
        ET_DOXFILE			= 0x2000000,
        ET_USECASE			= 0x2100000,
        
        ET_FILE				= 0x7E00000,
        ET_UNKNOWN			= 0x7F00000       
    };
    
}; 
#endif // ELEMENTS_H
