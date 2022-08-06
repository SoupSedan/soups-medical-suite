class CfgPatches
{
	class Thermal_Damage_OPTRE
	{
		author="Soup";
		url="";
		requiredaddons[]={};
		requiredversion=1;
		units[]={};
		weapons[]={};
		ammo[]=
		{
			"OPTRE_FC_Bolt_Base",
			"OPTRE_FC_T51_Repeater_Bolt",
			"OPTRE_FC_T51J_Repeater_Bolt",
			"OPTRE_FC_T25_Rifle_Bolt",
			"OPTRE_FC_T25J_Rifle_Bolt",
			"OPTRE_FC_PlasmaPistol_Bolt",
			"OPTRE_FC_T51_Rod",
			"OPTRE_FC_T50_SRS_Bolt",
			"OPTRE_FC_T33_FuelRod",
			"OPTRE_FC_T33_FuelRod_Guided",
			"OPTRE_FC_HeavyPlasma_Bolt_AAA",
			"OPTRE_FC_HeavyPlasma_Bolt_AAG",
			"OPTRE_FC_HeavyPlasma_Bolt_AG",
			"OPTRE_FC_HeavyNeedle",
			"OPTRE_FC_C2_Cannon_Bolt",
			"OPTRE_FC_T33_FuelRod_Veh",
			"OPTRE_FC_T33_FuelRod_VehAA",
			"OPTRE_AA_Big_Needler_ammo"
		};
		magazines[]={};
	};
};
class CfgAmmo {
	class OPTRE_FC_Bolt_Base {
		ACE_damageType = "SOUP";
	};
	class OPTRE_FC_T51_Repeater_Bolt {
		ACE_damageType = "SOUP";
	};
	class OPTRE_FC_T51J_Repeater_Bolt {
		ACE_damageType = "SOUP";
	};
	class OPTRE_FC_T25_Rifle_Bolt {
		ACE_damageType = "SOUP";
	};
	class OPTRE_FC_T25J_Rifle_Bolt {
		ACE_damageType = "SOUP";
	};
	class OPTRE_FC_PlasmaPistol_Bolt {
		ACE_damageType = "SOUP";
	};
	class OPTRE_FC_T51_Rod {
		ACE_damageType = "SOUP";
	};
	class OPTRE_FC_T50_SRS_Bolt {
		ACE_damageType = "SOUP";
	};
	class OPTRE_FC_T33_FuelRod {
		ACE_damageType = "SOUP";
	};
	class OPTRE_FC_HeavyPlasma_Bolt_AAA {
		ACE_damageType = "SOUP";
	};
	class OPTRE_FC_HeavyPlasma_Bolt_AAG {
		ACE_damageType = "SOUP";
	};
	class OPTRE_FC_HeavyPlasma_Bolt_AG {
		ACE_damageType = "SOUP";
	};
	class OPTRE_FC_HeavyNeedle {
		ACE_damageType = "SOUP";
	};
	class OPTRE_FC_C2_Cannon_Bolt {
		ACE_damageType = "SOUP";
	};
	class OPTRE_FC_T33_FuelRod_Veh {
		ACE_damageType = "SOUP";
	};
	class OPTRE_FC_T33_FuelRod_VehAA {
		ACE_damageType = "SOUP";
	};
	class OPTRE_AA_Big_Needler_ammo {
		ACE_damageType = "SOUP";
	};
};

class ACE_Medical_Injuries {

    class wounds {
	class Small_Plasma_Burn {
            bleeding = 0;
            pain = 1;
            causeLimping = 1;
	};

    class Medium_Plasma_Burn {
            bleeding = 0;
            pain = 2.0;
            causeLimping = 1;
	};
	
	class Large_Plasma_Burn {
			bleeding = 1;
			pain = 2.0;
			causeLimping = 1;
	};
     };

    class damageTypes {
        // default values used if a damage type does not define them itself
        thresholds[] = {{0.1, 1}};
        selectionSpecific = 1;

        // list of damage handlers, which will be called in reverse order
        // each entry should be a SQF expression that returns a function
        // this can also be overridden for each damage type
        class woundHandlers {
            ace_medical_damage = "ace_medical_damage_fnc_woundsHandlerBase";
        };

        // each sub-class defines a valid damage type
        class SOUP {
            // this is used to determine how many wounds to produce - see explanation above
            thresholds[] = {{0.7, 3}, {0.5, 2}, {0.3, 1}};

            // if 1, wounds are only applied to the most-damaged body part. if 0, wounds are applied to all damaged parts
            selectionSpecific = 1;

	class woundHandlers: woundHandlers {
                Soup_Energy_Weapon = "Soup_fnc_DamageHandler";
	};

            // one class for each type of wound this damage type is allowed to create
            // must match a wound type defined above
            class Medium_Plasma_Burn {
                // used to determine the chance of producing this type of wound instead of another - see explanation above
                weighting[] = {{1, 1}, {0.35, 1}, {0.35, 0}};

                // multiplier for incoming damage, applied before anything else is calculated (default: 1)
                damageMultiplier = 1;

                // multiplies the damage value used to determine wound size as shown in the UI.
                // size is used to scale bleeding & pain but *not* death or unconsciousness (default: 1)
                sizeMultiplier = 1;

                // multiplies bleeding rate (applied after size) (default: 1)
                bleedingMultiplier = 0;

                // multiplies pain produced (applied after size) (default: 1)
                painMultiplier = 2;

                // multiplies the probability to create fractures (default: 1)
                fractureMultiplier = 1;
            };
            	
	class Large_Plasma_Burn {
                weighting[] = {{1.5, 2}, {1.5, 1}, {0.35, 1}};
	};
	class Small_Plasma_Burn {
                weighting[] = {{0.35, 1}, {0.25, 1}, {0.35, 0}};
            };
            };
        };
    };
};
