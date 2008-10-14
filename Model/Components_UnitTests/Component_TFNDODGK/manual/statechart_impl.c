/*******************************************************************************
(c) 2008 by dSys e.K.

$Id: $ $Name: $
*******************************************************************************/

/*!
********************************************************************************
@file statechart_impl.c

@moduleinformation
  MODULNAME EINTRAGEN !

@preprocessor
  .

@verbatim
$Id: $ $Name: $
@endverbatim
RCS-Logs: 
@ref rcslog_statechart_impl_c
********************************************************************************
*/

#ifdef __RCS
/* Name der Funktion, die die RCS-Information ermittelt */
#define	GETLOCALRCSID	statechart_impl_getrcsid
#endif

#define	STATECHART_IMPL_C

/* Include-Dateien ************************************************************/
#include <stdlib.h>

#include "../auto/statechart_impl.h"
// #include "dbg.h"
#include "prjset.h"

/* Konstanten *****************************************************************/
/*! @brief Debugstufen fuer die jeweiligen Modulbereiche */
#define	_DBG_LEVEL_VOID		DBG_LEVEL_INFO		//!< Standardbereich

/*! @brief interne Modulzustaende */
#define	_MSTATE_INIT		0x01			//!< Modul initialisiert

/* Makros *********************************************************************/
// Debugausgaben
#if 0
#define	_DBGF(part,level,...) printf("%s, %d: ", __FILE__, __LINE__); printf(__VA_ARGS__); printf("\r\n");
#define	_DBG(part,level,msg) printf("%s, %d: ", __FILE__, __LINE__); printf(msg); printf("\r\n");
#else
#define	_DBGF(part,level,...)
#define	_DBG(part,level,msg)
#endif

#define	_RETURN(x) DBG_RETURN(STATECHART_IMPL,x)	//!< RETURN-Makro

/* Typen **********************************************************************/

/* Prototypen *****************************************************************/

/* Variablen ******************************************************************/

/* Funktionen *****************************************************************/

//************* actions **************************
extern 	void 	statechart_impl_quit_app (
       	STATECHART_SM_CTRL    	*sm,
       	STATECHART_COMMON_EVT 	*evt)
{
	exit(EXIT_SUCCESS);
}

/*!
********************************************************************************
@brief	#

#

@usage
\code
-
\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
extern 	void 	statechart_impl_write_p (
       	STATECHART_SM_CTRL    	*sm,
       	STATECHART_COMMON_EVT 	*evt)
{
	printf(" P \r\n");
}

/*!
********************************************************************************
@brief	#

#

@usage
\code
-
\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
extern 	void 	statechart_impl_write_ping (
       	STATECHART_SM_CTRL    	*sm,
       	STATECHART_COMMON_EVT 	*evt)
{
	printf(" PING \r\n");
}

/*!
********************************************************************************
@brief	#

#

@usage
\code
-
\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
extern 	void 	statechart_impl_write_pong (
       	STATECHART_SM_CTRL    	*sm,
       	STATECHART_COMMON_EVT 	*evt)
{
	printf(" PONG \r\n");
}

extern 	void 	statechart_impl_write_q (
       	STATECHART_SM_CTRL    	*sm,
       	STATECHART_COMMON_EVT 	*evt)
{
	printf(" Q \r\n");
}

/*!
********************************************************************************
@brief	#

#

@usage
\code
-
\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
extern 	void 	statechart_impl_write_timeout (
       	STATECHART_SM_CTRL    	*sm,
       	STATECHART_COMMON_EVT 	*evt)
{
	printf(" TIMEOUT \r\n");
}

//************* guards **************************
/*!
********************************************************************************
@brief	#

#

@usage
\code
-
\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
extern 	BOOL 	statechart_impl_is_p (
       	STATECHART_SM_CTRL    	*sm,
       	STATECHART_COMMON_EVT 	*evt)
{
	if (evt->id == STATECHART_SM_EVTID_KEY)
	{
		if (evt->data.key == 'p')
		{
			return TRUE;
		}
	}

	return FALSE;
}

/*!
********************************************************************************
@brief	#

#

@usage
\code
-
\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
extern 	BOOL 	statechart_impl_is_q (
       	STATECHART_SM_CTRL    	*sm,
       	STATECHART_COMMON_EVT 	*evt)
{
	if (evt->id == STATECHART_SM_EVTID_KEY)
	{
		if (evt->data.key == 'q')
		{
			return TRUE;
		}
	}

	return FALSE;
}


#ifdef __RCS
/*!
********************************************************************************
@brief	Diese Funktion ermittelt die RCS-Information des Moduls

@return	Zeiger auf die RCS-Information des Moduls oder,
@return	falls \c __RCS_INFO nicht definiert, NULL
********************************************************************************
*/
extern	char	*statechart_impl_getrcsid (void)
{
#ifdef __RCS_INFO
	return "$Id:$";
#else
	return NULL;
#endif
}
#endif

/* Aenderungsjournal **********************************************************/
#ifdef __DOCGEN
/*!
@page revisions Revisions

@subsection rcslog_statechart_impl_c statechart_impl.c
@verbatim
 * $Log: $
@endverbatim
*/
#endif
