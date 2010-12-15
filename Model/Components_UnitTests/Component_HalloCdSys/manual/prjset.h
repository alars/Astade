/*******************************************************************************
(c) 2008 by dSys e.K.

$Id: prjset.h,v 1.3 2008/04/02 12:55:56 a.becker Exp $ $Name:  $
*******************************************************************************/

/*!
********************************************************************************
@file prjset.h

@moduleinformation
  Projektweite Einstellungen

@moduledescription
  #

@moduleglossary
  .

@preprocessor
  .

@verbatim
$Id: prjset.h,v 1.3 2008/04/02 12:55:56 a.becker Exp $ $Name:  $
@endverbatim
RCS-Logs:
@ref rcslog_prjset_h
********************************************************************************
*/

#ifndef PRJSET_H
#define	PRJSET_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include-Dateien ************************************************************/
// #include "pdt.h"

/* Konstanten *****************************************************************/
#define	PRJSET_DBG_MODE	0

#define	PRJSET_DBG_TIMEOUT	DBG_LEVEL_WARN

/* Makros *********************************************************************/

/* Typen **********************************************************************/

/* Prototypen *****************************************************************/

#ifdef __RCS
extern	char		*prjset_getrcsid (void);
#endif

#ifdef __cplusplus
}
#endif

/* Aenderungsjournal **********************************************************/
#ifdef __DOCGEN
/*!
@page revisions Revisions

@subsection rcslog_prjset_h prjset.h
@verbatim
 * $Log: prjset.h,v $

@endverbatim
*/
#endif
#endif

