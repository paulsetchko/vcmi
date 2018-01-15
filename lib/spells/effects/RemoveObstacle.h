/*
 * RemoveObstacle.h, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */

#pragma once

#include "LocationEffect.h"

#include "../../GameConstants.h"

struct CObstacleInstance;
struct BattleObstaclesChanged;

namespace spells
{
namespace effects
{

class RemoveObstacle : public LocationEffect
{
public:
	RemoveObstacle(const int level);
	virtual ~RemoveObstacle();

	bool applicable(Problem & problem, const Mechanics * m) const override;
	bool applicable(Problem & problem, const Mechanics * m, const Target & aimPoint, const EffectTarget & target) const override;

protected:
	void apply(BattleStateProxy * battleState, RNG & rng, const Mechanics * m, const EffectTarget & target) const override;
	void serializeJsonEffect(JsonSerializeFormat & handler) override;

private:
    bool removeAbsolute;
    bool removeUsual;
    bool removeAllSpells;

    std::set<SpellID> removeSpells;

    bool canRemove(const CObstacleInstance * obstacle) const;

	std::set<const CObstacleInstance *> getTargets(const Mechanics * m, const EffectTarget & target, bool alwaysMassive) const;
};

}
}