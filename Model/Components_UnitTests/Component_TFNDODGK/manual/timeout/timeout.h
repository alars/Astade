/*******************************************************************************
(c) 2008 by dSys e.K.

$Id: timeout.h,v 1.3 2008/04/02 12:55:56 a.becker Exp $ $Name:  $
*******************************************************************************/

/*!
********************************************************************************
@file timeout.h

@moduleinformation
  MODULNAME EINTRAGEN !

@moduledescription
  #

@moduleglossary
  .

@preprocessor
  .

@verbatim
$Id: timeout.h,v 1.3 2008/04/02 12:55:56 a.becker Exp $ $Name:  $
@endverbatim
RCS-Logs:
@ref rcslog_timeout_h
********************************************************************************
*/

#ifndef TIMEOUT_H
#define	TIMEOUT_H

#ifdef __cplusplus
// extern "C" {
#endif


/* Include-Dateien ************************************************************/
// #include "pdt.h"
#include <sys/time.h>

/* Konstanten *****************************************************************/
#define	TIMEOUT_NAMELEN	20

/* Makros ****************************************
#endif*****************************/

/* Typen **********************************************************************/
enum timeout_ret
{
	TIMEOUT_RET_OK,			//!< Ausführung erfolgreich
	TIMEOUT_RET_RESTARTED,		//!< Timer war bereits gestartet, wurde neu gestartet
	TIMEOUT_RET_NOT_RUNING,		//!< Timer war nicht gestartet, wurde aber gestopt
	TIMEOUT_RET_E,			//!< Fehler, unspezifiziert
	TIMEOUT_RET_E_ALREADY_INIT,	//!< Modul ist bereits initialisiert
	TIMEOUT_RET_E_NOT_INIT,		//!< Modul nicht initialisiert
};

typedef enum timeout_ret TIMEOUT_RET;

typedef void (*TIMEOUT_CB)( void *arg);

typedef struct timeout_hdl
{
	TIMEOUT_CB		cb;		//!< Callback bei Timeout
	void			*cb_arg;		//!< Argument des Callbacks
	int			time_ms;		/*!< noch verbleibende Zeit bis 
			zum Ablauf als Differenz zum vorhergehenden timeout */
	int			time_ms_startval;		/*!< Anfangszeit */
	
	struct timeout_hdl	*next;		//!< naechstes Handle in der aus
	char		name[TIMEOUT_NAMELEN+1];
} TIMEOUT_HDL;

