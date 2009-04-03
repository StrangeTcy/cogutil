/*
 * opencog/embodiment/PetComboVocabulary/pet_perception.h
 *
 * Copyright (C) 2007-2008 Nil Geisweiller
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#ifndef _PET_PERCEPTION_H
#define _PET_PERCEPTION_H

#include "util/numeric.h"

#include "comboreduct/combo/perception.h"
#include "pet_operator.h"

namespace combo
{

namespace id {
enum pet_perception_enum {
    exists,
    exists_edible,
    exists_movable,
    exists_pickupable,
    exists_drinkable,
    exists_avatar,
    exists_pet,
    exists_small,
    exists_moving,
    exists_noisy,
    exists_poo_place,
    exists_pee_place,

    is_edible,
    is_movable,
    is_pickupable,
    is_drinkable,
    is_avatar,
    is_object,
    is_pet,
    is_small,
    is_moving,
    is_noisy,
    is_poo_place,
    is_pee_place,
    is_null,

    is_owner,
    is_moving_toward,

    is_holding_something,

    near,
    next,
    above,
    below,
    inside,

    has_said,
    has_novelty,
    has_learned_tricks,
    has_requested_schema,

    // traits
    get_aggressiveness,
    get_curiosity,
    get_playfulness,
    get_friendliness,
    get_fearfulness,
    get_appreciativeness,
    get_excitability,

    // pet emotional feelings (internal)
    get_happiness,
    get_fear,
    get_pride,
    get_love,
    get_hate,
    get_anger,
    get_gratitude,
    get_excitement,

    is_learning,
    is_agent_state,
    // pet feelings (signals from proxy). Boolean functions are implemented
    // as combo scripts
    get_hunger,
    get_thirst,
    get_energy,
    get_fitness,
    get_pee_urgency,
    get_poo_urgency,

    get_current_action_repetition,

    avatar_asked_to_try,

    inside_pet_fov,

    // relation between two objects
    is_there_relation,

    // how next two objects are
    is_proportional_next,

    is_last_agent_action,
    is_last_pet_schema,
    is_last_group_command,

    pet_perception_count
};
}

typedef id::pet_perception_enum pet_perception_enum;

/*********************************************************************
 *       Arrays containing perception name type and properties       *
 *                 to be edited by the developer                     *
 *********************************************************************/

