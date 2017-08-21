#ifndef RECTEMPLATE__
#define RECTEMPLATE__

typedef std::vector <std::pair <std::pair <std::string, std::string>, std::string>> recTemplate;
typedef std::pair <std::string, std::string> pairTemplate;

const recTemplate recipes = 
{
	{ pairTemplate( "water", "water" ),"sea" },
	{ pairTemplate( "water", "air" ),"steam" },
	{ pairTemplate( "ground", "ground" ),"pressure" },
	{ pairTemplate( "fire", "water" ),"alcohol" },
	{ pairTemplate( "air", "air" ),"wind" },
	{ pairTemplate( "fire", "ground" ),"lava" },
	{ pairTemplate( "lava", "pressure" ),"volcano" },
	{ pairTemplate( "volcano", "sea" ),"island" },
	{ pairTemplate( "water", "ground" ),"swamp" },
	{ pairTemplate( "air", "lava" ),"stone" },
	{ pairTemplate( "stone", "fire" ),"metal" },
	{ pairTemplate( "swamp", "pressure" ),"turf" },
	{ pairTemplate( "alcohol", "turf" ),"scotch" },
	{ pairTemplate( "steam", "metal" ),"steam_boiler" },
	{ pairTemplate( "stone", "wind" ),"sand" },
	{ pairTemplate( "water", "sand" ),"beach" },
	{ pairTemplate( "ground", "air" ),"dust" },
	{ pairTemplate( "lava", "volcano" ),"ash" },
	{ pairTemplate("dust", "fire" ),"powder" },
	{ pairTemplate( "steam", "ground" ),"geyser" },
	{ pairTemplate( "sand", "sand" ),"desert" },
	{ pairTemplate( "water", "metal" ),"rust" },
	{ pairTemplate( "water", "dust" ),"mud" },
	{ pairTemplate( "fire", "air" ),"energy" },
	{ pairTemplate( "fire", "turf" ),"smoke" },
	{ pairTemplate( "energy", "air" ),"tempest" },
	{ pairTemplate( "sand", "swamp" ),"clay" },
	{ pairTemplate( "wind", "metal" ),"sound" },
	{ pairTemplate( "water", "tempest" ),"typhoon" },
	{ pairTemplate( "fire", "clay" ),"brick" },
	{ pairTemplate( "fire", "sand" ),"glass" }

};

#endif