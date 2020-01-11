/*   -*- buffer-read-only: t -*- vi: set ro:
 *  
 *  DO NOT EDIT THIS FILE   (server-fsm.h)
 *  
 *  It has been AutoGen-ed  November 30, 2010 at 05:19:22 PM by AutoGen 5.10
 *  From the definitions    server.def
 *  and the template file   fsm
 *
 *  Automated Finite State Machine
 *
 *  copyright (c) 2001-2009 by Bruce Korb - all rights reserved
 *
 *  AutoFSM is free software copyrighted by Bruce Korb.
 *  
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name ``Bruce Korb'' nor the name of any other
 *     contributor may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *  
 *  AutoFSM IS PROVIDED BY Bruce Korb ``AS IS'' AND ANY EXPRESS
 *  OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED.  IN NO EVENT SHALL Bruce Korb OR ANY OTHER CONTRIBUTORS
 *  BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 *  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 *  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  This file enumerates the states and transition events for a FSM.
 *
 *  te_server_fsm_state
 *      The available states.  FSS_INIT is always defined to be zero
 *      and FSS_INVALID and FSS_DONE are always made the last entries.
 *
 *  te_server_fsm_event
 *      The transition events.  These enumerate the event values used
 *      to select the next state from the current state.
 *      SERVER_FSM_EV_INVALID is always defined at the end.
 */
#ifndef AUTOFSM_SERVER_FSM_H_GUARD
#define AUTOFSM_SERVER_FSM_H_GUARD 1

/*
 *  Finite State machine States
 *
 *  Count of non-terminal states.  The generated states INVALID and DONE
 *  are terminal, but INIT is not  :-).
 */
#define SERVER_FSM_STATE_CT  4
typedef enum {
    SERVER_FSM_ST_INIT,          SERVER_FSM_ST_USER_KNOWN,
    SERVER_FSM_ST_AUTHORIZATION, SERVER_FSM_ST_SESSION,
    SERVER_FSM_ST_INVALID,       SERVER_FSM_ST_DONE
} te_server_fsm_state;

/*
 *  Finite State machine transition Events.
 *
 *  Count of the valid transition events
 */
#define SERVER_FSM_EVENT_CT 8
typedef enum {
    SERVER_FSM_EV_TIMEOUT,           SERVER_FSM_EV_CMD_PROCEED,
    SERVER_FSM_EV_CMD_QUIT,          SERVER_FSM_EV_CMD_USER,
    SERVER_FSM_EV_CMD_PASSW,         SERVER_FSM_EV_PASSWORD_ACCEPTED,
    SERVER_FSM_EV_PASSWORD_INVALID,  SERVER_FSM_EV_TOO_MANY_ATTEMPTS,
    SERVER_FSM_EV_INVALID
} te_server_fsm_event;

/*
 *  Step the FSM.  Returns the resulting state.  If the current state is
 *  SERVER_FSM_ST_DONE or SERVER_FSM_ST_INVALID, it resets to
 *  SERVER_FSM_ST_INIT and returns SERVER_FSM_ST_INIT.
 */
extern te_server_fsm_state
server_fsm_step(
    te_server_fsm_state server_fsm_state,
    te_server_fsm_event trans_evt,
    const char *cmd,
    void *state );

#endif /* AUTOFSM_SERVER_FSM_H_GUARD */
/*
 * Local Variables:
 * mode: C
 * c-file-style: "stroustrup"
 * indent-tabs-mode: nil
 * End:
 * end of server-fsm.h */