namespace pet_perception_properties {

//struct for description of name and type
typedef combo::pet_operator<pet_perception_enum, id::pet_perception_count>::basic_description perception_basic_description;

//struct for decription of perception properties
struct perception_property_description {
    pet_perception_enum perception;
    bool ultrametric;
    bool transitive;
    bool irreflexive;
    bool reflexive;
    bool symmetric;
    bool identity_of_indiscernibles;
};

static const perception_basic_description pbd[] = {
    //perception             name                 type
    { id::exists,            "exists",            "->(union(definite_object indefinite_object) boolean)" },
    { id::exists_edible,     "exists_edible",     "boolean" },
    { id::exists_movable,    "exists_movable",    "boolean" },
    { id::exists_pickupable, "exists_pickupable", "boolean" },
    { id::exists_drinkable,  "exists_drinkable",  "boolean" },
    { id::exists_avatar,     "exists_avatar",     "boolean" },
    { id::exists_pet,        "exists_pet",        "boolean" },
    { id::exists_small,      "exists_small",      "boolean" },
    { id::exists_moving,     "exists_moving",     "boolean" },
    { id::exists_noisy,      "exists_noisy",      "boolean" },
    { id::exists_poo_place,  "exists_poo_place",  "boolean" },
    { id::exists_pee_place,  "exists_pee_place",  "boolean" },

    { id::is_edible,         "is_edible",         "->(union(indefinite_object wild_card) boolean)" },
    { id::is_movable,        "is_movable",        "->(union(indefinite_object wild_card) boolean)" },
    { id::is_pickupable,     "is_pickupable",     "->(union(indefinite_object wild_card) boolean)" },
    { id::is_drinkable,      "is_drinkable",      "->(union(indefinite_object wild_card) boolean)" },
    { id::is_avatar,         "is_avatar",         "->(union(indefinite_object wild_card) boolean)" },
    { id::is_object,         "is_object",         "->(union(indefinite_object wild_card) boolean)" },
    { id::is_pet,            "is_pet",            "->(union(indefinite_object wild_card) boolean)" },
    { id::is_small,          "is_small",          "->(union(indefinite_object wild_card) boolean)" },
    { id::is_moving,         "is_moving",         "->(union(definite_object indefinite_object wild_card) boolean)" },
    { id::is_noisy,          "is_noisy",          "->(union(indefinite_object wild_card) boolean)" },
    { id::is_poo_place,      "is_poo_place",      "->(union(indefinite_object wild_card) boolean)" },
    { id::is_pee_place,      "is_pee_place",      "->(union(indefinite_object wild_card) boolean)" },
    { id::is_null,           "is_null",           "->(union(definite_object indefinite_object) boolean)" },

    { id::is_owner,       "is_owner",    "->(union(definite_object indefinite_object wild_card) union(definite_object indefinite_object wild_card) boolean)" },
    { id::is_moving_toward,  "is_moving_toward",  "->(union(definite_object indefinite_object wild_card) union(definite_object indefinite_object wild_card) boolean)" },

    { id::is_holding_something,  "is_holding_something",  "->(union(definite_object indefinite_object wild_card) boolean)" },

    { id::near,              "near",              "->(union(definite_object indefinite_object wild_card) union(definite_object indefinite_object wild_card) boolean)" },
    { id::next,              "next",              "->(union(definite_object indefinite_object wild_card) union(definite_object indefinite_object wild_card) boolean)" },
    { id::above,             "above",             "->(union(definite_object indefinite_object wild_card) union(definite_object indefinite_object wild_card) boolean)" },
    { id::below,             "below",             "->(union(definite_object indefinite_object wild_card) union(definite_object indefinite_object wild_card) boolean)" },
    { id::inside,            "inside",            "->(union(definite_object indefinite_object wild_card) union(definite_object indefinite_object wild_card) boolean)" },
    { id::has_said,          "has_said",          "->(union(definite_object indefinite_object wild_card) message boolean)" },
    { id::has_novelty,       "has_novelty",       "->(union(definite_object indefinite_object) boolean)" },

    { id::has_learned_tricks,   "has_learned_tricks",   "->(union(definite_object indefinite_object) boolean)" },
    { id::has_requested_schema, "has_requested_schema", "->(union(definite_object indefinite_object) boolean)" },

    { id::get_aggressiveness,   "get_aggressiveness",   "->(union(definite_object indefinite_object) contin)"},
    { id::get_curiosity,        "get_curiosity",     "->(union(definite_object indefinite_object) contin)"},
    { id::get_playfulness,   "get_playfulness",    "->(union(definite_object indefinite_object) contin)"},
    { id::get_friendliness,   "get_friendliness",    "->(union(definite_object indefinite_object) contin)"},
    { id::get_fearfulness,    "get_fearfulness",    "->(union(definite_object indefinite_object) contin)"},
    { id::get_appreciativeness, "get_appreciativeness", "->(union(definite_object indefinite_object) contin)"},
    { id::get_excitability,   "get_excitability",   "->(union(definite_object indefinite_object) contin)"},

    { id::get_happiness,    "get_happiness",  "->(union(definite_object indefinite_object) contin)"},
    { id::get_fear,     "get_fear",   "->(union(definite_object indefinite_object) contin)"},
    { id::get_pride,     "get_pride",   "->(union(definite_object indefinite_object) contin)"},
    { id::get_love,     "get_love",   "->(union(definite_object indefinite_object) contin)"},
    { id::get_hate,     "get_hate",      "->(union(definite_object indefinite_object) contin)"},
    { id::get_anger,     "get_anger",   "->(union(definite_object indefinite_object) contin)"},
    { id::get_gratitude,    "get_gratitude",  "->(union(definite_object indefinite_object) contin)"},
    { id::get_excitement,    "get_excitement", "->(union(definite_object indefinite_object) contin)"},

    { id::is_learning,       "is_learning",       "->(union(definite_object indefinite_object) boolean)" },

    { id::get_hunger,     "get_hunger",  "->(union(definite_object indefinite_object) contin)"},
    { id::get_thirst,     "get_thirst",  "->(union(definite_object indefinite_object) contin)"},
    { id::get_energy,     "get_energy",  "->(union(definite_object indefinite_object) contin)"},
    { id::get_fitness,       "get_fitness",  "->(union(definite_object indefinite_object) contin)"},
    { id::get_pee_urgency,   "get_pee_urgency", "->(union(definite_object indefinite_object) contin)"},
    { id::get_poo_urgency,   "get_poo_urgency", "->(union(definite_object indefinite_object) contin)"},

    { id::get_current_action_repetition,   "get_current_action_repetition", "contin"},
    { id::is_agent_state,   "is_agent_state", "->(contin boolean)"},

    { id::avatar_asked_to_try,  "avatar_asked_to_try", "->(union(definite_object indefinite_object wild_card) boolean)" },
    { id::inside_pet_fov,    "inside_pet_fov",    "->(definite_object union(definite_object indefinite_object wild_card) boolean)" },

    { id::is_there_relation, "is_there_relation", "->(definite_object union(definite_object indefinite_object wild_card) union(definite_object indefinite_object wild_card) boolean)" },
    { id::is_proportional_next, "is_proportional_next", "->(union(definite_object indefinite_object wild_card) union(definite_object indefinite_object wild_card) contin contin boolean)" },

    { id::is_last_agent_action, "is_last_agent_action", "->(union(definite_object indefinite_object wild_card) action_definite_object arg_list(union(definite_object indefinite_object)) boolean)" },
    { id::is_last_pet_schema,   "is_last_pet_schema",   "->(action_definite_object action_result arg_list(union(definite_object indefinite_object wild_card)) boolean)" },
    { id::is_last_group_command, "is_last_group_command", "->(definite_object definite_object arg_list(union(definite_object contin)) boolean)" }
};

static const perception_property_description ppd[] = {
    //perception             ultrametric transitive irreflexive reflexive symmetric identity_of_indiscernibles
    { id::exists,            false,      false,     false,      false,    false,    false },
    { id::exists_edible,     false,      false,     false,      false,    false,    false },
    { id::exists_movable,    false,      false,     false,      false,    false,    false },
    { id::exists_pickupable, false,      false,     false,      false,    false,    false },
    { id::exists_drinkable,  false,      false,     false,      false,    false,    false },
    { id::exists_avatar,     false,      false,     false,      false,    false,    false },
    { id::exists_pet,        false,      false,     false,      false,    false,    false },
    { id::exists_small,      false,      false,     false,      false,    false,    false },
    { id::exists_moving,     false,      false,     false,      false,    false,    false },
    { id::exists_noisy,      false,      false,     false,      false,    false,    false },
    { id::exists_poo_place,  false,      false,     false,      false,    false,    false },
    { id::exists_pee_place,  false,      false,     false,      false,    false,    false },

    { id::is_edible,         false,      false,     false,      false,    false,    false },
    { id::is_movable,        false,      false,     false,      false,    false,    false },
    { id::is_pickupable,     false,      false,     false,      false,    false,    false },
    { id::is_drinkable,      false,      false,     false,      false,    false,    false },
    { id::is_avatar,         false,      false,     false,      false,    false,    false },
    { id::is_object,         false,      false,     false,      false,    false,    false },
    { id::is_pet,            false,      false,     false,      false,    false,    false },
    { id::is_small,          false,      false,     false,      false,    false,    false },
    { id::is_moving,         false,      false,     false,      false,    false,    false },
    { id::is_noisy,          false,      false,     false,      false,    false,    false },
    { id::is_poo_place,      false,      false,     false,      false,    false,    false },
    { id::is_pee_place,      false,      false,     false,      false,    false,    false },
    { id::is_null,           false,      false,     false,      false,    false,    false },

    { id::is_owner,          false,      false,     false,      false,    false,    false },
    { id::is_moving_toward,  false,      false,     false,      false,    false,    false },

    { id::is_holding_something,
      false,      false,     false,      false,    false,    false },

    { id::near,              false,      false,     false,      true,     true,     false },
    { id::next,              false,      false,     false,      true,     true,     false },
    { id::above,             false,      true,      true,       false,    false,    false },
    { id::below,             false,      true,      true,       false,    false,    false },
    { id::inside,            false,      true,      true,       false,    false,    false },
    { id::has_said,          false,      false,     false,      false,    false,    false },
    { id::has_novelty,       false,      false,     false,      false,    false,    false },
    { id::has_learned_tricks,   false,   false,     false,      false,    false,    false },
    { id::has_requested_schema, false,   false,     false,      false,    false,    false },

    { id::get_aggressiveness,   false,   false,     false,      false,    false,    false },
    { id::get_curiosity,        false,   false,     false,      false,    false,    false },
    { id::get_playfulness,      false,   false,     false,      false,    false,    false },
    { id::get_friendliness,     false,   false,     false,      false,    false,    false },
    { id::get_fearfulness,      false,   false,     false,      false,    false,    false },
    { id::get_appreciativeness, false,   false,     false,      false,    false,    false },
    { id::get_excitability,     false,   false,     false,      false,    false,    false },

    { id::get_happiness,    false,      false,     false,      false,    false,    false },
    { id::get_fear,     false,      false,     false,      false,    false,    false },
    { id::get_pride,     false,      false,     false,      false,    false,    false },
    { id::get_love,     false,      false,     false,      false,    false,    false },
    { id::get_hate,     false,      false,     false,      false,    false,    false },
    { id::get_anger,     false,      false,     false,      false,    false,    false },
    { id::get_gratitude,    false,      false,     false,      false,    false,    false },
    { id::get_excitement,    false,      false,     false,      false,    false,    false },

    { id::is_learning,    false,      false,     false,      false,    false,    false },

    { id::get_hunger,     false,      false,     false,      false,    false,    false },
    { id::get_thirst,        false,      false,     false,      false,    false,    false },
    { id::get_energy,        false,      false,     false,      false,    false,    false },
    { id::get_fitness,       false,      false,     false,      false,    false,    false },
    { id::get_pee_urgency,   false,      false,     false,      false,    false,    false },
    { id::get_poo_urgency,   false,      false,     false,      false,    false,    false },

    { id::get_current_action_repetition, false, false, false,   false,    false,    false },
    { id::is_agent_state, false, false, false,   false,    false,    false },

    { id::avatar_asked_to_try, false,    false,     false,      false,    false,    false },
    { id::inside_pet_fov,    false,      false,     false,      false,    false,    false },

    { id::is_there_relation, false,      false,     false,      false,    false,    false },
    { id::is_proportional_next, false,   false,     false,      true,     true,     false },
    { id::is_last_agent_action, false,   false,     false,      false,    false,    false },
    { id::is_last_pet_schema,   false,   false,     false,      false,    false,    false },
    { id::is_last_group_command,   false,   false,     false,      false,    false,    false }
};


}//~namespace pet_perception_properties