/* Prototypen *****************************************************************/
/*!
********************************************************************************
@brief	Timeout Modul initialisieren

Initialisiert das Timeout Modul.

@usage
\code

\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
extern	TIMEOUT_RET	timeout_init (void);

/*!
********************************************************************************
@brief	Timouts ueberpruefen

Diese Funktion ueberprueft die angemeldeten Timeout handler. Im Kontext dieser 
Funktion werden ggf. die Callback Funktion ausgefuehrt.

@usage
\code

\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
extern	TIMEOUT_RET	timeout_check (
	struct timespec	**timeout);	//!< \c o: naechste Timeout Variable oder NULL (Pointer, die Struktur wird intern gehalten)

/*!
********************************************************************************
@brief	Timeout anlegen

Initialisiert ein Timeout handler.

@usage
\code
static	TIMEOUT_HDL	_to_hdl;

static	void _timeout_handler (void *arg)
{
	// Do something
}


extern	void	my_fkt (void)
{
	TIMEOUT_RET	ret;
	
	ret = timeout_init();
	if (ret != TIMEOUT_RET_OK)
	{
		_DBGF(VOID, ERROR, "Dings Fehler ret: %u", ret);
		return;
	}
	
	ret = timeout_create( &_to_hdl, _to_hdl, NULL, "MY MODUL Timer");
	if (ret != TIMEOUT_RET_OK)
	{
		_DBGF(VOID, ERROR, "Dings Fehler ret: %u", ret);
		return;
	}
}
\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
extern	TIMEOUT_RET	timeout_create (
	TIMEOUT_HDL	*hdl,		//!< \c o: Referenz auf das zu initialisierende Handle
	TIMEOUT_CB	callback,	//!< \c i: Handle, das bei einem Timeout aufgerufen wird
	void		*arg,		//!< \c i: Argument, mit dem die Callbackfunktion aufgerufen wird.
	char		*name);		//!< \c i: Name fuer das Timeout handle -> maximal TIMEOUT_NAMELEN lan

#if 0
/*!
********************************************************************************
@brief	Timeout loeschen

Initialisiert ein Timeout handler.

@usage
\code
static	TIMEOUT_HDL	_to_hdl;

extern	void	my_fkt (void)
{
	TIMEOUT_RET	ret;
		
	ret = timeout_delete( &_to_hdl);
	if (ret != TIMEOUT_RET_OK)
	{
		_DBGF(VOID, ERROR, "Dings Fehler ret: %u", ret);
		return;
	}
}
\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
extern	TIMEOUT_RET	timeout_delete (
	TIMEOUT_HDL	*hdl);		//!< \c o: Referenz auf das zu initialisierende Handle
#endif

/*!
********************************************************************************
@brief	Timeout neu starten

startet einen Timer mit einem neuen Timeout. Der Alte Wert wird geloescht.

@usage
\code
static	TIMEOUT_HDL	_to_hdl;

static	void _timeout_handler (void *arg)
{
	// Do something
}


extern	void	my_fkt (void)
{
	TIMEOUT_RET	ret;
	
	ret = timeout_restart( &_to_hdl,	500);
}
\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
extern	TIMEOUT_RET	timeout_start (
	TIMEOUT_HDL	*hdl,		//!< \c m: Referenz auf das Timerhandle
	int		timeout_ms);	//!< \c i: Zeit in [ms] nach der Timeout kommen soll

#if 0
/*!
********************************************************************************
@brief	Timeout neu starten

stopt einen Timer.

@usage
\code
static	TIMEOUT_HDL	_to_hdl;

extern	void	my_fkt (void)
{
	TIMEOUT_RET	ret;
	
	ret = timeout_restart( &_to_hdl);
}

\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
extern	TIMEOUT_RET	timeout_reload (
	TIMEOUT_HDL	*hdl);		//!< \c m: Referenz auf das Timerhandle
#endif

/*!
********************************************************************************
@brief	Timeout stoppen

stopt einen Timer.

@usage
\code
static	TIMEOUT_HDL	_to_hdl;

extern	void	my_fkt (void)
{
	TIMEOUT_RET	ret;
	
	ret = timeout_stop( &_to_hdl);
}

\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
extern	TIMEOUT_RET	timeout_stop (
	TIMEOUT_HDL	*hdl);		//!< \c m: Referenz auf das Timerhandle

#if 0
/*!
********************************************************************************
@brief	Callback Funktion aendern

SEtzt die Callback Funktion neu.

@usage
\code
static	TIMEOUT_HDL	_to_hdl;

static	void _timeout_handler (void *arg)
{
	// Do something, "MY frist Timer"
}


extern	void	my_fkt (void)
{
	TIMEOUT_RET	ret;
	
	ret = timeout_callback_set( &_to_hdl, _to_hdl, NULL);
	if (ret != TIMEOUT_RET_OK)
	{
		_DBGF(VOID, ERROR, "Dings Fehler ret: %u", ret);
		return;
	}
}
\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
extern	TIMEOUT_RET	timeout_callback_set (
	TIMEOUT_HDL	*hdl,		//!< \c m: Referenz auf das Timerhandle
	TIMEOUT_CB	callback,	//!< \c i: Handle, das bei einem Timeout aufgerufen wird
	void		*arg);		//!< \c i: Argument, mit dem die Callbackfunktion aufgerufen wird.
#endif

#ifdef __RCS
extern	char		*timeout_getrcsid (void);
#endif

#ifdef __cplusplus
// }
#endif

/* Aenderungsjournal **********************************************************/
#ifdef __DOCGEN
/*!
@page revisions Revisions

@subsection rcslog_timeout_h timeout.h
@verbatim
 * $Log: timeout.h,v $

@endverbatim
*/
#endif
#endif
