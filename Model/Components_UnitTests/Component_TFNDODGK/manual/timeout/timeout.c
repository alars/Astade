/*******************************************************************************
(c) 2008 by dSys e.K.

$Id: timeout.c,v 1.2 2008/03/12 19:24:50 a.becker Exp $ $Name:  $
*******************************************************************************/

/*!
********************************************************************************
@file timeout.c

@moduleinformation
  MODULNAME EINTRAGEN !

@preprocessor
  .

@verbatim
$Id: timeout.c,v 1.2 2008/03/12 19:24:50 a.becker Exp $ $Name:  $
@endverbatim
RCS-Logs:
@ref rcslog_timeout_c
********************************************************************************
*/

#ifdef __RCS
/* Name der Funktion, die die RCS-Information ermittelt */
#define	GETLOCALRCSID	timeout_getrcsid
#endif

#define	TIMEOUT_C
/* Include-Dateien ************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "timeout.h"
// #include "dbg.h"
#include "prjset.h"

/* Konstanten *****************************************************************/
/*! @brief Debugstufen fuer die jeweiligen Modulbereiche */
#define	_DBG_LEVEL_VOID		DBG_LEVEL_WARN		//!< Standardbereich

/*! @brief interne Modulzustaende */
#define	_MSTATE_INIT	0x01				//!< Modul initialisiert

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

/* Typen ***********************************************v2 eingefügt***********************/

/* Prototypen *****************************************************************/

/* Variablen ******************************************************************/
static	int		_mstate;	//!< interner Modulzustand

static	TIMEOUT_HDL	_entry;		//!< Einstiegspunkt zur verketteten Timerliste

static	struct timespec	_to;
static	struct timeval	_tv_old;

/* Funktionen *******************************************v2 eingefügt**********************/

static	void	_get_timediff_last_ms (
	int	*timediff_ms)
{
	struct timeval	tv_now;
	struct timeval	tv_sub;

	gettimeofday(&tv_now, NULL);
	timersub(&tv_now, &_tv_old, &tv_sub);
	if (timediff_ms != NULL)
	{
		*timediff_ms = (tv_sub.tv_sec * 1000 + tv_sub.tv_usec / 1000);
	}

	_tv_old = tv_now;
	if (timediff_ms != NULL)
	{
		_DBGF(VOID, NOTICE, "timediff_ms %u", *timediff_ms);
	}
}

static	void	_timer_dump (void)
{
	TIMEOUT_HDL	*my;
	
	for (my = _entry.next; my != NULL; my = my->next)
	{
		_DBGF(VOID, INFO, "Timer: \"%s\", startval: %u, current_val: %u", my->name, my->time_ms_startval, my->time_ms);
	}
}

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
extern	TIMEOUT_RET	timeout_init (void)
{

	if (_mstate & _MSTATE_INIT)
	{
		_RETURN(TIMEOUT_RET_E_ALREADY_INIT);
	}

	_mstate |= _MSTATE_INIT;
	gettimeofday(&_tv_old, NULL);
	
	return TIMEOUT_RET_OK;
}

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
	struct timespec	**timeout)	//!< \c o: naechste Timeout Variable oder NULL (Pointer, die Struktur wird intern gehalten)
{
	int		timediff_ms;
	TIMEOUT_HDL	*my;
	TIMEOUT_HDL	*my_old;

	if (!(_mstate & _MSTATE_INIT))
	{
		_RETURN(TIMEOUT_RET_E_NOT_INIT);
	}
	