//pet_perception both derive from perception_base and pet_operator
class pet_perception : public pet_operator<pet_perception_enum, id::pet_perception_count>, public perception_base
{

private:

    //standard properties
    bool _ultrametric;
    bool _transitive;
    bool _irreflexive;
    bool _reflexive;
    bool _symmetric;
    bool _identity_of_indiscernibles;

    //private methods

    //ctor
    pet_perception();

    const basic_description * get_basic_description_array() const;
    unsigned int get_basic_description_array_count() const;

    static const pet_perception* init_perceptions();
    void set_perception(pet_perception_enum);

public:
    //name
    const std::string& get_name() const;

    //type_tree
    const type_tree& get_type_tree() const;

    //helper methods for fast access type properties
    //number of arguments that takes the operator
    arity_t arity() const;
    //return the type node of the operator
    type_tree get_output_type_tree() const;

    //return the type tree of the input argument of index i
    //if the operator has arg_list(T) as last input argument
    //then it returns always T past that index
    const type_tree& get_input_type_tree(arity_t i) const;

    //return a pointer of the static pet_perception corresponding
    //to a given name string
    //if no such perception exists then return NULL pointer
    static perception instance(const std::string& name);

    //return a pointer of the static pet_perception_action corresponding
    //to a given pet_perception_enum
    static perception instance(pet_perception_enum);

    //action property methods
    bool is_ultrametric() const;
    bool is_transitive() const;
    bool is_irreflexive() const;
    bool is_reflexive() const;
    bool is_symmetric() const;
    bool is_identity_of_indiscernibles() const;

};
}//~namespace combo

#endif
