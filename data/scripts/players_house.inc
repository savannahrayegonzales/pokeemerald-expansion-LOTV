PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet::
	lockall
	msgbox PlayersHouse_2F_Text_ReminderToSetClock, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, PlayersHouse_2F_Movement_PushBackFromStairs
	waitmovement 0
	releaseall
	end

PlayersHouse_2F_Movement_PushBackFromStairs:
	walk_up
	step_end

PlayersHouse_2F_Text_ReminderToSetClock:
	.string "Hmm, I wonder what time it is.\p"
	.string "If only I had a clock...$"

LittlerootTown_BrendansHouse_2F_EventScript_WallClock::
	lockall
	setvar VAR_0x8004, MALE
	goto PlayersHouse_2F_EventScript_WallClock
	end

LittlerootTown_MaysHouse_2F_EventScript_WallClock::
	lockall
	setvar VAR_0x8004, FEMALE
	goto PlayersHouse_2F_EventScript_WallClock
	end

PlayersHouse_2F_EventScript_WallClock::
	goto_if_set FLAG_SET_WALL_CLOCK, PlayersHouse_2F_EventScript_CheckWallClock
	msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	delay 30
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_SET_WALL_CLOCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
	@checkplayergender
	@call_if_eq VAR_RESULT, MALE, PlayersHouse_2F_EventScript_MomComesUpstairsMale
	@call_if_eq VAR_RESULT, FEMALE, PlayersHouse_2F_EventScript_MomComesUpstairsFemale
	playse SE_EXIT
	removeobject VAR_0x8008
	releaseall
	end

PlayersHouse_2F_EventScript_CheckWallClock::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	releaseall
	end

PlayersHouse_2F_EventScript_SetWallClock::
	fadescreen FADE_TO_BLACK
	special StartWallClock
	return

PlayersHouse_2F_EventScript_MomComesUpstairsMale::
    end

PlayersHouse_2F_EventScript_MomComesUpstairsFemale::
    end

EventScript_RunningShoesManual::
	msgbox PlayersHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
	end
