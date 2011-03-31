/*******************************************************************************
(c) 2008 by dSys e.K.

$Id: $ $Name: $
*******************************************************************************/

/*!
********************************************************************************
@file statechart_common.c

@moduleinformation
  MODULNAME EINTRAGEN !

@preprocessor
  .

@verbatim
$Id: $ $Name: $
@endverbatim
RCS-Logs: 
@ref rcslog_statechart_common_c
********************************************************************************
*/

#ifdef __RCS
/* Name der Funktion, die die RCS-Information ermittelt */
#define	GETLOCALRCSID	statechart_common_getrcsid
#endif

#define	STATECHART_COMMON_C

/* Include-Dateien ************************************************************/
#include <stdlib.h>
#include <string.h>

#include "statechart_common.h"
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

#define	_RETURN(x) return(x)	//!< RETURN-Makro

/* Typen **********************************************************************/

/* Prototypen *****************************************************************/

/* Variablen ******************************************************************/
static	int	_mstate;	//!< interner Modulzustand

static	struct statechart_sm_ctrl	_sm;	//!< The Statechart

/* Funktionen *****************************************************************/
/*!
********************************************************************************
@brief	Einen Event an die SM leiten

Vorher ggf. noch die Daten pruefen.

@usage
\code

\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
static	STATECHART_COMMON_RET		_event_generate	(
	STATECHART_SM_EVTID		id,
	STATECHART_COMMON_EVT_DATA	*data)
{
	STATECHART_COMMON_EVT	evt;
	BOOL			taken;
	
	if (!_mstate & _MSTATE_INIT)
	{
		_RETURN(STATECHART_COMMON_RET_E_NOT_INIT);
	}
	
	// TODO: Check that Events + data are matching!
	evt.id = id;
	if (data != NULL)
	{
		evt.data = *data;	//copy Data
	}
	else
	{
		evt.data.key = '\0';
	}

	_DBGF(VOID, WARN, "Event (%u:, ... @ State: %p) : ", evt.id, _sm.the_state);
	
	taken = statechart_sm_take_event( &_sm, &evt);
	if (!taken)
	{
		_DBGF(VOID, WARN, "Event (%u:, ... @ State: %p) not taken!", evt.id, _sm.the_state);
		_RETURN(STATECHART_COMMON_RET_NOT_TAKEN);
	}
	_DBGF(VOID, WARN, "Event (%u:, ... @ State: %p) OK", evt.id, _sm.the_state);
	_RETURN(STATECHART_COMMON_RET_OK);
}

/*!
********************************************************************************
@brief	Timeout aufgetreten

@usage
\code

\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
static	void	_timeout_cb (
	void	*arg)
{
	arg = arg;
	
	_event_generate(STATECHART_SM_EVTID_TIMEOUT, NULL);
}


/*!
********************************************************************************
@brief	Modul initialisieren

Diese Funktion initialisiert das Modul und muss vor dem Aufruf jeder anderen
Modulfunktion einmal aufgerufen werden.
Es wird ein Timer angelegt und ein Statechart-zustandsautomat initialisiert.
Der Statechart wird mit dem ersten Evenet versehen.

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
extern	STATECHART_COMMON_RET	statechart_common_init (void)
{
	STATECHART_COMMON_EVT	evt;
	TIMEOUT_RET		ret_timeout;

	if (_mstate & _MSTATE_INIT)
	{
		return STATECHART_COMMON_RET_E_ALREADY_INIT;
	}
	
	// Timeout anlegen (Timeout Modul muss bereits initialisiert sein.)
	ret_timeout = timeout_create(&(_sm.tmr.timeout), _timeout_cb, &_sm, "STATECHART_TMR");
	if (ret_timeout >= TIMEOUT_RET_E)
	{
		_RETURN(STATECHART_COMMON_RET_E_CREATE_TIMEOUT);
	}
	
	// Statemachine initialisieren	
	memset(&evt, 0, sizeof(evt));
	evt.id = 0;
	
	statechart_sm_init(&_sm, &evt);
	
	_mstate |= _MSTATE_INIT;

	_RETURN(STATECHART_COMMON_RET_OK);
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
extern	STATECHART_COMMON_RET	statechart_common_evt_key (
	char			*key)
{
	STATECHART_COMMON_EVT_DATA	evt_data;
	
	evt_data.key = *key;

	return _event_generate(STATECHART_SM_EVTID_KEY, &evt_data);
}


#ifdef __RCS
/*!
********************************************************************************
@brief	Diese Funktion ermittelt die RCS-Information des Moduls

@return	Zeiger auf die RCS-Information des Moduls oder,
@return	falls \c __RCS_INFO nicht definiert, NULL
********************************************************************************
*/
extern	char	*statechart_common_getrcsid (void)
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

@subsection rcslog_statechart_common_c statechart_common.c
@verbatim
 * $Log: $
@endverbatim
*/
#endif
