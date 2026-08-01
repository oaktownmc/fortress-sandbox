//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//=============================================================================

#include "cbase.h"
#include "tf_weapon_physgun.h"
#include "decals.h"

// Client specific.
#if defined( CLIENT_DLL )
#include "c_tf_player.h"
#include "clientmode_shared.h"
#include "hud_element_helper.h"
#include "hud_basechat.h"
#include "hud_chat.h"

// Server specific.
#else
#include "tf_player.h"
#endif

//=============================================================================
//
// Weapon Physgun tables.
//

IMPLEMENT_NETWORKCLASS_ALIASED( TFPhysgun, DT_TFWeaponPhysgun )

BEGIN_NETWORK_TABLE( CTFPhysgun, DT_TFWeaponPhysgun )
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA( CTFPhysgun )
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS( tf_weapon_physgun, CTFPhysgun );
PRECACHE_WEAPON_REGISTER( tf_weapon_physgun );

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
CTFPhysgun::CTFPhysgun()
{
	m_bReloadsSingly = true;
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void CTFPhysgun::PrimaryAttack()
{
	if ( !CanAttack() )
		return;
	
#if CLIENT_DLL
	CBaseHudChat *pHUDChat = ( CBaseHudChat * ) GET_HUDELEMENT( CHudChat );
	pHUDChat->ChatPrintf( 0, CHAT_FILTER_NONE, "primary attack" );
#endif

	BaseClass::PrimaryAttack();
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void CTFPhysgun::SecondaryAttack()
{
	if ( !CanAttack() )
		return;
	
#if CLIENT_DLL
	CBaseHudChat *pHUDChat = ( CBaseHudChat * ) GET_HUDELEMENT( CHudChat );
	pHUDChat->ChatPrintf( 0, CHAT_FILTER_NONE, "secondary attack" );
#endif

	BaseClass::SecondaryAttack();
}