	// --- Neuen Timeout bestimmen ---
	if (_entry.next == NULL)
	{
		// Es stehen keine Timeouts an
		*timeout = NULL;	
	}
	else
	{
		//--->>> bereits abgelaufene Zeit bestimmen und ggf. Timeouts ausfuehren
		_get_timediff_last_ms(&timediff_ms);
#if 0
		if (time == SYS_ARCH_TIMEOUT) {
		/* If time == SYS_ARCH_TIMEOUT, a timeout occured before a message
		could be fetched. We should now call the timeout handler and
		deallocate the memory allocated for the timeout. */
		tmptimeout = timeouts->next;
		timeouts->next = tmptimeout->next;
		h = tmptimeout->h;
		arg = tmptimeout->arg;
		memp_free(MEMP_SYS_TIMEOUT, tmptimeout);
		if (h != NULL) {
			LWIP_DEBUGF(SYS_DEBUG, ("ssw h=%p(%p)\n", (void *)h, (void *)arg));
			h(arg);
		}

		/* We try again to fetch a message from the mbox. */
		goto again;
		} else {
		/* If time != SYS_ARCH_TIMEOUT, a message was received before the timeout
		occured. The time variable is set to the number of
		milliseconds we waited for the message. */
		if (time <= timeouts->next->time) {
		timeouts->next->time -= time;
		} else {
		timeouts->next->time = 0;
		}
		}
#endif
		
		// Handle erst aus der Liste herrausloesen + Timer korrigieren, dann Callbacks ausfuehren
		
		// Solange Callbacks ausfuehren + CB loeschen, bis die Zeit erreicht wurde, dann verbleibende Timeoutzeit abspeichern
		for ( my = _entry.next, my_old = NULL; my != NULL && (timediff_ms > 0); my_old = my, my = my->next)
		{
			// Zeit treffer / ueberschreitung?
			if (my->time_ms <= timediff_ms)
			{
				// Zeit ist abgelaufen 

				// Timer aus Liste entfernen 
				if (my_old == NULL)
				{
					 _entry.next = my->next; // Handler aus der Liste entfernen
				}
				else
				{
					my_old->next = my->next; // Handler aus der Liste entfernen
				}
				
				//Callback ausfuehren
				_DBGF(VOID, NOTICE, "exec Timer %s my->time_ms %u <= timediff_ms %u", my->name, my->time_ms, timediff_ms);
				my->cb(my->cb_arg);	// Handler ausfuehren

				break; // ICh treffe die Annahme, dass es kaum verzoegerungen bei der Ausfuehrung der Timer gab.
				
/*				while ((my->next != NULL) && (my->next->time_ms == 0))
				{
					my = my->next;	// gleich den naechsten ausfuehren
					my_old->next = my->next; // Handler aus der Liste entfernen
					
					_DBGF(VOID, NOTICE, "exec Timer %s", my->name);
					my->cb(my->cb_arg);	// Handler ausfuehren
				}
				timediff_ms -= my->time_ms;*/
			}
			else
			{
				// War nicht groesser, abziehen und fertig.
				my->time_ms -= timediff_ms;
				break;
			}
		}

		if (_entry.next == NULL)
		{
			// Es stehen keine Timeouts an
			_DBGF(VOID, NOTICE," No timer started");
			*timeout = NULL;	
			
		}
		else
		{
			_DBGF(VOID, INFO, "next timer: %s in %u ms, timediff_ms %d", _entry.next->name, _entry.next->time_ms, timediff_ms);
			_to.tv_sec = (_entry.next->time_ms/*- timediff_ms*/) / 1000;
			_to.tv_nsec = ((_entry.next->time_ms/*- timediff_ms*/) % 1000) * 1000/*[us/ms]*/ * 1000 /*[ns/us]*/ ;
			*timeout = &_to;
		}

	}

	_timer_dump();
	
