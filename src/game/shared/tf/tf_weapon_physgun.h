//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//=============================================================================

#ifndef TF_WEAPON_PHYSGUN_H
#define TF_WEAPON_PHYSGUN_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_weaponbase_gun.h"

#if defined( CLIENT_DLL )
#define CTFPhysgun C_TFPhysgun
#endif

//=============================================================================
//
// Physgun class.
//
class CTFPhysgun : public CTFWeaponBase
{
public:

	DECLARE_CLASS( CTFPhysgun, CTFWeaponBase );
	DECLARE_NETWORKCLASS(); 
	DECLARE_PREDICTABLE();

	CTFPhysgun();

	virtual int		GetWeaponID( void ) const			{ return TF_WEAPON_PHYSGUN; }
	virtual void	PrimaryAttack() OVERRIDE;
	virtual void	SecondaryAttack() OVERRIDE;

private:

	CTFPhysgun( const CTFPhysgun & ) {}
};

#endif // TF_WEAPON_PHYSGUN_H
