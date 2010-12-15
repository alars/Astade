/*******************************************************************************
(c) 2008 by dSys e.K.

$Id: $ $Name: $
*******************************************************************************/

/*!
********************************************************************************
@file pdt.h

@moduleinformation
  Portierbare Datentypen

@moduledescription
  Diese Modul enthaelt portierbare Datentypen fuer die ARM-Kontroller von
  Atmel. Die Datentypen sind an den \b GNU C-Compiler (GCC) angepasst.

	\arg \b PDT: portable data types

@preprocessor
	\arg \c __COMPILER_GCC_ARM: GNU C-Compiler fuer die ARM-Kontroller

@verbatim
$Id: $ $Name: $
@endverbatim
RCS-Logs: 
@ref rcslog_pdt_h
********************************************************************************
*/

#ifndef PDT_H
#define	PDT_H

/*
#if !defined (__COMPILER_GCC_ARM)
# error "pdt.h: wrong compiler !"
#endif
*/

#ifdef __cplusplus
extern "C" {
#endif

/* Include-Dateien ************************************************************/


/* Konstanten *****************************************************************/
#define	TRUE	(!0)			//!< wahrheitswert: wahr
#define	FALSE	0			//!< wahrheitswert: falsch

/* Makros *********************************************************************/

/* Typen **********************************************************************/
typedef	unsigned char	BOOL;		//!< Wahrheitswert

/* Prototypen *****************************************************************/

#ifdef __RCS		
extern	char		*pdt_getrcsid (void);
#endif

#ifdef __cplusplus
}
#endif

/* Aenderungsjournal **********************************************************/
#ifdef __DOCGEN
/*!
@page revisions Revisions

@subsection rcslog_pdt_h pdt.h
@verbatim
 * $Log: $
@endverbatim
*/
#endif
#endif