	_RETURN(TIMEOUT_RET_OK);
}

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
	char		*name)		//!< \c i: Name fuer das Timeout handle -> maximal TIMEOUT_NAMELEN lan
{
	if (!(_mstate & _MSTATE_INIT))
	{
		_RETURN(TIMEOUT_RET_E_NOT_INIT);
	}
	
	memset(hdl, 0, sizeof(TIMEOUT_HDL));
	
	hdl->cb = callback;	//!< Callback bei Timeout
	hdl->cb_arg = arg;	//!< Argument des Callbacks
// 	hdl->next = NULL;	//!< naechstes Handle in der aus
	
	strncpy(hdl->name, name, TIMEOUT_NAMELEN);

	_RETURN(TIMEOUT_RET_OK);
}

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
	int		timeout_ms)	//!< \c i: Zeit in [ms] nach der Timeout kommen soll
{
	if (!(_mstate & _MSTATE_INIT))
	{
		_RETURN(TIMEOUT_RET_E_NOT_INIT);
	}
	
	timeout_stop(hdl);

	
	hdl->next = NULL;
	hdl->time_ms = timeout_ms;
	hdl->time_ms_startval = timeout_ms;

	_DBGF(VOID, NOTICE, "set timer %s to %d", hdl->name, timeout_ms);

	if (_entry.next == NULL)
	{
		// Erstes Element, Timer neu starten
		_get_timediff_last_ms(NULL); 
		_entry.next = hdl;
	}
	else
	{
		if (_entry.next->time_ms > hdl->time_ms)
		{
			// Hdl am Anfang einfuegen, vorher zeit korrigieren
			_entry.next->time_ms -= hdl->time_ms;
			hdl->next = _entry.next;
			_entry.next = hdl;
			_DBGF(VOID, NOTICE, "set to first timer");
		}
		else
		{
			// Hdl in der Kette einfuegen
			TIMEOUT_HDL	*my;
			
			for (my = _entry.next; my != NULL; my = my->next)
			{
				hdl->time_ms -= my->time_ms;
				if ((my->next == NULL) ||
				    (my->next->time_ms > hdl->time_ms))
				{
					// Davor einfuegen
					if (my->next != NULL)	
					{	// Kommt noch einer hinten drann -> Vorher abziehen
						my->next->time_ms -= hdl->time_ms;
					}

					//Einfuegen
					hdl->next = my->next; // auch NULL
					my->next = hdl;
					
					break; // Ende
				}
			}
		}
	}
	_timer_dump();
	
	_RETURN(TIMEOUT_RET_OK);
}

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
	TIMEOUT_HDL	*hdl)		//!< \c m: Referenz auf das Timerhandle
{
	TIMEOUT_HDL	*my;
	TIMEOUT_HDL	*old;

	if (!(_mstate & _MSTATE_INIT))
	{
		_RETURN(TIMEOUT_RET_E_NOT_INIT);
	}
	
	//Dieses Handle in der Liste finden und aushaengen
	if (_entry.next == NULL)
	{
		_RETURN(TIMEOUT_RET_NOT_RUNING);
	}

	for (my = _entry.next, old = NULL; my != NULL; old = my, my = my->next)
	{
		if (my == hdl)
		{
			/* Gefunden ! */
			// Aus Liste austragen
			if (old == NULL)
			{
				_entry.next = my->next;
			}
			else
			{
				old->next = my->next;
			}

			/* Zeit korrigierne, falls es nicht das letzte Handle war*/
			if (my->next != NULL)
			{
				my->next->time_ms += hdl->time_ms;
			}
// 			return;
			break;
		}
	}

	_timer_dump();
	
	_RETURN(TIMEOUT_RET_OK);
}

#ifdef __RCS
/*!
********************************************************************************
@brief	Diese Funktion ermittelt die RCS-Information des Moduls

@return	Zeiger auf die RCS-Information des Moduls oder,
@return	falls \c __RCS_INFO nicht definiert, NULL
********************************************************************************
*/
extern	char	*timeout_getrcsid (void)
{
#ifdef __RCS_INFO
	return "$Id: timeout.c,v 1.2 2008/03/12 19:24:50 a.becker Exp $";
#else
	return NULL;
#endif
}
#endif

/* Aenderungsjournal **********************************************************/
#ifdef __DOCGEN
/*!
@page revisions Revisions

@subsection rcslog_timeout_c timeout.c
@verbatim
 * $Log: timeout.c,v $
 * Revision 1.2  2008/03/12 19:24:50  a.becker
 * Bacnet Stack update auf Version 01.01.Test..
 *
 * Revision 1.1  2008/02/11 17:20:31  becker
 * Receive State Machine funktioniert. (getestet)
 *
@endverbatim
*/
#endif
